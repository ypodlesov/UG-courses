#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

int n, m, timer, logn;
vector<int> d, tin, tout;
vector<vector<int>> g, jmp;

void count_logn() { while ((1 << logn) <= n) ++logn; }

void dfs(int v, int from = 0) {
    tin[v] = ++timer;
    d[v] = d[from] + 1;
    jmp[v][0] = from;
    for (int i = 1; i <= logn; ++i) jmp[v][i] = jmp[jmp[v][i-1]][i-1];
    for (auto u : g[v])
        if (u != from) dfs(u, v);
    tout[v] = ++timer;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int k = logn; k >= 0; --k) {
        int tmp = jmp[u][k];
        if (d[tmp] >= d[v]) u = tmp;
    }
    if (u == v) return u;
    for (int k = logn; k >= 0; --k) {
        int u_ = jmp[u][k], v_ = jmp[v][k];
        if (u_ != v_) u = u_, v = v_;
    }
    return jmp[u][0];
}

int main() {

    cin >> n;
    count_logn();
    d.assign(n+1, 0), tin.assign(n+1, 0), tout.assign(n+1, 0);
    g.assign(n+1, vector<int>()), jmp.assign(n+1, vector<int>(logn+1));
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].PB(y), g[y].PB(x);
    }
    dfs(1);
    cout << lca(10, 11) << endl;

// 11
// 1 2
// 1 3
// 2 4
// 2 5
// 5 11
// 5 7
// 5 6
// 7 8
// 7 9
// 6 10


    return 0;
}
