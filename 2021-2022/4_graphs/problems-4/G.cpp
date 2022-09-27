#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

ll n, m, l, x, y, z, timer, ans, res, a1, a2;
vector<ll> d, tin, tout;
vector<vector<ll>> g, jmp;

void dfs(int v, int from = 0) {
    tin[v] = ++timer;
    d[v] = d[from] + 1;
    jmp[v][0] = from;
    for (int i = 1; i <= l; ++i) jmp[v][i] = jmp[jmp[v][i-1]][i-1];
    for (auto u : g[v])
        if (u != from) dfs(u, v);
    tout[v] = ++timer;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int k = l; k >= 0; --k) {
        int tmp = jmp[u][k];
        if (d[tmp] >= d[v]) u = tmp;
    }
    if (u == v) return u;
    for (int k = l; k >= 0; --k) {
        int u_ = jmp[u][k], v_ = jmp[v][k];
        if (u_ != v_) u = u_, v = v_;
    }
    return jmp[u][0];
}


int main() {

    cin >> n >> m;
    while ((1 << l) <= n) ++l;
    d.assign(n+1, 0), tin.assign(n+1, 0), tout.assign(n+1, 0);
    g.assign(n+1, vector<ll>(0)), jmp.assign(n+1, vector<ll>(l+5, 0));
    for (int i = 1; i < n; ++i) {
        int v;
        cin >> v;
        g[v].PB(i), g[i].PB(v);
    }
    dfs(0);
    cin >> a1 >> a2 >> x >> y >> z;
    for (int i = 0; i < m; ++i) {
        res = lca((a1 + res) % n, a2);
        ans += res;
        a1 = (x * a1 + y * a2 + z) % n;
        a2 = (x * a2 + y * a1 + z) % n;
    }
    cout << ans << endl;



    return 0;
}
