#include <bits/stdc++.h>

using namespace std;

void 
solve() 
{
    int n;
    cin >> n;
    if (n == 1 || n == 3) {
        cout << -1;
    } else if (n & 1) {
        for (int i = 1; i < n; i += 2) {
            if (n - i == 2) cout << 1 << ' ';
            cout << n - i << ' ' << n - i + 1 << ' ';
        }
    } else {
        for (int i = n; i > 0; --i) {
            cout << i << ' ';
        }
    }
    cout << endl;
}

int 
main() 
{
    int t;
    cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}
