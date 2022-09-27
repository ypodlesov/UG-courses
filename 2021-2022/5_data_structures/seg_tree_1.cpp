#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

const int N = 105;

int n, t[4*N], a[N];

void build(int v, int tl, int tr) {
	if (tl == tr) {
        t[v] = a[tl];
        return;
    }
	int tm = (tl + tr) / 2;
	build(v*2, tl, tm);
	build(v*2 + 1, tm + 1, tr);
	t[v] = t[v*2] + t[v*2+1];
}

int sum (int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm)) + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
        t[v] = val;
        return;
    }
	int tm = (tl + tr) / 2;
	if (pos <= tm) update (v*2, tl, tm, pos, val);
	else update (v*2+1, tm+1, tr, pos, val);
	t[v] = t[v*2] + t[v*2+1];
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= 2*n; i *= 2) {
        for (int j = i; j < i*2; ++j) cout << t[j] << ' ';
        cout << endl;
    }

    return 0;
}
