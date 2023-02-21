#include <stdio.h>

int 
main() 
{

    int a, b;
    a = 3, b = 0;
    if (a || b++) {
        printf("Cond 1: %d %d\n", a, b);
    } 
    printf("after: %d %d\n", a, b);

    return 0;
}
