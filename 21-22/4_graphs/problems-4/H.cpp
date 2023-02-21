#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

int n, m, l, timer, root;
vector<bool> used;
vector<int> d, tin, tout;
vector<vector<int>> g, jmp;

void dfs(int v, int depth = 0) {
    used[v] = true;
    tin[v] = ++timer;
    d[v] = depth++;
    for (auto u : g[v])
        if (!used[u]) jmp[u][0] = v, dfs(u, depth);
    tout[v] = ++timer;
}

bool cmp(int v, int u) { return d[v] < d[u]; }

bool is_ancestor(int u, int v) {
    if (tin[u] <= tin[v] && tout[u] >= tout[v]) return true;
    return false;
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int k = l; k >= 0; --k)
        if (jmp[u][k] && !is_ancestor(jmp[u][k], v)) u = jmp[u][k];
    return jmp[u][0];
}


int main() {

    while (true) {
        l = 0, timer = 0, root = 1;
        cin >> n;
        if (n == 0) return 0;
        while ((1 << l) <= n) ++l;
        d.assign(n+1, 0), tin.assign(n+1, 0), tout.assign(n+1, 0), used.assign(n+1, false);
        g.assign(n+1, vector<int>(0)), jmp.assign(n+1, vector<int>(l+5, 0));
        for (int i = 1; i < n; ++i) {
            int v, u;
            cin >> v >> u;
            g[v].PB(u), g[u].PB(v);
        }
        dfs(1);
        for (int k = 1; k <= l; ++k)
            for (int u = 1; u <= n; ++u) jmp[u][k] = jmp[jmp[u][k-1]][k-1];
        cin >> m;
        while (m--) {
            char ch;
            cin >> ch;
            if (ch == '!') cin >> root;
            else {
                int v, u;
                cin >> v >> u;
                int tmp1 = lca(v, u), tmp2 = lca(v, root), tmp3 = lca(u, root);
                cout << max(tmp1, max(tmp2, tmp3, cmp), cmp) << endl;
            }
        }
    }

    return 0;
}
