#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

int main() {

    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].ff >> a[i].ss;
    LL cnt = 0;
    for (int i = 0; i < n; ++i) cnt += gcd(abs(a[(i+1) % n].ff - a[i].ff), abs(a[(i+1) % n].ss - a[i].ss));
    cout << cnt << endl;

    return 0;
}
