#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define f first
#define s second
#define PB push_back

vector<vector<int>> g(105), comps(0);
vector<int> cut_points;
vector<bool> used(105);
vector<int> up(105), tin(105), buffer;
int timer;

void dfs(int v, int p = -1) {
    used[v] = true;
    int cnt = 0;
    up[v] = tin[v] = timer++;
    for (auto u : g[v]) {
        if (u == p) continue;
        if (!used[u]) {
            ++cnt;
            dfs(u, v);
            up[v] = min(up[v], up[u]);
            if (p != -1 && up[u] >= tin[v]) cut_points.PB(v);
        } else up[v] = min(up[v], tin[u]);
    }
    if (p == -1 && cnt > 1) cut_points.PB(v);
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
    cout << "Cut points:\n";
    for (auto i : cut_points) cout << i << ' ';
    cout << endl;

// 10 12
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

    return 0;
}
