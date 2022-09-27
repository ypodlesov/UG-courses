#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back

vector<bool> used;
vector<int> order;
vector<vector<int>> out, in, components;

void dfs1(int v) {
    used[v] = true;
	for (int i = 0; i < out[v].size(); ++i)
		if (!used[out[v][i]])
			dfs1(out[v][i]);
	order.push_back(v);
}

void dfs2(int v, vector<int> &component) {
    used[v] = true;
	component.push_back(v);
	for (int i = 0; i < in[v].size(); ++i)
		if (!used[in[v][i]])
			dfs2(in[v][i], component);
}

int main() {

    int n, m;
    cin >> n >> m;
    out.assign(n + 1, vector<int>(0)), in.assign(n + 1, vector<int>(0));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        out[a].PB(b);
        in[b].PB(a);
    }
    used.assign(n + 1, false);
    for (int i = 1; i <= n; ++i) if (!used[i]) dfs1(i);
    reverse(order.begin(), order.end());
    used.assign(n + 1, false);
    for (auto v : order) {
		if (!used[v]) {
            vector<int> comp;
			dfs2 (v, comp);
			components.PB(comp);
		}
	}
    for (int i = 0; i < components.size(); ++i) {
        cout << i + 1 << ": ";
        for (int j = 0; j < components[i].size(); ++j) cout << components[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
