#include <stdio.h>
#include "analysis.h"

int
main() 
{
    struct Node *tree = NULL;
    char *str = calloc(50, sizeof(*str));
    while (scanf("%s", str) == 1) {
        if (!strcmp(str, "quit")) {
            break;
        }
        tree = insert(tree, str);
    }
    while (scanf("%s", str) == 1) {
        struct Node *res = search(tree, str);
        if (res) {
            printf("%d\n", res->word_count);
        } 
    }




    return 0;
}
