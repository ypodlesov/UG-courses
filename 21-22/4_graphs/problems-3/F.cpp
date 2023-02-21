#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back

struct edge {
    int v, u, cost;
};

bool cmp(edge a, edge b) {
    return ((a.cost < b.cost) || (a.cost == b.cost && a.v < b.v) || (a.cost == b.cost && a.v == b.v && a.u < b.u));
}

int n;
vector<int> mark(105);
vector<edge> edges;
vector<vector<int>> g(105, vector<int> (105));

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
            if (g[i][j]) edges.PB({i, j, g[i][j]});
        }
    }
    for (int i = 1; i <= n; ++i) cin >> mark[i];
    sort(edges.begin(), edges.end(), cmp);
    int k = 0;
    while (k < edges.size() && mark[edges[k].v] == mark[edges[k].u]) ++k;
    if (mark[edges[k].v] == 0) cout << edges[k].v << ' ' << edges[k].u << endl;
    else cout << edges[k].u << ' ' << edges[k].v << endl; 


    return 0;
}
