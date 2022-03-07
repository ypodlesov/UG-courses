#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

struct node {
    int left, right, max, add;
    node *child_left, *child_right;
};

node *build(int left, int right, vector<int> &a) {
    if (left > right) return NULL;
    node *res = new node;
    res->left = left, res->right = right;
    if (left == right) {
        res->child_left = NULL;
        res->child_left = NULL;
        res->add = 0;
        res->max = a[left];
    } else {
        int m = (left + right) / 2;
        res->child_left = build(left, m, a);
        res->child_right = build(m+1, right, a);
        res->max = max(res->child_left->max, res->child_right->max);
    }
    return res;
}

int query(int left, int right, node *root) {
    if (left > root->right || right < root->left) return -INF;
    if (root->left >= left && root->right <= right) return root->max + root->add;
    return max(query(left, right, root->child_left), query(left, right, root->child_right)) + root->add;
}

void update(node *root, int idx, int val) {
    if (root->left > idx || root->right < idx) return;
    if (root->left == root->right) {
        root->max = val;
        return;
    }
    update(root->child_left, idx, val);
    update(root->child_right, idx, val);
    root->max = max(root->child_left->max + root->child_left->add,
         root->child_right->max + root->child_right->add);
}

void update(node *root, int left, int right, int delta) {
    if (left > root->right || right < root->left) return;
    if (root->left >= left && root->right <= right) {
        root->add += delta;
        return;
    }
    update(root->child_left, left, right, delta);
    update(root->child_right, left, right, delta);
    root->max = max(root->child_left->max + root->child_left->add,
        root->child_right->max + root->child_right->add);
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
    while (true) {
        string q;
        cin >> q;
        if (q == "search") {
            int x, y;
            cin >> x >> y;
            cout << query(x, y, root) << endl;
        } else if (q == "set") {
            int x, y;
            cin >> x >> y;
            update(root, x, y);
        } else if (q == "SET") {
            int x, y, val;
            cin >> x >> y >> val;
            update(root, x, y, val);
        } else if (q == "finish") {
            cout << "Goodbye\n";
            break;
        }
    }

    return 0;
}
