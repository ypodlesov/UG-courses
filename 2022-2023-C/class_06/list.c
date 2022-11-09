#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node * 
search(Node *root, int key) 
{
    if (root == NULL){
        return NULL;
    }
    if (root->key == key) {
        return root;
    } else if (root->key > key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}
Node *
insert(Node *root, int key)
{
    if (root == NULL){
        root = malloc(sizeof(Node));
        root->key = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (root->key > key) {
        root->left = insert(root->left, key);
        return root;
    } else if (root->key < key) {
        root->right = insert(root->right, key);
        return root;
    }
}

void 
show(Node *root) 
{
    if (!root) {
        return;
    }
    show(root->left);
    printf("%d ", root->key);
    show(root->right);
}

int main() 
{
    int n;
    scanf("%d", &n);
    Node *root = NULL;
    for (int i = 0; i < n; ++i) {
        int key;
        scanf("%d", &key);
        if (search(root, key)) {
            continue;
        }
        root = insert(root, key);
    }
    show(root);
    

    return 0;
}
