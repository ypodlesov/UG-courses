#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int main() {

    int n;
    cin >> n;
    int *a1 = new int[n + 5], *b1 = new int[n + 5], *c1 = new int[n + 5], *ans1 = new int[n + 5];
    int *a = a1 + 3, *b = b1 + 3, *c = c1 + 3, *ans = ans1 + 3;
    ans[-2] = ans[-1] = INF, ans[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i <= n; ++i) {
        ans[i] = min(min(ans[i-1] + a[i], ans[i-2] + b[i-1]), ans[i-3] + c[i-2]);
    }
    cout << ans[n] << endl;

    return 0;
}
