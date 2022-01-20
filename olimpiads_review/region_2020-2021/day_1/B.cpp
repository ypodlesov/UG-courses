#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n, m;

ll vert_sum(int j) {
    return j * n * (1 + j + m * (n - 1)) / 2;
}

ll hor_sum(int i) {
    return i * m * (1 + m + m * (i - 1)) / 2;
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
        if (abs(2 * vert_sum(l) - sum) > abs(2 * vert_sum(l + 1) - sum)) ++vert;

        // horizontal cut
        l = 0, step = n;
        while (step) {
            while (2 * hor_sum(l + step) > sum) step /= 2;
            l += step;
        }
        ll hor = l;
        if (abs(2 * hor_sum(l) - sum) > abs(2 * hor_sum(l + 1) - sum)) ++hor;

        ll a = abs(2 * vert_sum(vert) - sum);
        ll b = abs(2 * hor_sum(hor) - sum);
        if (a <= b) cout << "V " << vert + 1 << endl;
        else cout << "H " << hor + 1 << endl;

    }

    return 0;
}
