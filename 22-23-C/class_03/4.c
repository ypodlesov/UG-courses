#include <stdio.h>

int 
main() 
{
    int t;
    scanf("%d", &t);
    while (--t) { // t = 5, 4, 3, 2, 1, 0
                  // t = 4, 3, 2, 1, 0
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }



    return 0;
}
