#include <bits/stdc++.h>

using namespace std;

int main() {

    int ma = INT_MIN, mi = INT_MAX, n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == ma) a[i] = mi;
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}
