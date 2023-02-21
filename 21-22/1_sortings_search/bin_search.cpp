#include <bits/stdc++.h>

// with all questions and suggestions write to the e-mail:
// ypodlesov@gmail.com

using namespace std;

int bin_search(vector<int> &a, int key);

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int key;
    cin >> key;
    int ans = bin_search(a, key);
    cout << ans << endl;


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
