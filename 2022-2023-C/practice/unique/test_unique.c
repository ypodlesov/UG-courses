#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "unique.c"

int 
cmp(const void *a, const void *b) 
{
    int aa = *(int *)a;
    int bb = *(int *)b;
    if (aa > bb) return 1;
    if (aa < bb) return -1;
    return 0;
}

int
main(int argc, char *argv[]) 
{

    int n = strtol(argv[1], NULL, 10);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(*a), cmp);
    int new_size = unique(a, n);
    printf("%d\n", new_size);
    for (int i = 0; i < new_size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
