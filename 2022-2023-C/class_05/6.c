#include <stdio.h>

int N; // dynmem

int 
sum(int a, int b) // stackmem
{ 
    return a + b;
}

int
main() 
{
    int n;
    scanf("%d", &n);
    int a[n]; // 0 ... N-1
    int *pa = &a[0]; // the same as a
    for (int i = 0; i < n; ++i) {
        scanf("%d", (pa + i));
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", *(pa + i)); // pa + i * 4 - address in bytes
    }
    printf("\n");
    

    return 0;
}

