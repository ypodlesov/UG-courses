#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000


int n, s, w;

int main() {

    cin >> n;
    vector<int> c(n+5);
    for (int i = 1; i <= n; ++i) cin >> c[i];
    cin >> s;
    vector<int> dp(s+5, INF);
    dp[0] = 0;
    for (int j = 1; j <= s; ++j)
        for (int i = 1; i <= n; ++i)
            if (c[i] <= j && dp[j-c[i]] + 1 < dp[j]) dp[j] = dp[j-c[i]] + 1;
    if (dp[s] == INF) {
        cout << "No solution\n";
        return 0;
    }
    while (s > 0) {
        for (int i = 1; i <= n; ++i) {
            if (s >= c[i] && dp[s] == dp[s - c[i]] + 1) {
                cout << c[i] << ' ';
                s -= c[i];
            }
        }
    }
    cout << endl;

    return 0;
}
