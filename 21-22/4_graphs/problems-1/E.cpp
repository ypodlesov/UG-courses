#include<bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(int &ans, vector<vector<int>> &a, int v, vector<bool> &used) {
    used[v] = true;
    ans++;
    for (int i = 0; i < a[v].size(); i++) 
        if (!used[i] && a[v][i]) dfs(ans, a, i, used);
}

int main() {

    int n, s;
    int ans = 0;
    cin >> n >> s;
    vector<bool> used(n, false);
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    s--;
    dfs(ans, a, s, used);
    cout << ans;

    return 0;
}
