#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define PB push_back
const int N = 400;

vector<int> g[N], ans;
int tin[N], tup[N], timer = 0, dp[N][N], u, v, q;
bool used[N];

void dfs1(int v, int p = -1) {
    used[v] = true;
    tin[v] = tup[v] = timer++;
    for (auto u : g[v]) {
        if (u == p) continue;
        if (used[u]) tup[v] = min(tup[v], tin[u]);
        else {
            dfs1(u, v);
            tup[v] = min(tup[v], tup[u]);
        }
    }
}

void dfs2(int v, int start) {
    used[v] = true;
    for (auto u : g[v]) {
        if (!used[u]) {
            if (tup[u] >= tin[v]) dp[start][u] = dp[start][v] + 1;
            else dp[start][u] = dp[start][v];
            dfs2(u, start);
        }
    }
}


int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u-1].PB(v-1), g[v-1].PB(u-1);
    }
    for (int i = 0; i < n; i++) {
        fill(used, used + n, false);
        dfs1(i, -1);
        fill(used, used + n, false);
        dfs2(i, i);
    }
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        ans.push_back(max(0, dp[a-1][b-1] - 1));
    }
    for (int i : ans) cout << i << endl;

    return 0;
}
