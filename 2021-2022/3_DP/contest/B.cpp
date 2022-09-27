#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (i == 1) dp[i][j] = a[i][j] + dp[i][j-1];
            if (j == 1) dp[i][j] = a[i][j] + dp[i-1][j];
        }
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
            dp[i][j] += a[i][j];
        }
    }
    cout << dp[n][m];

    return 0;
}
