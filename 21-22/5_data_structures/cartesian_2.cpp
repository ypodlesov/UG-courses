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
    int max;
    int add;
    node *left, *right;
    node(int val) {
        data = val;
        add = 0;
        max = data;
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

int get_max(node *root) {
    if (root == nullptr) return -INF;
    return root->max + root->add;
}

void update(node *root) {
    if (root == nullptr) return;
    root->size = 1 + get_size(root->left) + get_size(root->right);
    root->max = max(root->data, get_max(root->left), get_max(root->right));
}

void push(node *root) {
    if (root == nullptr) return;
    if (root->left) root->left->add += root->add;
    if (root->right) root->right->add += root->add;
    root->data += root->add;
    root->max += root->add;
    root->add = 0;
}

pair<node*, node*> split_kth(node *root, int k) {
    if (root == nullptr) return {nullptr, nullptr};
    if (get_size(root) <= k) return {root, nullptr};
    if (k == 0) return {nullptr, root};
    push(root);
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
        push(root1);
        root1->right = merge(root1->right, root2);
        update(root1);
        return root1;
    } else {
        push(root2);
        root2->left = merge(root1, root2->left);
        update(root2);
        return root2;
    }
}

node *merge(node *root1, node *root2, node *root3) {
    return merge(merge(root1, root2), root3);
}

int get_kth(node *root, int k) {
    int left_size = get_size(root->left);
    if (k < left_size) return get_kth(root->left, k);
    else if (k == left_size) return root->data;
    else return get_kth(root->right, k - left_size - 1);
}

int query(int l, int r, node *root) {
    auto [res1, tmp] = split_kth(root, l);
    auto [res2, res3] = split_kth(tmp, r - l + 1);
    int ans = res2->max + res2->add;
    root = merge(res1, res2, res3);
    return ans;
}

void update_kth(node *root, int k, int x) {
    int left_size = get_size(root->left);
    if (k < left_size) update_kth(root->left, k, x);
    else if (k == left_size) root->add += x;
    else update_kth(root->right, k - left_size - 1, x);
}



int main() {

    node *root = nullptr;
    int size = 100000;
    for (int i = 1; i < size; ++i) {
        node *newnode = new node(i);
        root = merge(root, newnode);
    }

    // cout << get_kth(root, 0) << endl;
    // cout << root->max << endl;
    // auto [tmp, root2] = split_kth(root, 51000);
    // auto [root0, root1] = split_kth(tmp, 49000);
    // cout << get_max(root1) << endl;
    // root1->add += 780;
    // root = merge(merge(root0, root1), root2);
    // cout << get_max(root) << endl;

    return 0;
}
