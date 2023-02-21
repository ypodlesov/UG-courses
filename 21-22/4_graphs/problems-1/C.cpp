#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

int main() {

    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(n+1));
    vector<int> colour(n+1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];

    for (int i = 1; i <= n; i++) cin >> colour[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] && colour[i] != colour[j]) ++ans;
            
    cout << ans/2;

    return 0;
}
