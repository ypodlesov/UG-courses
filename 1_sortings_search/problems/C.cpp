#include <bits/stdc++.h>
using namespace std;

int n, k, p;
vector<vector<int>> a(n, vector<int>(4));

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i][1] >> a[i][2] >> a[i][3];
    cin >> k >> p;
    sort(a.begin(), a.end());
    



    return 0;
}
