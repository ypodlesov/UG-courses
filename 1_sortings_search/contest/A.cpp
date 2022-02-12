#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0; i < m; ++i) {
        auto it_first = lower_bound(a.begin(), a.end(), b[i]);
        auto it_last = upper_bound(a.begin(), a.end(), b[i]);
        cout << it_last - it_first << ' ';
    }
    cout << endl;

    return 0;
}
