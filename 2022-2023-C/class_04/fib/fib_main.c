#include <stdio.h>
#include "fib_help.h"

extern int n;

int main() {
    scanf("%d", &n);
    printf("%d\n", fib());
    return 0;
}
