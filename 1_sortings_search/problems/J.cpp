#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll H, D, h, d;
bool valid(ll n) {
    ll k = n * h;
    ll tmp = H;
    while (tmp > 0) {
        if (n <= 0) return false;
        tmp -= n * d;
        if (tmp <= 0) return true;
        k -= D;
        if (k <= 0) return false;
        n = (k - 1) / h + 1;
    }
    return true;
}

int main() {

    cin >> H >> D >> h >> d;
    if (d * (1 + (h - 1) / D) >= H) {
        cout << 1;
        return 0;
    }
    ll l = 1, r = H;
    while (r - l > 1) {
        ll n = (l + r) / 2;
        if (valid(n)) r = n;
        else l = n;
    }
    cout << r << endl;

    return 0;
}
