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

    if (n > 5) {
        cout << "yes\n";   
    } else if (n == 5 && s[2] == t[2]) {
        cout << "yes\n";   
    } else if (n == 4 && s[1] == t[1] && s[2] == t[2]) {
        cout << "yes\n";   
    } else if (n <= 3 && !strcmp(s.c_str(), t.c_str())) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}