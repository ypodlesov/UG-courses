#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back

int main() {

    int n, i_max = 0, k, b, m;
    cin >> n;
    vector<int> a(n), dp(n + 1, INF), p(n + 1, -1), mas(n, -1), ans;
    dp[0] = -INF;
    cin >> a[0] >> k >> b >> m;
    for (int i = 1; i < n; ++i) a[i] = (k * a[i - 1] + b) % m;

    for (int i = 0; i < n; ++i) {
        int j = int(upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin());
        if (a[i] > dp[j - 1]) {
            dp[j] = a[i];
            p[j] = i;
            mas[i] = p[j - 1];
            i_max = max(i_max, j);
        }
    }

    i_max = p[i_max];
    while (mas[i_max] != -1) {
        ans.push_back(a[i_max]);
        i_max = mas[i_max];
    }
    ans.push_back(a[i_max]);

    for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << ' ';
    cout << endl;


    return 0;
}
