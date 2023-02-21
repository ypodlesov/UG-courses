#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

vector<pair<LL, int>> factor(LL n) {
    vector<pair<LL,int>> res;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res.PB({i, 0});
            while (n % i == 0) {
                ++res.back().ss;
                n /= i;
            }
        }
    }
    if (n > 1) res.PB({n, 1});
    return res;
}

LL number_of_divs(LL n) {
    vector<pair<LL,int>> f = factor(n);
    LL res = 1;
    for (int i = 0; i < f.size(); ++i) res *= (f[i].ss + 1);
    return res;
}

int main() {

    LL x;
    cin >> x;
    cout << number_of_divs(x) << endl;

    return 0;
}
