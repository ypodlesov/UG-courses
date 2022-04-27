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

    int h1, m1, h2, m2, h3, m3, h4, m4;
    // cin >> h1 >> m1 >> h2 >> m2 >> h3 >> m3 >> h4 >> m4;
    scanf("%d:%d %d:%d %d:%d %d:%d", &h1, &m1, &h2, &m2, &h3, &m3, &h4, &m4);
    int a1 = h1 * 60 + m1;
    int a2 = h2 * 60 + m2;
    int a3 = h3 * 60 + m3;
    int a4 = h4 * 60 + m4;
    int d1, d2;
    // if (a1 > a4) d1 = 24 * 60 + a4 - a1;
    // else d1 = a4 - a1;
    d1 = (a4 + 24 * 60 - a1) % (24 * 60);
    d2 = (a3 + 24 * 60 - a2) % (24 * 60);
    if (d2 >= d1) d1 += 24 * 60;
    int ans = abs(d1 - d2);
    if (ans & 1) {
        int res = (ans + 1) / 2;
        printf("%0.2d:%0.2d\n", res / 60, res % 60);
    } else {
        int res = ans / 2;
        printf("%0.2d:%0.2d\n", res / 60, res % 60);
    }


    return 0;
}
