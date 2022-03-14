#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

struct node {
    int left, right;
    ll sum, add;
    node *child_left, *child_right;
};

node *build(int left, int right, vector<int> &a) {
    if (left > right) return NULL;
    node *res = new node;
    res->left = left;
    res->right = right;
    res->add = 0;
    if (left == right) {
        res->child_left = NULL;
        res->child_right = NULL;
        res->sum = a[left];
        return res;
    }
    int mid = (left + right) / 2;
    res->child_left = build(left, mid, a);
    res->child_right = build(mid+1, right, a);
    res->sum = res->child_left->sum + res->child_right->sum;
    return res;
}

int query(int left, int right, node *root) {
    if (left > root->right || right < root->left) return 0;
    if (left <= root->left && right >= root->right) return root->sum + root->add * (root->right - root->left + 1);
    ll tmp = query(left, right, root->child_left) + query(left, right, root->child_right);
    if (root->left <= left && root->right >= right) return tmp + root->add * (right - left + 1);
    if (root->right <= right) return tmp + root->add * (root->right - left + 1);
    if (root->left >= left) return tmp + root->add * (right - root->left + 1);
    return 0;
}

void update(node *root, int left, int right, int delta) {
    if (root->left > right || root->right < left) return;
    if (root->left >= left && root->right <= right) {
        root->add += delta;
        return;
    }
    update(root->child_left, left, right, delta);
    update(root->child_right, left, right, delta);
    node *tmp_l = root->child_left, *tmp_r = root->child_right;
    root->sum = tmp_l->sum + tmp_l->add * (tmp_l->right - tmp_l->left + 1) + tmp_r->sum + tmp_r->add * (tmp_r->right - tmp_r->left + 1);
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    node *root = build(0, n - 1, a);
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type & 1) {
            ll s;
            cin >> s;
            update(root, l, r-1, s);
        } else cout << query(l, r-1, root) << endl;
    }

    return 0;
}
