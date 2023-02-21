#include <stdio.h>

int 
main() 
{
    //for (int i = 1; i <= 100; ++i) {
      //  if (!(i & 1)) {
        //    printf("%d ", i);
        //}
    //}
    //printf("\n");
    
    for (int i = 1, j = 2; i <= 100 && j <= 10; i += 4, j++) {
        printf("%d %d\n", i, j);
    }
    //printf("\n");

    return 0;
}
