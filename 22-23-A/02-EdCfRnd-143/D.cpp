#include <bits/stdc++.h>
 
using namespace std;
 
const long long MOD = 998244353;
 
 
long long 
binpow(long long a, long long n) 
{
    long long res = 1;
    while (n) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}
 
int
main()
{
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= n/6; ++i) {
        ans = ans * ((i + n/6) * binpow(i, MOD - 2) % MOD) % MOD;
    }
    for (int i = 1; i <= n / 3; ++i) {
        vector<int> a(3);
        for(int j = 0; j < 3; j++) cin >> a[j];
        long long mn = *min_element(a.begin(), a.end());
        long long cnt_min = count(a.begin(), a.end(), mn);
        ans = ans * cnt_min % MOD;
    }
    cout << ans << endl;
}