#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

LL sum_pows(int k, LL delta) {
    LL sum = 0;
    for (int i = 0; i <= k; ++i) sum += powl(10, i) * delta;
    return sum;
}

int count_length(LL n) {
    int res = 0;
    while (n) ++res, n/=10;
    return res;
}

int main() {

    LL x;
    int k;
    cin >> x >> k;
    int length = count_length(x);
    vector<LL> a;
    if (k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int l = 0; l < length; ++l) {
                    LL y = 0;
                    for (int idx = 0; idx < length; ++idx) y = y * 10 + (idx == l ? j : i);
                    a.PB(y);
                }
            }
        }
    } else for (int i = 1; i < 10; ++i) a.PB(sum_pows(length - 1, i));
    sort(a.begin(), a.end());
    cout << *lower_bound(a.begin(), a.end(), x) << endl;

    return 0;
}
