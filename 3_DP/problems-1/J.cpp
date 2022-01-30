#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    vector<vector<int>> l(n+1, vector<int>(m+1));
    if (a[0] == b[0]) l[0][0] = 1;
    for (int i = 1; i < m; ++i)
        if (b[i] == a[0] || l[0][i-1]) l[0][i] = 1;
    for (int i = 1; i < n; ++i)
        if (a[i] == b[0] || l[i-1][0]) l[i][0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i] == b[j]) l[i][j] = l[i-1][j-1] + 1;
            else l[i][j] = max(l[i-1][j], l[i][j-1]);
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << l[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << l[n-1][m-1] << endl;

    return 0;
}
