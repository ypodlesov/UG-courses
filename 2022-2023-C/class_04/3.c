#include <stdio.h>

void foo(int n) {
    static int cur = 0;
    if (cur > n) return;
    printf("%d\n", cur++);
    foo(n);
}

int main() {
    int n;
    scanf("%d", &n);
    foo(n);
}
