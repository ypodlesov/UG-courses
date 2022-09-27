#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

int n;
vector<int> a, t;

int sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r+1)) - 1) res += t[r];
    return res;
}

void inc(int i, int d) {
    for (; i < n; i = (i | (i+1))) t[i] += d;
}

int sum(int l, int r) {
    if (l == 0) return sum(r);
    return sum(r) - sum(l-1);
}

int main() {

    cin >> n;
    a.assign(n, 0);
    t.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        inc(i, a[i]);
    }
    for (int i = 0; i < n; ++i) cout << t[i] << ' ';
    cout << endl;

    while (true) {
        string s;
        cin >> s;
        if (s == "sum") {
            int l, r;
            cin >> l >> r;
            cout << sum(l, r) << endl;
        } else if (s == "update") {
            int i, val;
            cin >> i >> val;
            inc(i, val - a[i]);
        } else if (s == "finish") {
            cout << "bye\n";
            break;
        }
    }


    return 0;
}
