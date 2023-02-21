#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define f first
#define s second
#define PB push_back

struct edge {
    int v, u, cost;
};

int n, m, mst_sum;
vector<int> id(100);
vector<edge> edges, mst;
vector<vector<pair<int,int>>> g(100);

bool cmp(edge a, edge b) {
    return ((a.cost < b.cost) || (a.cost == b.cost && a.v < b.v) || (a.cost == b.cost && a.v == b.v && a.u < b.u));
}

int main() {

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int v, u, c;
        cin >> v >> u >> c;
        g[v].PB({c,u}), g[u].PB({c,v}), edges.PB({v, u, c});
    }
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 1; i <= n; ++i) id[i] = i;
    for (int i = 0; i < m; ++i) {
        int a = edges[i].v, b = edges[i].u, c = edges[i].cost;
        if (id[a] == id[b]) continue;
        mst_sum += c;
        mst.PB({a, b, c});
        int old_id = id[b], new_id = id[a];
        for (int j = 1; j <= n; ++j)
            if (id[j] == old_id) id[j] = new_id;
    }
    cout << mst_sum << endl;
    for (auto i : mst) cout << i.v << ' ' << i.u << ' ' << i.cost << endl;

    return 0;
}

// 6 8
// 1 3 1
// 1 6 2
// 1 2 8
// 2 4 10
// 2 5 10
// 3 4 2
// 4 5 3
// 6 2 2
