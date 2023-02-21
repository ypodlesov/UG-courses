#include <stdio.h>
#include <stdlib.h>

void
insertion_sort(int *, int); // прототип функции сортировки

void 
swap(int *, int *); // прототип функции обмена значениями двух переменных

int
main() {
    int n;
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(*arr));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    
    return 0;
}

void
insertion_sort(int *a, int n) {
    for (int i = 1; i < n; ++i) { 
        // i - индекс элемента, который надо вставить в правильное место
        // в уже отсортированный подмассив a[0] ... a[i-1]
        for (int j = i; j > 0 && a[j] <= a[j - 1]; --j) {
            // j - бежит по отсортированному подмассиву и ищет место для 
            // вставки, одновременно сдвигая вправо все элементы
            swap(&a[j], &a[j - 1]); 
        }
    }
}

void
swap(int *a, int *b) { // функция обмена значений двух целых чисел
    int c = *a;
    *a = *b;
    *b = c;
}
