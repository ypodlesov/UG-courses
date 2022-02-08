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


    int n, b, e;
    cin >> n >> b >> e;
    b--, e--;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> d(n, vector<int>(n, pow(10, 9)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
            if (d[i][j] == -1) d[i][j] = INT_MAX;
        }
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; ++j)
                if (d[i][k] < INT_MAX && d[k][j] < INT_MAX) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    if (d[b][e] < pow(10,9)) cout << d[b][e];
    else cout << -1;

    return 0;
}
