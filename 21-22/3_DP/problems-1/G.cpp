#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;

int main() {

    cin >> n >> m;
    vector<int> w(n+1), c(n+1);
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j >= w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + c[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;

    return 0;
}
