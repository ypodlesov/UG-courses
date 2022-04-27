#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(max(100 / gcd(a, 100), 100 / gcd(b, 100)), max(100 / gcd(c, 100), 100 / gcd(d, 100))) << endl;


    return 0;
}
