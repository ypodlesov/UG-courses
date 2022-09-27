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

    int num, n, m, x, y, z, start;
    cin >> num;
    while (num--) {
        cin >> n >> m;
        vector<vector<pair<int,int>>> g(n+1);
        for (int i = 1; i <= m; ++i) {
            cin >> x >> y >> z;
            g[x].push_back({z, y});
            g[y].push_back({z, x});
        }
        cin >> start;
        vector<int> d(n + 5, 2009000999);
        dra(start, d, g);
        for (int i = 0; i < n; ++i) cout << d[i] << ' ';
        cout << endl;
    }
    
    return 0;
}
