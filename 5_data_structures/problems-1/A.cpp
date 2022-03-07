#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

int n, m, last;
vector<int> parent, rang;

void init_parents(int n) {
    parent.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) parent[i] = i;
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

    cin >> n >> m;
    rang.assign(n+1, 0);
    init_parents(n);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        if (fnd(x) != fnd(y)) {
            last = i;
            un(x, y);
        }
    }
    cout << last << endl;

    return 0;
}
