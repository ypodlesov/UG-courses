#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

int n, m, s, t, ans;
vector<vector<int>> z(21, vector<int>(21)), c(105, vector<int>(105)), f(105, vector<int>(105));
// vector<int> r(21), c(21);
vector<bool> used(105);

int dfs(int v, int delta) {
    if (v == t) return delta;
    used[v] = true;
    for (int u = 1; u <= n+m+1; ++u) {
        if (f[v][u] >= c[v][u] || used[u]) continue;
        int tmp = dfs(u, min(delta, c[v][u] - f[v][u]));
        if (tmp > 0) {
            f[v][u] += tmp;
            f[u][v] -= tmp;
            return tmp;
        }
    }
    return 0;
}


int main() {

    cin >> m >> n;
    t = m + n + 1;
    // for (int i = 1; i <= m; ++i) cin >> r[i];
    // for (int j = 1; j <= n; ++j) cin >> c[j];
    for (int i = 1 + n; i <= m + n; ++i) cin >> c[i][t];
    for (int j = 1; j <= n; ++j) cin >> c[s][j];
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> z[i][j];
            if (z[i][j] >= 0) c[s][j] -= z[i][j], c[i+n][t] -= z[i][j], ans += z[i][j];
            else c[j][i+n] = INF;
        }
    }

    for (int i = 0; i <= n+m+1; ++i) {
        for (int j = 0; j <= n+m+1; ++j) {
            if (c[i][j] < 0) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    // cout << "c:\n";
    // for (int i = 0; i <= n+m+1; ++i) {
    //     for (int j = 1; j <= n+m+1; ++j) cout << c[i][j] << ' ';
    //     cout << endl;
    // }
    while (true) {
        used.assign(n+m+5, false);
        int delta = dfs(s, INF);
        if (delta > 0) ans += delta;
        else break;
    }
    // cout << "f:\n";
    // for (int i = 0; i <= n+m+1; ++i) {
    //     for (int j = 1; j <= n+m+1; ++j) cout << f[i][j] << ' ';
    //     cout << endl;
    // }
    for (int i = 1 + n; i <= n+m; ++i)
        for (int j = 1; j <= n; ++j)
            if (z[i-n][j] < 0) z[i-n][j] = f[j][i];
    // cout << ans << endl;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << z[i][j] << ' ';
        cout << endl;
    }


    return 0;
}
