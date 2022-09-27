#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

void bfs(vector<vector<int>> &a, vector<vector<bool>> &used, vector<vector<int>> &d) {
    queue<pair<int,int>> q;
    q.push({1,1});
    used[1][1] = true;
    while (!q.empty()) {
        pair<int,int> v = q.front();
        q.pop();
        if (a[v.f + 1][v.s] != 1) { // 1
            int k = v.f + 1;
            while (a[k][v.s] != 2 && a[k][v.s] != 1) k++;
            if (a[k][v.s] == 1) k--;
            if (!used[k][v.s]) {
                used[k][v.s] = true;
                d[k][v.s] = d[v.f][v.s] + 1;
                q.push({k, v.s});
            }
        }

        if (a[v.f - 1][v.s] != 1) { // 2
            int k = v.f - 1;
            while (a[k][v.s] != 2 && a[k][v.s] != 1) k--;
            if (a[k][v.s] == 1) k++;
            if (!used[k][v.s]) {
                used[k][v.s] = true;
                d[k][v.s] = d[v.f][v.s] + 1;
                q.push({k, v.s});
            }
        }

        if (a[v.f][v.s + 1] != 1) { // 3
            int k = v.s + 1;
            while (a[v.f][k] != 2 && a[v.f][k] != 1) k++;
            if (a[v.f][k] == 1) k--;
            if (!used[v.f][k]) {
                used[v.f][k] = true;
                d[v.f][k] = d[v.f][v.s] + 1;
                q.push({v.f, k});
            }
        }

        if (a[v.f][v.s - 1] != 1) { // 4
            int k = v.s - 1;
            while (a[v.f][k] != 2 && a[v.f][k] != 1) k--;
            if (a[v.f][k] == 1) k++;
            if (!used[v.f][k]) {
                used[v.f][k] = true;
                d[v.f][k] = d[v.f][v.s] + 1;
                q.push({v.f, k});
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+5, vector<int>(m+5, 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    vector<vector<bool>> used(n+5, vector<bool>(m+5, false));
    vector<vector<int>> d(n+5, vector<int>(m+5));
    bfs(a, used, d);
    int res = INT_MAX;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 2) res = min(res, d[i][j]);

    cout << res << endl;

    return 0;
}
