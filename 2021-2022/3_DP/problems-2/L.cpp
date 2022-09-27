#include <bits/stdc++.h>
using namespace std;

#define ld long double
const ld INF = 1e18;

//1908

vector<vector<ld>> dp(101, vector<ld> (101, INF));
vector<pair<ld, ld>> dots(101);

ld dist(int a, int b); //длина хорды между двумя точками

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> dots[i].first >> dots[i].second;

    for (int l = 0; l < n; l++){
        for (int i = 0; i < n - l; i++){
            if ((l == 0) || (l == 1) || (l == 2)) dp[i][i + l] = 0;
            else{
                for (int k = i + 1; k < i + l; k++){
                    dp[i][i + l] = min(dp[i][i + l], dp[i][k] + dp[k][i + l] + dist(i, k) + dist(k, i + l));
                }
            }
        }
    }
    cout << setprecision(7) <<dp[0][n - 1];
    return 0;
}

ld dist(int a, int b)
{
    if (a + 1 == b) return 0;
    ld x = dots[a].first - dots[b].first;
    ld y = dots[a].second - dots[b].second;
    return sqrt(x * x + y * y);
}
