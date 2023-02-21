#include <stdio.h>

int
main() 
{

    int t;
    scanf("%d", &t);
    //do {
      //  printf("%d\n", t);
    //} while (t--); // t = 5, 4, 3, 2, 1, 0
    while(t--) {
        printf("%d\n", t);
    }

    return 0;
}
