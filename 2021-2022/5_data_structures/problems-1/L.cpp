#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

struct node {
    int data;
    int y;
    int size;
    node *left, *right;
    node(int val) {
        data = val;
        y = rand();
        size = 1;
        left = right = nullptr;
    }
    ~node() {
        if (left != nullptr) delete left;
        if (right != nullptr) delete right;
    }
};

int get_size(node *root) {
    if (root == nullptr) return 0;
    return root->size;
}

void update(node *root) {
    if (root == nullptr) return;
    root->size = 1 + get_size(root->left) + get_size(root->right);
}

pair<node*, node*> split_kth(node *root, int k) {
    if (root == nullptr) return {nullptr, nullptr};
    if (get_size(root) <= k) return {root, nullptr};
    if (k == 0) return {nullptr, root};
    int left_size = get_size(root->left);
    if (left_size >= k) {
        auto [res1, res2] = split_kth(root->left, k);
        root->left = res2;
        update(root);
        return {res1, root};
    } else {
        auto [res1, res2] = split_kth(root->right, k - left_size - 1);
        root->right = res1;
        update(root);
        return {root, res2};
    }
}

node * merge(node *root1, node *root2) {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;
    if (root1->y < root2->y) {
        root1->right = merge(root1->right, root2);
        update(root1);
        return root1;
    } else {
        root2->left = merge(root1, root2->left);
        update(root2);
        return root2;
    }
}

int get_kth(node *root, int k) {
    int left_size = get_size(root->left);
    if (k < left_size) return get_kth(root->left, k);
    else if (k == left_size) return root->data;
    else return get_kth(root->right, k - left_size - 1);
}


int main() {

    node *root = nullptr;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        node *newnode = new node(i);
        root = merge(root, newnode);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto [res1, res2] = split_kth(root, l - 1);
        auto [res3, res4] = split_kth(res2, r - l + 1);
        root = merge(merge(res3, res1), res4);
    }
    for (int i = 0; i < n; ++i) cout << get_kth(root, i) << ' ';
    cout << endl;

    return 0;
}
