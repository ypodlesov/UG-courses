#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll w, h, n;
ll l, r, m;

int main() {
	cin >> w >> h >> n;
	l = min(w, h);
	r = n * max(w, h);
	while (l < r) {
		m = (l + r) / 2;
		if (n <= (m / w) * (m / h)) r = m;
		else l = m + 1;
	}
	cout << l;
	return 0;
}
