#include <stdio.h>

#define forn(i, N) for (int (i) = 0; (i) < (N); ++(i))

int main() {

    forn(i, 10) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
