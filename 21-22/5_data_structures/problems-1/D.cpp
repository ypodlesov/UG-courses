#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

int n, d, m;
vector<int> a, prefix;
vector<vector<int>> decomp;

int max_query(int i, int j) {
    int ans = -INF;
    while (i % d && i <= j) ans = max(ans, a[i]), ++i;
    while (j % d != d - 1 && j >= i) ans = max(ans, a[j]), --j;
    for (int k = i / d; k < i / d + (j + 1 - i) / d; ++k) ans = max(ans, prefix[k]);
    return ans;
}

int num_query(int i, int j, int val) {
    int res = 0;
    while (i % d && i <= j) {
        if (val == a[i]) ++res;
        ++i;
    }
    while (j % d != d - 1 && j >= i) {
        if (val == a[j]) ++res;
        --j;
    }
    for (int k = i / d; k < i / d + (j + 1 - i) / d; ++k) {
        res += upper_bound(decomp[k].begin(), decomp[k].end(), val) -
            lower_bound(decomp[k].begin(), decomp[k].end(), val);
    }
    return res;
}

int main() {

    cin >> n;
    a.assign(n+1, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    d = sqrt(n), m = n / d + 1;
    prefix.assign(m, 0), decomp.assign(m, vector<int>());
    for (int i = 0; i < n; ++i) {
        prefix[i/d] = max(prefix[i/d], a[i]);
        decomp[i/d].PB(a[i]);
    }
    for (int i = 0; i < m; ++i) sort(decomp[i].begin(), decomp[i].end());
    int k;
    cin >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        int ans1 = max_query(x, y);
        int ans2 = num_query(x, y, ans1);
        cout << ans1 << ' ' << ans2 << endl;
    }

    return 0;
}
