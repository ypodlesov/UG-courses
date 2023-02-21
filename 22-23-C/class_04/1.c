#include <stdio.h>

#define newline printf("\n")
#define ll long long

ll 
fib(int cur_num, int n, ll prev, ll p_prev)
{
    if (cur_num > n) {
        return prev;
    }
    ll res = prev + p_prev;
    return fib(cur_num + 1, n, res, prev);
}

int
main()
{
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    printf("%lld\n", fib(2, n, 1, 0));

    return 0;
}

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34

