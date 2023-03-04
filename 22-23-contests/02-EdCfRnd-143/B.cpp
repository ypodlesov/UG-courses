#include <bits/stdc++.h>
 
using namespace std;
 
 
void 
solve() 
{
    int n, k;
    cin >> n >> k;
    bool flag = false;
    vector<pair<int,int>> segs(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        segs[i] = {l, r};
    }
    for (int i = 0; i < n; ++i) {
        if (segs[i].first == segs[i].second && segs[i].first == k) flag = true;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (segs[i].first == segs[j].second && segs[i].first == k) flag = true;
            if (flag) break;
        }
        if (flag) break;
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
} 
int
main()
{
    
    int t;
    cin >> t;
    while (t--) solve();
 
    return 0;
}