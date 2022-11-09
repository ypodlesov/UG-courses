#include <stdio.h>

int main() {
    int n; // number of elements in array
    scanf("%d", &n);
    int a[n]; // declare an array
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    long long sum = 0; // initialize sum of elements in the array
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    printf("%lld\n", sum);
    return 0;
}
