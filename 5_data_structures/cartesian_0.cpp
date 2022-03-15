#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

struct node {
    int x, y;
    node *left, *right;
    node(int val) {
        x = val;
        y = rand();
        left = right = nullptr;
    }
};

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
        return {root, res2};
    } else {
        auto [res1, res2] = split(root->left, val);
        root->left = res2;
        return {res1, root};
    }
}

node *merge(node *root1, node *root2) {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;
    if (root1->y < root2->y) {
        root1->right = merge(root1->right, root2);
        return root1;
    } else {
        root2->left = merge(root1, root2->left);
        return root2;
    }
}

node *insert(node *root, int val) {
    if (exists(root, val)) return root;
    auto [res1, res2] = split(root, val);
    node *newnode = new node(val);
    root = merge(res1, newnode);
    return merge(root, res2);
}

node *erase(node *root, int val) {
    if (!exists(root, val)) return root;
    auto [tmp, res2] = split(root, val);
    auto [res1, valnode] = split(tmp, val-1);
    return merge(res1, res2);
}

int main() {



    return 0;
}
