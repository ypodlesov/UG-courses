#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

void dra(int b, vector<int> &d, vector<vector<pair<int,int>>> &a) {
    set<pair<int,int>> q;
    d[b] = 0;
    q.insert({d[b], b});
    while (!q.empty()) {
        int v = q.begin()->s;
        q.erase({d[v], v});
        for (int i = 0; i < a[v].size(); i++) {
            int to = a[v][i].s;
            if (d[to] > d[v] + a[v][i].f) {
                q.erase({d[to], to});
                d[to] = d[v] + a[v][i].f;
                q.insert({d[to], to});
            }
        }
    }
}


int main() {

    int n, m, x, y;
    cin >> n;
    vector<int> c(n + 5);
    for (int i = 1; i <= n; i++) cin >> c[i];
    cin >> m;
    vector<vector<pair<int,int>>> a(n+5);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[x].push_back({c[x], y});
        a[y].push_back({c[y], x});
    }
    vector<int> d(n + 5, INT_MAX);
    dra(1, d, a);
    if (d[n] != INT_MAX) cout << d[n];
    else cout << -1;

    return 0;
}
