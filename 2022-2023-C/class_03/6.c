#include <stdio.h>

int
main() 
{
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            int res = (i - 1) * 10 + j;
            printf("%d ", res);
            if (res % 7 == 0) {
                break;
            }
        }
        printf("\n");
    }
    
    return 0;
}
