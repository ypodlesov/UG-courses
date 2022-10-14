#include <stdio.h>

int main() 
{
    int a = 7;
    int b = 9;
    printf("b / 7 = %d\ta * b = %d\n", b / 7, a * b);
    printf("%d %d\n", a, b);
    int tmp = ++a;
    printf("%d %d\n", tmp, a);
    tmp = b++;
    printf("%d %d\n", tmp, b);

    return 0;
}
