#include <bits/stdc++.h>
using namespace std;

int n, k;

int max_of(vector<int> &a) {
    int m = 0;
    for (int i = 0; i < a.size(); ++i) m = max(m, a[i]);
    return m;
}

bool valid(vector<int> &a, int m) {
    int res = 0;
    for (int i = 0; i < a.size(); ++i) res += a[i] / m;
    return res >= k;
}

int main() {

    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = max_of(a) + 5;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (valid(a, m)) l = m;
        else r = m;
    }
    cout << l << endl;

    return 0;
}
