#include <bits/stdc++.h>
 
using namespace std;
 
bool 
cond(vector<int> &a, int l, int r, int m, int M) 
{
    return a[l] == m || a[l] == M || a[r] == m || a[r] == M;
}
 
void 
solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int m = 1, M = n;
    int l = 1, r = n;
    while (l < r) {
        if (!cond(a, l, r, m, M)) break;
        if (a[l] == m) ++l, ++m;
        if (a[l] == M) ++l, --M;
        if (a[r] == m) --r, ++m;
        if (a[r] == M) --r, --M;
    }
    if (l >= r) cout << -1 << endl;
    else cout << l << ' ' << r << endl;
}
 
int
main()
{
 
    int t;
    cin >> t;
    while (t--) solve();
 
    return 0;
}