#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m;

ll vert_sum(ll j) {
    return (n * j * (1 + j + (n - 1) * m)) / 2;
}

ll hor_sum(ll i) {
    return m * i * (1 + m + m * (i - 1)) / 2;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll sum = (1 + n * m) * n * m / 2;

        // vertical cut
        ll l = 0, step = m;
        while (step) {
            while (2 * vert_sum(l + step) > sum) step /= 2;
            l += step;
        }
        ll vert = l;
        if (abs(2 * vert_sum(vert + 1) - sum) < abs(2 * vert_sum(vert) - sum)) ++vert;

        // horizontal cut
        l = 0, step = n;
        while (step) {
            while (2 * hor_sum(l + step) > sum) step /= 2;
            l += step;
        }
        ll hor = l;
        if (abs(2 * hor_sum(hor + 1) - sum) < abs(2 * hor_sum(hor) - sum)) ++hor;

        ll a = abs(2 * vert_sum(vert) - sum);
        ll b = abs(2 * hor_sum(hor) - sum);
        if (a <= b) cout << "V " << vert + 1 << endl;
        else cout << "H " << hor + 1 << endl;
    }

    return 0;
}
