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
    vector<vector<ll>> a(n, vector<ll>(n));
    vector<vector<ll>> d(n, vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> d[i][j];
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    ll ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (d[i][i] < 0) {
            cout << -1 << endl;
            return 0;
        }
        for (int j = 0; j < n; j++) {
            if (i != j) ans = min(ans, d[i][j]);
        }
    }

    cout << ans;

    return 0;
}
