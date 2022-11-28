#include <stdio.h>
#include <stdlib.h>

int
inner_product(int *, int *, int);

int **
matrix_mult(int, int, int **, int, int, int **);


int
main(int argc, char *argv[]) 
{
    int m = strtol(argv[1], NULL, 10);
    int n = strtol(argv[2], NULL, 10);
    int k = strtol(argv[3], NULL, 10);
    int **a = calloc(n, sizeof(*a));
    int **b = calloc(n, sizeof(*b));
    for (int i = 0; i < m; ++i) {
        a[i] = calloc(n, sizeof(*a[i]));
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        b[i] = calloc(k, sizeof(*b[i]));
        for (int j = 0; j < k; ++j) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    int **c = matrix_mult(m, n, a, n, k, b);
    if (!c) {
        fprintf(stderr, "error!\n");
        exit(1);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int 
inner_product(int *a, int *b, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }
    return res;
}

int *
get_col(int **a, int j, int m, int n) {
    int *res = calloc(m, sizeof(*res));
    for (int i = 0; i < m; ++i) {
        res[i] = a[i][j];
    }
    return res;
}

int**
matrix_mult(int a_m, int a_n, int **a, int b_m, int b_n, int **b) 
{
    if (a_n != b_n) {
        return NULL;
    }
    int **res = calloc(a_m, sizeof(*res));
    
    for (int i = 0; i < a_m; ++i) {
        res[i] = calloc(b_n, sizeof(*res[i]));
        for (int j = 0; j < b_n; ++j) {
            res[i][j] = inner_product(a[i], get_col(b, j, b_m, b_n), a_n);
        }
    }
    for (int i = 0; i < a_m; ++i) {
        for (int j = 0; j < b_n; ++j) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return res;
}



