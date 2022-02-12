#include<bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(vector<vector<int>> &a, int v, vector<int> &used, vector<char> &colour, bool &flag, vector<int> &from) {
    used[v] = 1;
    for (int i = 0; i < a[v].size(); i++) {
        if (a[i][v]) {
            if (!used[i]) {
                from[i] = v;
                dfs(a, i, used, colour, flag, from);
            }
            if (used[i] == 1 && from[v] != i) flag = false;
        }
    }
    used[v] = 2;
}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> used(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    int num = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            num++;
            vector<char> colour(n, 'w');
            vector<int> from(n);
            dfs(a, i, used, colour, flag, from);
        }
    }
    if (flag && num < 2) cout <<  "YES";
    else cout << "NO";

    return 0;
}
