#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define mod 1000000007
#define PB push_back
#define f first
#define s second

const int N = 200005;
ll cnt = 1;
vector<vector<int>> g(N), cond(N);
vector<vector<int>> comps;
vector<pair<int,int>> bridges;
vector<bool> used(N);
vector<int> up(N), tin(N), buffer, type(N), leaves, comp_cnt(N);
int timer;

void dfs(int v, int p = -1) {
    used[v] = true;
    up[v] = tin[v] = timer++;
    buffer.PB(v);
    for (auto u : g[v]) {
        if (u == p) continue;
        if (!used[u]) {
            dfs(u, v);
            up[v] = min(up[v], up[u]);
        } else up[v] = min(up[v], tin[u]);
    }
    if (up[v] == tin[v]) {
        if (p != -1) bridges.PB({p, v});
        vector<int> comp;
        bool flag = true;
        while (flag) {
            if (buffer.back() == v) flag = false;
            comp.PB(buffer.back());
            buffer.pop_back();
        }
        comps.PB(comp);
        for (auto i : comps.back()) type[i] = comps.size();
    }
}

int main() {

    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        g[x].PB(y), g[y].PB(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            timer = 0;
            dfs(i);
        }
    }
    for (auto i : bridges) cond[type[i.f]].PB(type[i.s]), cond[type[i.s]].PB(type[i.f]);
    for (int i = 1; i <= n; ++i) ++comp_cnt[type[i]];
    for (int i = 1; i <= comps.size(); ++i)
        if (cond[i].size() == 1) leaves.PB(i);
    for (auto l : leaves) cnt = cnt * comp_cnt[l] % mod;
    if (leaves.size() == 0) cout << 1 << ' ' << comp_cnt[1] << endl;
    else cout << leaves.size() << ' ' << cnt << endl;

    return 0;
}
