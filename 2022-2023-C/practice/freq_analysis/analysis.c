#include "analysis.h"


struct Node;

//int strlen(char *word) {
//    int len = 0;
//    if (!word) return 0;
//    while (word[len++] != '\0') {}
//    return len;
//}

struct Node * 
init(char *word) 
{
    if (word == NULL) {
        return NULL;
    }
    struct Node *res = calloc(1, sizeof(*res));
    if (res == NULL) {
        return res;
    }
    res->word = calloc(50, sizeof(*word)); // (*res).word = word
    strcpy(res->word, word);
    if (res->word == NULL) {
        free(res);
        return NULL;
    }
    res->word_count = 1;
    res->left_child = res->right_child = NULL;
}

struct Node * 
search(struct Node *root, char *key) 
{
    if (root == NULL || root->word == NULL) {
        return NULL;
    }
    if (key == NULL) {
        return NULL;
    }
    int res = strcmp(root->word, key);
    if (!res) {
        return root;
    } else if (res < 0) {
        return search(root->right_child, key);
    } else {
        return search(root->left_child, key);
    }
}

struct Node * 
insert(struct Node *root, char *key)
{
    if (root == NULL) {
        printf("1\n");
        return init(key);
    }
    if (key == NULL) {
        printf("2\n");
        return root;
    }
    if (root->word == NULL) {
        printf("3\n");
        root->word = calloc(strlen(key), sizeof(*root->word));
        strcpy(root->word, key);
        return root;
    }
    printf("%s %s\n", root->word, key);
    printf("4\n");
    int res = strcmp(root->word, key);
    if (!res) {
        root->word_count++; 
    } else if (res < 0) {
        root->right_child = insert(root->right_child, key);
    } else {
        root->left_child = insert(root->left_child, key);
    }
    return root;
}

void 
show(struct Node *root) 
{
    if (root == NULL) return;
    show(root->left_child);
    printf("%s %d\n", root->word, root->word_count);
    show(root->right_child);
}


