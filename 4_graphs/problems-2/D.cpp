#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

void dra(int b, vector<int> &d, vector<vector<pair<int,int>>> &g, vector<int> &p) {
    set<pair<int,int>> q;
    d[b] = 0;
    q.insert({d[b], b});
    while (!q.empty()) {
        int v = q.begin()->s;
        q.erase({d[v], v});
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i].s;
            if (d[to] > d[v] + g[v][i].f) {
                q.erase({d[to], to});
                d[to] = d[v] + g[v][i].f;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

int main() {

    int n, b, e, x;
    cin >> n >> b >> e;
    vector<vector<pair<int,int>>> g(n+5);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x > 0) g[i].push_back({x,j});
        }
    }
    vector<int> d(n+5, INT_MAX), p(n+5, -1);
    dra(b, d, g, p);
    if (d[e] != INT_MAX) {
        deque<int> w;
        for (int i = e; i != -1; i = p[i]) w.push_front(i);
        for (int i : w) cout << i << ' ';
    } else cout << -1;

    return 0;
}
