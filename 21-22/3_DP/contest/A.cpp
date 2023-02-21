#include<bits/stdc++.h>
using namespace std;

#define ll long long

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n+1, vector<int>(m+1, 0));
    d[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (d[i][j] == 0) d[i][j] = d[i][j-1] + d[i-1][j];
        }
    }
    cout << d[n][m];

    return 0;
}
