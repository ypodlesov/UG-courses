#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second
#define A (a+3)/4
#define B (b+3)/4
#define gate gates[path[i]][path[i+1]]
#define re_gate gates[path[i+1]][path[i]]

int n, a, b, cnt = -1;
vector<bool> used(1005);
vector<int> deg(4005), spec_deg(4005), path;
vector<vector<set<pair<int,int>>>> gates(1005, vector<set<pair<int,int>>>(1005));
vector<multiset<int>> g(1005);
stack<int> vs;

void dfs(int v) {
    used[v] = true;
    for (auto u : g[v])
        if (!used[u]) dfs(u);
}

int main() {

    cin >> n;
    for (int i = 1; i <= 2*n; ++i) {
        cin >> a >> b;
        g[A].insert(B), g[B].insert(A);
        gates[A][B].insert({a, b}), gates[B][A].insert({b, a});
        ++deg[A], ++deg[B], ++spec_deg[a], ++spec_deg[b];
    }
    for (int i = 1; i <= n; ++i)
        if (!used[i]) ++cnt, dfs(i);
    if (cnt) {
        cout << "No\n";
        return 0;
    } else cout << "Yes\n";
    vs.push(1);
    while (!vs.empty()) {
        int v = vs.top();
        if (deg[v] == 0) {
            path.PB(v);
            vs.pop();
        } else {
            int u = *g[v].begin();
            vs.push(u);
            --deg[v], --deg[u];
            g[v].erase(g[v].find(u)), g[u].erase(g[u].find(v));
        }
    }
    for (int i = 0; i < path.size() - 1; ++i) {
        pair<int,int> edge = *gate.begin();
        pair<int,int> re_edge = {edge.s, edge.f};
        cout << edge.f << ' ' << edge.s << ' ';
        gate.erase(edge);
        re_gate.erase(re_edge);
    }
    cout << endl;

    return 0;
}
