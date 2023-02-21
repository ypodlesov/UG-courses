#include <stdio.h>

int main()
{
    int a = 5;
    printf("%d ", a);
    a += 4;
    printf("%d ", a);
    a /= 2;
    printf("%d ", a);
    a <<= 2;
    printf("%d ", a);
    a ^= 5; 
    printf("%d\n", a);
    return 0;
}
