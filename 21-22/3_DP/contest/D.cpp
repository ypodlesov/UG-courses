#include <bits/stdc++.h>
using namespace std;

#define ll long long

void func(vector<vector<ll>> &dp, int i, int j, int from_i, int from_j, int n, int m) {
    if (i > 0 && i <= n && j > 0 && j <= m) {
        dp[i][j] += dp[from_i][from_j];
        func(dp, i+1, j+2, i, j, n, m);
        func(dp, i-1, j+2, i, j, n, m);
        func(dp, i+2, j+1, i, j, n, m);
        func(dp, i+2, j-1, i, j, n, m);
    }
}

struct point {
    int a, b, from_a, from_b;
    point(int c, int d, int x, int y) {
        a = c;
        b = d;
        from_a = x;
        from_b = y;
    }
};

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+5, vector<int>(m+1, 0));
    vector<vector<int>> dp(n+5, vector<int>(m+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] += a[i][j];
        }
    }
    cout << dp[n][m];
    
    return 0;
}
