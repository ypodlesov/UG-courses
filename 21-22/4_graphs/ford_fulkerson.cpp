#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second
const int N = 105;

int n, m, s, t, ans;
vector<vector<int>> c(N, vector<int>(N)), f(N, vector<int>(N));
vector<bool> used;

int dfs(int v, int delta) {
    if (v == t) return delta;
    used[v] = true;
    for (int u = 1; u <= n; ++u) {
        if (f[v][u] == c[v][u] || used[u]) continue;
        int tmp = dfs(u, min(delta, c[v][u] - f[v][u]));
        if (tmp) {
            f[v][u] += tmp;
            f[u][v] -= tmp;
            return tmp;
        }
    }
    return 0;
}

int main() {

    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        cin >> c[v][u];
    }
    while (true) {
        used.assign(n+1, false);
        int delta = dfs(s, INF);
        if (!delta) break;
        ans += delta;
    }
    cout << ans << endl;

// 6 10 1 6
// 1 2 16
// 1 3 13
// 2 3 10
// 2 4 12
// 3 5 14
// 3 2 4
// 4 3 9
// 4 6 20
// 5 4 7
// 5 6 4

    return 0;
}
