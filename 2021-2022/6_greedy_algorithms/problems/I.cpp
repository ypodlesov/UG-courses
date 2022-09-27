#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

int main() {

    int l, n;
    cin >> l >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!a[i]) continue;
        ++ans;
        i += l - 1;
    }
    cout << ans << endl;

    return 0;
}
