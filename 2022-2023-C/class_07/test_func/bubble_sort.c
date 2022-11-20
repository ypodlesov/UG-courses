#include "bubble_sort.h"

extern int error;

void 
swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void
bubble_sort(int *a, int n)
{
    if (!a) {
        error |= 1;
    } 
    if (n <= 0) {
        error |= 2;
    }
    if (error) {
        return;
    }
    for (int i = 0; i < n; ++i) { 
        for (int j = 1; j < n - i; ++j) {
            if (a[j] < a[j - 1]) {
                swap(&a[j], &a[j - 1]); 
            }
        }
    }
}
