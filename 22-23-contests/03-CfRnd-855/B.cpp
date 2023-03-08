#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<pair<int,int>> a(26);
    for (auto i : s) {
        if (isupper(i)) {
            ++a[i - 'A'].ff;
        } else {
            ++a[i - 'a'].ss;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans += min(a[i].ff, a[i].ss);
        a[i].ff = abs(a[i].ff - a[i].ss);
        a[i].ss = 0;
        if (k >= a[i].ff / 2) {
            k -= a[i].ff / 2;
            ans += a[i].ff / 2;
        } else {
            ans += k;
            k = 0;
        }
    }
    cout << ans << endl;
}

int main() {

    int t;
    cin >> t;
    while (t--) solve(); 

    return 0;
}