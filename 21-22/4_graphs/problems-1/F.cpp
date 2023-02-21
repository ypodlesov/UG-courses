#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back

void dfs(vector<vector<int>> &a, int v, vector<bool> &used, int &num, vector<vector<int>> &comps, int ans) {
    used[v] = true;
    num++;
    comps[ans-1].push_back(v);
    for (int i = 0; i < a[v].size(); i++)
        if (!used[a[v][i]]) dfs(a, a[v][i], used, num, comps, ans);
}

int main() {

    int n, m;
    cin >> n >> m;
    int x, y;
    vector<bool> used(n);
    vector<vector<int>> a(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[x-1].PB(y-1), a[y-1].PB(x-1);
    }
    int ans = 0;
    vector<int> nums;
    vector<vector<int>> comps(n);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            int num = 0;
            ans++;
            dfs(a, i, used, num, comps, ans);
            nums.PB(num);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
        for (int j = 0; j < comps[i].size(); j++) cout << comps[i][j] + 1 << ' ';
        cout << endl;
    }

    return 0;
}
