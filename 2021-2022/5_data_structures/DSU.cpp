#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

int n, m;
vector<int> parent, rang;

void init_parents(int n) {
    parent.assign(n+1, 0);
    for (int i = 0; i <= n; ++i) parent[i] = i;
}

int fnd(int x) {
    if (x == parent[x]) return x;
	return parent[x] = fnd(parent[x]);
}

void un(int x, int y) {
    x = fnd(x);
    y = fnd(y);
    if (x == y) return;
    if (rang[x] > rang[y]) swap(x, y);
    if (rang[x] == rang[y]) ++rang[y];
    parent[x] = y;
}

int main() {

    cin >> n;
    rang.assign(n+1, 0);
    init_parents(n);
    char ch = '8';
    while (true) {
        cin >> ch;
        if (ch == 'f') {
            int x;
            cin >> x;
            cout << fnd(x) << endl;
        } else if (ch == 'u') {
            int x, y;
            cin >> x >> y;
            un(x, y);
        } else if (ch == '0') {
            cout << "Thank You!\n";
            break;
        }
    }

    return 0;
}
