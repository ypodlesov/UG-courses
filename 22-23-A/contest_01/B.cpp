#include <bits/stdc++.h> 
 
using namespace std;
 
void 
solve(void)
{
    long long x, y;
    cin >> x >> y;
    cout << 2 * (x - y) << endl;
    for (long long i = y; i <= x; ++i) cout << i << ' ';
    for (long long i = x - 1; i > y; --i) cout << i << ' ';
    cout << endl;
}
 
int 
main(void)
{
    int t;
    cin >> t;
    while (t--) solve();
 
    return 0;
}