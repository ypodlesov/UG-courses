#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n, x, y, ans;

bool valid(ll m) {
	return (n <= (m / x) + (m / y));
}

int main() {

	cin >> n >> x >> y;
	ans += min(x, y);
	--n;
	ll left = 0, right = min(x, y) * n, m;
	while (n && left < right) {
		m = (left + right) / 2;
		if (valid(m)) right = m;
		else left = m + 1;
	}
	cout << ans + left << endl;

	return 0;
}
