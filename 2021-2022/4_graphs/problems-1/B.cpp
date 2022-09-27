#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

int main() {

    int n, m, k, j;
    cin >> n >> m;
    vector<vector<int>> a(n+1);
    for (int i = 0; i < m; i++) {
        cin >> k >> j;
        a[k].push_back(j);
        a[j].push_back(k);
    }
    for (int i = 1; i <= n; i++) cout << a[i].size() << ' ';

    return 0;
}
