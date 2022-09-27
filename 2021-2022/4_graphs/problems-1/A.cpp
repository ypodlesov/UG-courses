#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    int n;
    int ans = 0;
    cin >> n;
    vector<vector<int>> a(n, (vector<int> (n)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j]) ans++;

    cout << ans / 2;

    return 0;
}
