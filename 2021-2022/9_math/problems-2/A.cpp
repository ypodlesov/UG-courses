#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

int main() {

    LL n;
    cin >> n;
    LL a = n / 3, b = a + 1, c = b + 1;
    for (LL i = n/3 - 4; i <= n/3 + 5; ++i) {
        for (LL j = i + 1; j <= n/3 + 5; ++j) {
            LL k = n - i - j;
            if (k == j || k == i) continue;
            if (i * i + j * j + k * k < a * a + b * b + c * c) a = i, b = j, c = k;
        }
    }
    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}
