#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

int n, l;
vector<int> a, loga;
vector<vector<int>> m;

int query(int i, int j) {
    int k = loga[j+1-i];
    return max(m[k][i], m[k][j+1-(1<<k)]);
}

int main() {

    cin >> n;
    while ((1 << l) <= n) ++l;
    --l;
    a.assign(n, 0), loga.assign(n+1, 0);
    loga[1] = 0;
    for (int i = 2; i <= n; ++i) loga[i] = loga[i/2] + 1;
    for (int i = 0; i < n; ++i) cin >> a[i];
    m.assign(l+1, vector<int>(n));
    for (int i = 0; i < n; ++i) m[0][i] = a[i];
    for (int k = 1; k <= l; ++k)
        for (int i = 0; i + (1 << k) <= n; ++i) m[k][i] = max(m[k-1][i], m[k-1][i+(1<<(k-1))]);
    while (true) {
        string ch;
        cin >> ch;
        if (ch == "max") {
            int left, right;
            cin >> left >> right;
            cout << query(left, right) << endl;
        } else if (ch == "finish") break;
    }

    return 0;
}
