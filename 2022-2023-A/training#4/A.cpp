#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sqr(A) (A * A)

int main() {
    ll n;
    cin >> n; 
    ll u;
    if ((n % 2 == 0 && n % 4 != 0) || n == 1 || n == 2 || n == 4) cout << "No\n";
    else if (!n) cout << "Yes\n" << 1 << ' ' << 1 << endl;
    else if (n & 1) cout << "Yes\n" << (n + 1) / 2 << ' ' << (n - 1) / 2 << endl;
    else cout << "Yes\n" << (n/2 + 2) / 2 << ' ' << (n/2 - 2) / 2 << endl;
}
