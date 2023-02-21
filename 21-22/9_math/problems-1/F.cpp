#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

vector<bool> erat(int n) {
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (LL i = 2; i <= n; ++i) {
        if (prime[i])
            for (LL j = i * i; j <= n; j += i) prime[j] = false;
    }
    return prime;
}

int main() {

    int n;
    cin >> n;
    vector<bool> prime = erat(n);
    for (int i = 2; i <= n; ++i) {
        if (prime[i] && prime[n-i]) {
            cout << i << ' ' << n - i << endl;
            return 0;
        }
    }

    return 0;
}
