#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

int n, m;
vector<vector<int>> dp(105, vector<int>(10005, INF));
int cnt[105][10005];
int w[105];


int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];
    dp[1][w[1]] = 1;
    for (int i = 1; i <= n; ++i) dp[i][0] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (w[i] <= j) dp[i][j] = min(dp[i-1][j], dp[i-1][j-w[i]] + 1);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][m] % INF << endl;
    return 0;
}
