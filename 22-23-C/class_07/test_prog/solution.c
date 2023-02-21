#include <stdio.h>
#include <stdlib.h>

void 
swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void
bubble_sort(int *a, int n)
{
    for (int i = 0; i < n; ++i) { 
        for (int j = 1; j < n - i; ++j) {
            if (a[j] < a[j - 1]) {
                swap(&a[j], &a[j - 1]); 
            }
        }
    }
}

int
main() 
{
    int n;
    scanf("%d", &n);
    int *a = calloc(n, sizeof(*a));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    bubble_sort(a, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

