#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char *word;
    int word_count;
    struct Node * left_child;
    struct Node * right_child;
};

struct Node * init(char *);

struct Node * search(struct Node *, char *);

struct Node * insert(struct Node *, char *);

void show(struct Node *);

