#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

int n;
vector<int> t, a;

void build(int v, int tl, int tr) {
	if (tl == tr) {
        t[v] = a[tl];
        return;
    }
	int tm = (tl + tr) / 2;
	build(v*2, tl, tm);
	build(v*2 + 1, tm + 1, tr);
	t[v] = min(t[v*2], t[v*2+1]);
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r) return INF;
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) / 2;
	return min(query(v*2, tl, tm, l, min(r,tm)), query(v*2+1, tm+1, tr, max(l,tm+1), r));
}

int main() {

    int n, k;
    cin >> n >> k;
    a.assign(n+1, 0), t.assign(4*n, INF);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i + k - 1 <= n; ++i) cout << query(1, 1, n, i, i + k - 1) << endl;

    return 0;
}
