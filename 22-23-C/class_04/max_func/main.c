#include <stdio.h>
#include "help.h"

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("max(a, b) = %d\n", max(a, b));
}

