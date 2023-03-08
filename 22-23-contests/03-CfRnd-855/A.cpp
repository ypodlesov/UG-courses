#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int mode = -1;
    for (auto i : s) {
        char c = tolower(i);
        int a{};
        if (c == 'm') {
            a = 0;
        } else if (c == 'e') {
            a = 1;
        } else if (c == 'o') {
            a = 2;
        } else if (c == 'w') {
            a = 3;
        } else {
            cout << "no\n";
            return;
        }
        if (a < mode) {
            cout << "no\n";
            return;
        } else if (a > mode) {
            if (a - mode > 1) {
                cout << "no\n";
                return;
            } else {
                ++mode;
            }
        }
    }
    if (mode == 3) cout << "yes\n";
    else cout << "no\n";
}

int main() {

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}