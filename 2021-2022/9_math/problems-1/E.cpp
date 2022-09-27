#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

bool is_prime(int n) {
    int d = sqrt(n);
    int i = 2;
    while (n % i != 0 && i <= d) ++i;
    return i > d;
}

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

int main() {

    int x;
    cin >> x;
    vector<int> a = {2, 3};
    while (a.back() < 349954501) {
        int res = a[0];
        for (int j = 1; j < a.size(); ++j) res *= a[j];
        a.PB(res - 1);
    }
    vector<int> ans;
    for (int i = 0; i < a.size() && x > 1; ++i) {
        while (x % a[i] == 0) {
            ans.PB(a[i]);
            x /= a[i];
        }
    }
    if (x > 1) cout << 0;
    else for (auto i : ans) cout << i << ' ';
    cout << endl;




    return 0;
}
