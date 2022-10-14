#include <stdio.h>

int
main() 
{

    int a;
    scanf("%d", &a);
    switch (a) { 
        case 4: 
            printf("case 1\n");
            break;
        case 7: 
            printf("case 2\n");
            break;
        case 14: 
            printf("case 3\n");
            break; 
        default: 
            printf("def case\n");
    }

    return 0;
}
