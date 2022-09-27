#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

struct node {
    int left, right, max, m_idx;
    node *child_left, *child_right;
};

node *build(int left, int right, vector<int> &a) {
    if (left > right) return NULL;
    node *res = new node;
    res->left = left, res->right = right;
    if (left == right) {
        res->child_left = NULL;
        res->child_left = NULL;
        res->m_idx = left;
        res->max = a[left];
    } else {
        int m = (left + right) / 2;
        res->child_left = build(left, m, a);
        res->child_right = build(m+1, right, a);
        if (res->child_left->max > res->child_right->max) {
            res->max = res->child_left->max;
            res->m_idx = res->child_left->m_idx;
        } else {
            res->max = res->child_right->max;
            res->m_idx = res->child_right->m_idx;
        }
    }
    return res;
}

pair<int,int> query(int left, int right, node *root) {
    if (left > root->right || right < root->left) return {-INF, 0};
    if (root->left >= left && root->right <= right) return {root->max, root->m_idx};
    pair<int,int> l = query(left, right, root->child_left);
    pair<int,int> r = query(left, right, root->child_right);
    if (l.f > r.f) return l;
    return r;
}

int main() {

    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.PB(x);
    }
    node *root = build(0, a.size()-1, a);
    int k;
    cin >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        pair<int,int> ans = query(x, y, root);
        cout << ans.f << ' ' << ans.s + 1 << endl;
    }

    return 0;
}
