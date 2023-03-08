#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vector<int> a(26), b(26);
    
    // check letters
    for (int i = 0; i < s.size(); ++i) {
        ++a[s[i] - 'a'];
        ++b[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (a[i] != b[i]) {
            cout << "no\n";
            return;
        }
    }

    if (n >= 2 * k) {
        cout << "yes\n";   
    } else {
        if (n > k) {
            for (int i = 0; i < 2 * k - n; ++i) {
                if (s[i + n - k] != t[i + n - k]) {
                    cout << "no\n";
                    return;
                }
            }
            cout << "yes\n";
        } else if (n <= k && !strcmp(s.c_str(), t.c_str())) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}