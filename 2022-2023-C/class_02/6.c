#include <stdio.h>

int main()
{
    int a = 6; // 0110
    int b = 9; // 1001
    printf("%d %d %d %d %d %d\n", a & b, a | b, a ^ b, ~a, a >> 2, a << 3);
    
        
    return 0;
}
