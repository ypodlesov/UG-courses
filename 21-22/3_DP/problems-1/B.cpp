#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    ll n;
    cin >> n;
    vector<ll> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    a[0] = b[0] = c[0] = 1;
    a[1] = b[1] = 1;
    c[1] = 0;
    for (int i = 2; i <= n; ++i) {
        a[i] = a[i-1] + b[i-1] + c[i-1];
        b[i] = a[i-1];
        c[i] = b[i-1];
    }
    cout  << a[n] + b[n] + c[n];

    return 0;
}
