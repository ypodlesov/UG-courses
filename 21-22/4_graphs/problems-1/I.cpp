#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back

vector<int> used(105), order;
vector<vector<int>> g(105);


bool has_cycle(int v) {
    used[v] = 1;
    bool flag = false;
    for (int i = 0; i < g[v].size(); ++i)
        if (used[g[v][i]] == 1) return true;
        else if (!used[g[v][i]]) flag = has_cycle(g[v][i]);
    used[v] = 2;
    return flag;
}

void top_sort(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]]) top_sort(g[v][i]);
    order.push_back(v);
}

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].PB(y);
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i] && has_cycle(i)) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    used.assign(105, 0);
    for (int i = 1; i <= n; ++i)
        if (!used[i]) top_sort(i);
    reverse(order.begin(), order.end());
    for (auto i : order) cout << i << ' ';
    cout << endl;

    return 0;
}
