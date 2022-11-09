#include <stdio.h>
#include <stdlib.h>

int
main()
{
    int n;
    scanf("%d", &n);
    int *a = calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    int m;
    scanf("%d", &m);
    a = realloc(a, m * sizeof(*a));
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = m - 1; i >= 0; --i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);

    return 0;
}
