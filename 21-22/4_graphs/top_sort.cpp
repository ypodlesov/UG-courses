#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back

vector<vector<int>> g(100005);
vector<int> order, used(100005), indeg(100005);
set<int> vs;

int main() {

    int n, num, k;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        while(num--) {
            cin >> k;
            g[i].PB(k);
            ++indeg[k];
        }
    }
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0) vs.insert(i);
    while (!vs.empty()) {
        int v = *vs.rbegin();
        vs.erase(v);
        order.PB(v);
        for (auto u : g[v]) {
            --indeg[u];
            if (indeg[u] == 0) vs.insert(u);
        }
    }
    reverse(order.begin(), order.end());
    for (auto i : order) cout << i << ' ';
    cout << endl;

    return 0;
}
