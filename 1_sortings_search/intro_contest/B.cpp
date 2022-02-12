#include <bits/stdc++.h>

using namespace std;

int bin_search(vector<int> &a, int key);

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        int idx = bin_search(a, b[i]);
        if (idx == -1) {
            cout << 0 << endl;
            continue;
        }
        int left, right;
        left = right = idx;
        while (left >= 0 && a[left] == a[idx]) --left;
        while (right < n && a[right] == a[idx]) ++right;
        left += 2;
        cout << left << ' ' << right << endl;
    }

    return 0;
}

int bin_search(vector<int> &a, int key) {
    int left = 0, right = a.size() - 1;
    int res = -1;
    while (left <= right) {
        int m = (left + right) / 2;
        if (a[m] == key) return m;
        if (key > a[m]) left = m + 1;
        else right = m - 1;
    }
    return res;
}
