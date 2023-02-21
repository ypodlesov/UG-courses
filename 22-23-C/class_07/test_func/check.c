#include "bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern error;
#define NULL_POINTER(err) ((err) & (1 << 0) ? 1 : 0)
#define INCORRECT_SIZE(err) ((err) & (1 << 1) ? 1 : 0)

enum
{
    RAND_RANGE = 1000;
};

int 
cmp(const void *a, const void *b) 
{
    int aa = *(int *) a;
    int bb = *(int *) b;
    if (aa > bb) return 1;
    if (aa < bb) return -1;
    return 0;
}

int 
equal_arrs(int *a, int *b, int size) 
{
    for (int i = 0; i < size; ++i) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

void
print(int *a, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int
main(int argc, char *argv[])
{
    int t = strtol(argv[1], NULL, 10);
    while (t--) {
        srand(time(NULL));
        int n = rand() % RAND_RANGE;
        int *a = calloc(n, sizeof(*a));
        int *b = calloc(n, sizeof(*b));
        for (int i = 0; i < n; ++i) {
            a[i] = rand() % RAND_RANGE; 
            b[i] = a[i];
        }
        qsort(a, n, sizeof(*a), cmp);
        error = 0;
        bubble_sort(b, n);
        if (NULL_POINTER(error)) {
            printf("NULL was passed into bubble_sort function\n");
        }
        if (INCORRECT_SIZE(error)) {
            printf("incorrect size of array was passe into bubble_sort function\n");
        }
        if (!equal_arrs(a, b, n)) {
            printf("WA\n");
            print(a, n);
            print(b, n);
        } else {
            printf("OK\n");
        }
        free(a);
        free(b);
    }
    return 0; 
}
