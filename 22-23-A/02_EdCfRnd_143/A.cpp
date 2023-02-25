#include <bits/stdc++.h>
 
using namespace std;
 
void 
solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    string r = s + t;
    if (r.find("RRR") < r.size() || r.find("BBB") < r.size()) {
        cout << "NO\n";
        return;
    }
    int cnt = 0;
    for (int i = 1; i < r.size(); ++i) {
        if (r[i] == r[i-1]) ++cnt;
    }
    if (cnt > 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
 
int
main()
{
    int t;
    cin >> t;
    while (t--) solve();
 
    return 0;
}