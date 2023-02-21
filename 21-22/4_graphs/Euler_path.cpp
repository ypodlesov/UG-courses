#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

int n, m, a, b, cnt;
vector<int> deg(105), path;
vector<set<int>> g(105);
stack<int> vs;

int main() {

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        g[a].insert(b), g[b].insert(a);
        ++deg[a], ++deg[b];
    }
    for (int i = 1; i <= n; ++i)
        if (deg[i] & 1) ++cnt;
    if (cnt > 2 || cnt == 1) {
        cout << "No Euler path\n";
        return 0;
    } else if (cnt == 2) cout << "Found Euler path\n";
    else if (cnt == 0) cout << "Found Euler cycle\n";
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
            g[v].erase(u), g[u].erase(v);
        }
    }
    for (auto i : path) cout << i << "->";
    cout << endl;

    return 0;
}
