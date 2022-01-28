#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back

int n, m, maximum = 0, u1 = 0, u2 = 0;
vector<vector<int>> g(50005);
deque<int> q, way;
set<int> s;
vector<int> p(50005), U, metro;

void bfs(vector<int> &d) {
    vector<bool> used(50005, false);
    for (int i = 0; i < q.size(); ++i) used[q[i]] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
    	for (int i = 0; i < g[v].size(); ++i) {
    		int to = g[v][i];
    		if (!used[to]) used[to] = true, q.PB(to), d[to] = d[v] + 1, p[to] = v;
    	}
    }
}

bool valid(int time) {
    int vertex = way[time];
    q.PB(vertex);
    q.insert(q.end(), metro.begin(), metro.end());
    vector<int> d(n+1);
    bfs(d);
    for (int i = 1; i <= n; ++i)
        if (time < d[i]) return false;
    return true;
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        s.insert(x);
        metro.PB(x);
        q.PB(x);
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].PB(y), g[y].PB(x);
    }
    vector<int> d(n+1), du(n+1);
    bfs(d);
    for (int i = 1; i <= n; ++i) maximum = max(maximum, d[i]);
    for (int i = 1; i <= n; ++i) if (d[i] == maximum) U.PB(i);
    q.PB(U[0]);
    bfs(du);
    int max_dist = maximum;
    maximum = 0;
    for (int i = 0; i < U.size(); ++i) maximum = max(maximum, du[U[i]]);
    for (int i = 0; i < U.size(); ++i) if (du[U[i]] == maximum) u1 = U[i];
    q.PB(u1);
    du[u1] = 0, p[u1] = 0;
    bfs(du);
    maximum = 0;
    for (int i = 0; i < U.size(); ++i) maximum = max(maximum, du[U[i]]);
    for (int i = 0; i < U.size(); ++i) if (du[U[i]] == maximum) u2 = U[i];
    int tmp = u2;
    while (tmp) way.PB(tmp), tmp = p[tmp];
    for (int i = 0; i < way.size(); ++i)
        if (s.find(way[i]) != s.end())
            for (int i = 1; i <= n; ++i)
                if (s.find(i) == s.end()) {
                    cout << max_dist << endl << i << endl;
                    return 0;
                }
    if (way.size() == 1 || max_dist > du[u2]) {
        int v = 1;
        for (int i = 0; i < metro.size(); ++i)
            if (du[metro[i]] == max_dist) v = metro[i];
        v = p[v], way.clear();
        while (v) way.push_front(v), v = p[v];
    }
    int l = 0, r = way.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (valid(mid)) r = mid;
        else l = mid;
    }
    if (r >= max_dist) {
        for (int i = 1; i <= n; ++i)
            if (s.find(i) == s.end()) {
                cout << max_dist << endl << i << endl;
                return 0;
            }
    }
    cout << r << endl << way[r] << endl;

    return 0;
}
