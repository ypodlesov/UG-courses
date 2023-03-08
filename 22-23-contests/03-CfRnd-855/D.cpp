#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans{};
    for (int i = 0; i < s.size() - 1; ++i) {
        ++ans;
        int j = i + 2;
        while (j + 1 < s.size() && s[i] == s[j] && s[i+1] == s[j+1]) j += 2;
        i = j - 2;
        if (j < s.size() && s[i] == s[j]) i = j - 1;
    }
    cout << ans << endl;

}

int main() {

    int t;
    cin >> t;
    while (t--) solve();    

    return 0;
}