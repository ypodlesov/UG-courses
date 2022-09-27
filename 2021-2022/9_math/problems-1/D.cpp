#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

int foo(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return n/i;
    }
    return 1;
}

int main() {

    int n;
    cin >> n;
    int res = foo(n);
    cout << res << ' ' << n - res << endl;

    return 0;
}
