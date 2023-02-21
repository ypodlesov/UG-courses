#include <bits/stdc++.h>
using namespace std;

using namespace std;
#define ll long long
#define sp_ceil 1000000000 + 9
#define sp_floor -1000000000 - 7
using namespace std;
#define ll long long
#define sp_ceil 1000000000 + 9
#define sp_floor -1000000000 - 7

void dfs(vector<vector<int>> &a, int v, vector<int> &used, bool &flag, int colour) {
    used[v] = colour;
    for (int i = 0; i < a[v].size(); i++) {
        if (used[a[v][i]] == -1) dfs(a, a[v][i], used, flag, (colour + 1) % 2);
        if (used[a[v][i]] == used[v]) flag = false;
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    int x, y;
    vector<vector<int>> a(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[x-1].push_back(y-1);
        a[y-1].push_back(x-1);
    }
    bool flag = true;
    vector<int> used(n, -1);
    for (int i = 0; i < n; i++) {
        if (used[i] == -1) dfs(a, i, used, flag, 1);
    }
    if (flag) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            if (used[i]) cout << i+1 << ' ';
    } else cout << "NO";

    return 0;
}
