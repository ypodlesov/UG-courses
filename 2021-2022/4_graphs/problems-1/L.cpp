#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back

vector<vector<char>> t(105, vector<char>(105, '-'));
vector<vector<int>> g(10005);
vector<bool> used(10005);
int ans;

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]]) dfs(g[v][i]);
}

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> t[i][j];
            if (t[i][j] == '#') {
                if (t[i][j] == t[i-1][j]) g[(i-1)*m + j].PB((i-2)*m + j), g[(i-2)*m + j].PB((i-1)*m + j);
                if (t[i][j] == t[i][j-1]) g[(i-1)*m + j].PB((i-1)*m + j-1), g[(i-1)*m + j-1].PB((i-1)*m + j);
            } else used[(i-1)*m + j] = true;
        }
    }
    for (int i = 1; i <= n * m; ++i)
        if (!used[i]) dfs(i), ++ans;
    cout << ans << endl;

    return 0;
}
