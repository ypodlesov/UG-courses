#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

LL gcd(LL a, LL b) {
    return b ? gcd (b, a % b) : a;
}

int main() {

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << gcd(abs(x2 - x1), abs(y2 - y1)) + 1 << endl;

    return 0;
}
