#include <stdio.h>
#include <stdlib.h>

#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0) 
// макрос для обработки ошибок


void
bubble_sort(int *, int); // прототип функции сортировки 

void
swap(int *, int *); // прототип функции обмена значений двух переменных

int
main()
{
    int n;
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    if (arr == NULL) {
        handle_error("calloc");        
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}

void
bubble_sort(int *a, int n)
{
    for (int i = 0; i < n; ++i) { 
        // i отвечает за правую границу подмассива в котором переставляем 
        // наибольший элемент на последнюю позицию
        for (int j = 1; j < n - i; ++j) {
            // j бежит пj подмассиву и переставляет больший элемент правее
            if (a[j] < a[j - 1]) {
                // если предыдущий больше текущего переставляем их местами
                swap(&a[j], &a[j - 1]); 
            }
        }
    }
}

void
swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
















