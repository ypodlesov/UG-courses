#include <bits/stdc++.h>

using namespace std;

bool valid(long long x, long long n, long long k) {
    return (x * x - n * n == k);
}

long long solve(long long k) {
    long long ans = 1e12;
    for (long long u = 1; u * u <= abs(k); ++u) {
        if (abs(k) % u == 0) {
            long long v = abs(k) / u;
            if ((u + v) & 1) continue;
            if (valid((u + v) / 2, (u - v) / 2, k)) ans = min(ans, abs(u + v) / 2); 
            if (valid((u - v) / 2, (u + v) / 2, k)) ans = min(ans, abs(u - v) / 2);
            if (valid((u + v) / 2, (v - u) / 2, k)) ans = min(ans, abs(u + v) / 2);
            if (valid((v - u) / 2, (u + v) / 2, k)) ans = min(ans, abs(v - u) / 2);
         }
    }
    return ans; 
}

int main() {

    long long k;
    cin >> k;
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = solve(k);
    if (ans == 1e12) {
        cout << "none\n";
    } else {
        cout << ans << endl;
    }

    return 0;
}
