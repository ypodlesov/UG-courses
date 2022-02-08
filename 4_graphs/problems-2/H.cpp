#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

using namespace std;

struct edge {
    int a, b, cost;
};

int main() {

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> d[i][j];
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; ++j)
                if (d[i][k] < INT_MAX && d[k][j] < INT_MAX) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) ans = min(ans, d[i][j]);

    cout << ans;

    return 0;
}
