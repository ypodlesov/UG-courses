#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

int main() {

    int c, p, n;
    cin >> c >> p >> n;
    if (n <= c) {
        cout << n << endl;
        return 0;
    }
    int cur = c, v = 1, ans = c;
    while (cur < n) {
        if (cur < c) {
            int tmp = (c - cur + v - 1) / v;
            cur += v * tmp;
            ans += tmp;
        } else {
            int num = cur / c;
            int tmp = cur % c + v + p * num;
            int vt = v + p * (cur / c);
            if ((n - tmp + vt - 1) / vt < (n - cur + v - 1) / v) v += p * num, cur = cur % c + v, ++ans;
            else ans += (n - cur + v - 1) / v, cur = n;
        }
    }
    cout << ans << endl;

    return 0;
}
