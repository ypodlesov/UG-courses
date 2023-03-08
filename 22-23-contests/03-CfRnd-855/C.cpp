#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;
    vector<int> s(n);
    priority_queue<int> tmp{};
    long long ans{};
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i]) {
            tmp.push(s[i]);
        } else {
            if (tmp.empty()) continue;
            ans += tmp.top();
            tmp.pop();
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