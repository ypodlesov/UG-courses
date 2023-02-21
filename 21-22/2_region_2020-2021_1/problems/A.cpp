#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    ll k, a, x, b, y;
    cin >> k >> a >> x >> b >> y;
    ll first_case = max(k - a, 0ll) * x + max(k - a - b, 0ll) * y; // begin with first machine
    ll second_case = max(k - b, 0ll) * y + max(k - a - b, 0ll) * x; // begin with second machine
    cout << max(first_case, second_case) << endl; // choose max of cases

    return 0;
}
