#include <bits/stdc++.h>
 
using namespace std;
 
void 
solve()
{
    int n;
    cin >> n;
    vector<long long> a(n + 1), b(n + 1), res(n + 1), pref(n + 1), stopped(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        pref[i] = pref[i-1] + b[i];
        res[i] = b[i] * i;
    }
    for (int i = 1; i <= n; ++i) {
        int j = distance(pref.begin(), lower_bound(pref.begin(), pref.end(), a[i] + pref[i-1]));
        if (j > n) continue;
        long long left = a[i] - (pref[j-1] - pref[i-1]);
        res[j] = res[j] - b[j] + left;        
        if (j < n) ++stopped[j+1];
    }
    for (int i = 1; i <= n; ++i) {
        stopped[i] += stopped[i-1];
        res[i] -= b[i] * stopped[i];
        cout << res[i] << ' ';
    }
    cout << endl;
}

// a[i] <= pref[j] - pref[i-1]
// a[i] + pref[i-1] <= pref[j]
 
int
main()
{
    int t;
    cin >> t;
    while (t--) solve();
 
    return 0;
}