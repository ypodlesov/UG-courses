#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

int n, d, m;
vector<int> a, prefix;

int query(int i, int j) {
    int ans = -INF;
    while (i % d && i <= j) ans = max(ans, a[i]), ++i;
    while (j % d != d - 1 && j >= i) ans = max(ans, a[j]), --j;
    for (int k = i / d; k < i / d + (j + 1 - i) / d; ++k) ans = max(ans, prefix[k]);
    return ans;
}

int main() {

    cin >> n;
    a.assign(n+1, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    d = sqrt(n), m = n / d + 1;
    prefix.assign(m, 0);
    for (int i = 0; i < n; ++i) prefix[i/d] = max(prefix[i/d], a[i]);
    while (true) {
        string ch;
        cin >> ch;
        if (ch == "max") {
            int left, right;
            cin >> left >> right;
            cout << query(left, right) << endl;
        } else if (ch == "finish") break;
    }

    return 0;
}
