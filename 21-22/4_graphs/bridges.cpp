#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define f first
#define s second
#define PB push_back


const int N = 105;
vector<vector<int>> g(N), comps, cond(N);
vector<pair<int,int>> bridges;
vector<bool> used(105);
vector<int> up(N), tin(N), buffer, type(N);
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
    cout << "Input number of vertexes: ";
    cin >> n;
    cout << "Input number of edges: ";
    cin >> m;
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
    cout << "Bridges:\n";
    for (auto i : bridges)
        if (i.f != -1) cout << i.f << ' ' << i.s << endl;
    cout << "Components:\n";
    for (int i = 0; i < comps.size(); ++i) {
        cout << i + 1 << ": ";
        for (auto j : comps[i]) cout << j << ' ';
        cout << endl;
    }

    cout << "Condence:\n";
    for (auto i : bridges) cond[type[i.f]].PB(type[i.s]), cond[type[i.s]].PB(type[i.f]);

    // for (int i = 1; i <= n; ++i) cout << i << ": " << type[i] << endl;
    for (int i = 1; i <= comps.size(); ++i) {
        cout << i << ": ";
        for (auto j : cond[i]) cout << j << ' ';
        cout << endl;
    }

// 10 13
// 1 2
// 1 6
// 2 3
// 3 4
// 4 5
// 6 7
// 7 8
// 8 9
// 7 9
// 9 10
// 8 10
// 3 5
// 2 6

    return 0;
}
