#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

const long long MOD = INF + 7;


int main() {

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    long long a = 0, b = 0, c = 0, d = 0, ans = 1, a0 = 0, b0 = 0;
    for (long long i = 0; i < s1.size(); i++) {
        if ((s1[i] - '0') + (s2[i] - '0') >= 10) {
            if ((s1[i] - '0') + (s2[i] - '0') == 10 + (s3[i] - '0')) {
                c++;
            } else {
                if ((s1[i] - '0') + (s2[i] - '0') + 1 != 10 + (s3[i] - '0')) {
                    cout << '0';
                    return 0;
                }
                d++;
            }
        } else {
            if ((s1[i] - '0') + (s2[i] - '0') == (s3[i] - '0')) {
                a++;
                if (s1[i] == '0' || s2[i] == '0' || s3[i] == '0')
                    a0++;
            } else {
                if ((s1[i] - '0') + (s2[i] - '0') + 1 != (s3[i] - '0') && (s1[i] - '0') + (s2[i] - '0') + 1 != 10 + (s3[i] - '0')) {
                    cout << '0';
                    return 0;
                }
                if ((s1[i] - '0') + (s2[i] - '0') + 1 == 10 + (s3[i] - '0')) {
                    d++;
                    continue;
                }
                b++;
                if (s1[i] == '0' || s2[i] == '0' || s3[i] == '0')
                    b0++;
            }
        }
    }
    if (b != c) {
        cout << '0';
        return 0;
    }
    long long bf = 1, cf = 1;
    for (long long i = 1; i <= b; i++) {
        ans *= i;
        bf *= i;
        ans %= MOD;
        bf %= MOD;
    }
    for (long long i = 1; i <= c; i++) {
        ans *= i;
        cf *= i;
        ans %= MOD;
        cf %= MOD;
    }
    for (long long i = b + 1; i <= b + a; i++) {
        ans *= i;
        ans %= MOD;
    }
    long long ans0 = 1;
    for (long long i = b + 1; i <= b + a - 1; i++) {
        ans0 *= i;
        ans0 %= MOD;
    }
    ans0 *= bf;
    ans0 %= MOD;
    ans0 *= cf;
    ans0 %= MOD;
    ans0 *= a0;
    ans0 %= MOD;
    ans = ans - ans0;
    if (ans < 0) ans += MOD;


    long long ans1 = 1;
    for (long long i = b + 1; i <= b + a - 1; i++) {
        ans1 *= i;
        ans1 %= MOD;
    }
    ans1 *= bf;
    ans1 %= MOD;
    ans1 *= cf;
    ans1 %= MOD;
    ans1 *= b0;
    ans1 %= MOD;
    if (a == 0) {
        ans1 = 1;
        for (long long i = 1; i < b; i++) {
            ans1 *= i;
            ans1 %= MOD;
        }
        ans1 *= cf;
        ans1 %= MOD;
        ans1 *= b0;
        ans1 %= MOD;
    }
    ans = ans - ans1;
    if (ans < 0) ans += MOD;
    for (long long i = b; i <= b + d - 1; i++) {
        ans *= i;
        ans %= MOD;
    }
    cout << ans;
    
    return 0;
}
