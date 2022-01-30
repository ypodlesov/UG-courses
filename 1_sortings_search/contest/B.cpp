#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a(10005, 0);

bool valid(int dist) {
    int j = 0, res = 1;
    for (int i = 1; i < n; ++i) 
        if (a[i] - a[j] >= dist) ++res, j = i;
    return res >= k;
}

int main() {

    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = a[n-1] - a[0] + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (valid(m)) l = m;
        else r = m;
    }
    cout << l << endl;

    return 0;
}
