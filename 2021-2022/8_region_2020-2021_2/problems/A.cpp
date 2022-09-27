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

    LL d, m, w, i, j, k;
    cin >> d >> m >> w;
    cin >> i >> j >> k;
    i = ((k-1) * d * m + (j-1) * d + i - 1) % w;
    cout << char('a' + i) << endl;

    return 0;
}
