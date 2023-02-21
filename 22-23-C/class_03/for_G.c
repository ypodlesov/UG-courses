#include <stdio.h>

enum
{
    HUNDRED = 100
};

int 
main()
{
    long long sum = 0;
    for (int i = 0; i < HUNDRED; ++i) {
        long long tmp;
        scanf("%lld", &tmp);
        sum += tmp;
    }
    printf("%lld\n", sum);

    return 0;
}
