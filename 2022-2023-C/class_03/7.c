#include <stdio.h>

int
main() 
{
    for (int i = 1; i <= 100; ++i) {
        if (i % 13) {
            continue;
        }
        printf("%d\n", i);
    }
    return 0;
}
