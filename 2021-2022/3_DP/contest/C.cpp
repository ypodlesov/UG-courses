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
    vector<vector<int>> dp(n+5, vector<int>(m+5, 0));
    dp[2][2] = 1;
    for (int k = 1; k <= max(n, m); ++k)
        for (int i = 2; i <= n+1; ++i)
            for (int j = 2; j <= m+1; ++j)
                if (!(i == 2 && j == 2)) dp[i][j] = dp[i-2][j-1] + dp[i-2][j+1] + dp[i-1][j-2] + dp[i+1][j-2];
    cout  << dp[n+1][m+1];

    return 0;
}
