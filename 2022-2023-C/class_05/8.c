#include <stdio.h>
#include <stdlib.h>

int 
cmp(const void *a, const void *b)
{
    int aa = *(int *) a;
    int bb = *(int *) b;
    if (aa > bb) {
        return 1;
    }
    if (aa < bb) {
        return -1;
    }
    return 0;
    

}


int main() 
{
    int n;
    scanf("%d", &n);
    int *a = calloc(n, sizeof(*a));
    for (int i = 0; i < n; ++i )
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(*a), cmp);

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
