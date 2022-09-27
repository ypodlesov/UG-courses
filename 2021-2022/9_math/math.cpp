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

LL gcd(LL a, LL b, LL &x, LL &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    LL x1, y1;
    LL d = gcd(b % a, b, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution (LL a, LL b, LL c, LL & x0, LL & y0, LL & g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g) return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 *= -1;
	if (b < 0) y0 *= -1;
	return true;
}

LL lcm(LL a, LL b) {
    return a * b / gcd(a, b);
}

vector<pair<LL, int>> factor(LL n) {
    vector<pair<LL,int>> res;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res.PB({i, 0});
            while (n % i == 0) {
                ++res.back().ss;
                n /= i;
            }
        }
    }
    if (n > 1) res.PB({n, 1});
    return res;
}

LL number_of_divs(LL n) {
    vector<pair<LL,int>> f = factor(n);
    LL res = 1;
    for (int i = 0; i < f.size(); ++i) res *= (f[i].ss + 1);
    return res;
}

vector<bool> erat(LL n) {
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (LL i = 2; i <= n; ++i) {
        if (prime[i])
            for (LL j = i * i; j <= n; j+=i) prime[j] = false;
    }
    return prime;
}

int phi(LL n) {
	LL result = n;
	for (LL i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			result -= result / i;
		}
	if (n > 1) result -= result / n;
	return result;
}

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			--n;
		} else {
			a *= a;
			n >>= 1;
		}
    }
	return res;
}

bool is_prime(int n) {
    int d = sqrt(n);
    int i = 2;
    while (n % i != 0 && i <= d) ++i;
    return i > d;
}

int main() {

    LL a, n;
    cin >> a >> n;
    cout << binpow(a, n) << endl;

    return 0;
}
