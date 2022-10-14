#include <stdio.h>

int main() {

    char c;
    scanf("%c", &c);
    if (c - '0' > 3) {
        printf("Good\n");
    } else {
        printf("Not good\n");
    }

    return 0;
}
