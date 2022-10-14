#include <stdio.h>

int 
main()
{
    int n;
    scanf("%d", &n);
    long long cur = 1, prev = 1;
    int i = 2;
    while (i < n) {
        int tmp = cur;
        cur = cur + prev;
        prev = tmp;
        ++i;
    }
    printf("%lld\n", cur);
// 0 1 1 2 3 5
    return 0;
}
