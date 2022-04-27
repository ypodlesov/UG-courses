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
    int n, d = 0;
    cin >> n;
    if(n < 12) {
    	cout << "13223140496";
    	return 0;
    }
    n -= 11;

    if (n % 22 == 0) d = n / 22;
    else d = (n - n % 22 + 22) / 22;

    for (int r = 1; r < d + 1; r++) cout<<"1322314049586776859504";

    cout<<"13223140496";
    return 0;
}
