#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(40, 0);
    int res = s.size();
    for (int i = s.size() - 1; i >= 0; --i) {
        if (cnt[s[i] - 'a'] == 0) {
            res = i;
            ++cnt[s[i] - 'a'];
        }  
    }
    for (int i = res; i < s.size(); ++i) {
        cout << s[i];
    }
    cout << endl;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
