#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

struct node {
    int x, y, size;
    node *left, *right;
    node(int val) {
        x = val;
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
    root->size = 1 + get_size(root->left) + get_size(root->right);
}

bool exists(node *root, int val) {
    if (root == nullptr) return false;
    if (root->x == val) return true;
    if (root->x < val) return exists(root->right, val);
    return exists(root->left, val);
}

pair<node*, node*> split(node *root, int val) {
    if (root == nullptr) return {nullptr, nullptr};
    if (root->x <= val) {
        auto [res1, res2] = split(root->right, val);
        root->right = res1;
        update(root);
        return {root, res2};
    } else {
        auto [res1, res2] = split(root->left, val);
        root->left = res2;
        update(root);
        return {res1, root};
    }
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

node *insert(node *root, int val) {
    if (exists(root, val)) return root;
    auto [res1, res2] = split(root, val);
    node *newnode = new node(val);
    return merge(merge(res1, newnode), res2);
}

node *erase(node *root, int val) {
    if (!exists(root, val)) return root;
    auto [tmp, res2] = split(root, val);
    auto [res1, valnode] = split(tmp, val-1);
    delete valnode;
    return merge(res1, res2);
}

int get_kth(node *root, int k) {
    int left_size = get_size(root->left);
    if (k < left_size) return get_kth(root->left, k);
    else if (k == left_size) return root->x;
    else return get_kth(root->right, k - left_size - 1);
}

int main() {

    node *root = nullptr;
    for (int i = 0; i < 200000; i += 2) {
        root = insert(root, i);
    }
    for (int i = 200000; i >= 0; i -= 4) {
        root = erase(root, i);
    }
    int cnt = 0;
    for (int i = 200000; i >= 0; --i) {
        if (exists(root, i)) ++cnt;
    }
    int s = get_size(root);
    cout << s << endl;
    int sum = 0;
    for (int i = 0; i < s; ++i) {
        sum += get_kth(root, i);
    }

    cout << sum << endl;

    return 0;
}
