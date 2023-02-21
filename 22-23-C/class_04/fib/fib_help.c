#include "fib_help.h"

int fib(void) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int prev = 0, cur = 1;
    for (int i = 2; i <= n; ++i) {
        int tmp = cur;
        cur += prev;
        prev = tmp;
    }
    return cur;
}
