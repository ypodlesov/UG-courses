#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

struct node {
    int left, right, GCD;
    node *child_left, *child_right;
};

int gcd(int a, int b) {
    while (b) {
		a %= b, swap(a, b);
	}
	return a;
}

node *build(int left, int right, vector<int> &a) {
    if (left > right) return NULL;
    node *res = new node;
    res->left = left, res->right = right;
    if (left == right) {
        res->child_left = NULL;
        res->child_left = NULL;
        res->GCD = a[left];
    } else {
        int m = (left + right) / 2;
        res->child_left = build(left, m, a);
        res->child_right = build(m+1, right, a);
        res->GCD = gcd(res->child_left->GCD, res->child_right->GCD);
    }
    return res;
}

int query(int left, int right, node *root) {
    if (left > root->right || right < root->left) return 0;
    if (root->left >= left && root->right <= right) return root->GCD;
    return gcd(query(left, right, root->child_left), query(left, right, root->child_right));
}

int main() {

    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    node *root = build(0, n-1, a);
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        cout << query(l-1, r-1, root) << ' ';
    }
    cout << endl;

    return 0;
}
