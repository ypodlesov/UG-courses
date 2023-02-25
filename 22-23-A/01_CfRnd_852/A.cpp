#include <bits/stdc++.h>
 
using namespace std;
 
void 
solve()
{
    long long a, b, n, m;
    cin >> a >> b >> n >> m;
    cout << n / (m + 1) * min(a * m, b * (m + 1)) + n % (m + 1) * min(a, b) << endl;
}
 
int
main(void)
{
    int t;
    cin >> t;
    while (t--) solve();
 
    return 0;
}