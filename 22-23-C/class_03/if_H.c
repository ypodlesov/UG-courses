#include <stdio.h>
#include <stdlib.h>

int 
main() 
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (abs(x2 - x1) <= 1 && abs(y2 - y1) <= 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }



    return 0;
}
