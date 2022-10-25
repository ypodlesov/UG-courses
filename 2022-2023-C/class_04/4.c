#include <stdio.h>

void print(int n) {
    if (n < 0) {
        n *= -1;
        printf("-");
    }
    if (n / 10) {
        print(n / 10);
    } 
    printf("%c ", n % 10 + '0');
}

int main() {
    int n;
    scanf("%d", &n);
    print(n);
    printf("\n");
    return 0;
}
