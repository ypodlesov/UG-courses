#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

LL a, b, c, x, k;

bool check(LL m) {
    if (m >= a && m <= b) return (double)(m * k) + (double)(m * c * k) / 100 <= (double)x;
    return m * k <= x;
}

int main() {

    cin >> a >> b >> c >> x >> k;
    if ((b + 1) * k <= x) {
        cout << x / k << endl;
        return 0;
    }
    LL l = 0, r = x / k + 10;
    while (l < r - 1) {
        LL m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << endl;

    return 0;
}
