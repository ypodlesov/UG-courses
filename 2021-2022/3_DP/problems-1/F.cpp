#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back

int a, b, c, n;
vector<int> d(1005);

int main() {

    cin >> a >> b >> c >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    if (a > c) {
        cout << a << endl << 0 << endl;
        return 0;
    }
    vector<vector<int>> dp(n + 5, vector<int>(b + 5));
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (j >= d[i]) dp[i][j] |= dp[i-1][j-d[i]];
            dp[i][j] |= dp[i-1][j];
        }
    }
    for (int i = c - a + 1; i < b; ++i) {
        if (dp[n][i]) {
            cout << a + i << endl;
            int w = i;
            vector<int> items;
            while (n) {
                if (w >= d[n] && dp[n][w-d[n]]) {
                    items.PB(n);
                    w -= d[n];
                }
                --n;
            }
            sort(items.begin(), items.end());
            cout << items.size() << ' ';
            for (auto it : items) cout << it << ' ';
            cout << endl;
            return 0;
        }
    }
    cout << a + b << endl << -1 << endl;

    return 0;
}
