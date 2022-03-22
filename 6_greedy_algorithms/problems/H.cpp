#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

int n, m, l;
vector<int> a, b;

multiset<int> v, used;


int main() {

    cin >> n >> m >> l;
    a.assign(n, 0), b.assign(m, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v.insert(a[i]);
    }
    for (int i = 0; i < m; ++i) cin >> b[i];
    int ans = 0;
    while (ans < m) {
        if (used.find(b[ans]) != used.end()) {
            ++ans;
            continue;
        }
        auto it = v.upper_bound(b[ans]);
        if (it == v.begin()) break;
        --it;
        if (l < b[ans] - *it) break;
        l -= (b[ans] - *it);
        used.insert(b[ans]);
        v.erase(it);
        ++ans;
    }
    cout << ans << endl;

    return 0;
}
