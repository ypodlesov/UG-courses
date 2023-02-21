#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

int n, q, d, k;
vector<ll> a, add;
vector<vector<ll>> decomp;

int query(int i, int j, ll x) {
    int ans = 0;
    while (i % d && i <= j) {
        if (a[i] < x - add[i/d]) ++ans;
        ++i;
    }
    while (j % d != d - 1 && j >= i) {
        if (a[j] < x - add[j/d]) ++ans;
        --j;
    }
    for (int k = i / d; k < i / d + (j + 1 - i) / d; ++k) {
        auto it = lower_bound(decomp[k].begin(), decomp[k].end(), x - add[k]);
        if (it == decomp[k].end()) ans += decomp[k].size();
        else ans += int(it - decomp[k].begin());
    }
    return ans;
}

void update(int i, int j, ll x) {
    int l2 = i, r2 = j;
	bool flag = false;
	while (i <= j) {
		if (i % d == 0 && i + d - 1 <= j) add[i / d] += x, i += d;
		else a[i] += x, ++i, flag = true;
	}
	if (!flag) return;
	int l = l2, r = r2;
	int num = l / d;
	for (int i = num * d; i < min(n, (num + 1) * d); ++i) decomp[num][i % d] = a[i];
	sort(decomp[num].begin(), decomp[num].end());
	num = r / d;
	for (int i = num * d; i < min(n, (num + 1) * d); ++i) decomp[num][i % d] = a[i];
	sort(decomp[num].begin(), decomp[num].end());
}

int main() {

    cin >> n >> q;
    d = sqrt(n), k = n/d + 1;
    a.assign(n, 0), add.assign(k, 0);
    decomp.assign(k, vector<ll>(0, 0));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        decomp[i/d].PB(a[i]);
    }
    for (int i = 0; i < k; ++i) sort(decomp[i].begin(), decomp[i].end());
    while (q--) {
        int type, l, r;
        ll x;
        cin >> type >> l >> r >> x;
        if (type == 1) {
            cout << query(l-1, r-1, x) << endl;
        }
        else {
            update(l-1, r-1, x);
        }
    }

    return 0;
}
