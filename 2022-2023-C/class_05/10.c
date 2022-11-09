#include <stdio.h>
#include <stdlib.h>

void 
swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int
main()
{

    int n;
    scanf("%d", &n);
    int *a = calloc(n, sizeof(*a));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i * n + j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(&a[i * n + j], &a[j * n + i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[i * n + j]);
        }
        printf("\n");
    }

    return 0;
}
