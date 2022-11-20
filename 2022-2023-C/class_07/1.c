#include <stdio.h>
#include <stdlib.h>

int error;

#define INCORRECT_POINTER(A) ((A) == -1 ? 1 : 0)
#define INCORRECT_FORMAT(A) ((A) == 1 ? 1 : 0)
#define LARGE_NUMBER(A) ((A) == 2 ? 1 : 0)

int 
check_is_digit(char ch) 
{
    if (ch - '0' < 0 || ch - '0' > 9) return 0;
    return 1;
}

int 
convert_str_to_int(char *str) 
{
    if (str == NULL) {
        error = -1;
        exit(1);
    }
    long long res = 0;
    for (int i = (check_is_digit(str[0]) ? 0 : 1); str[i] != '\0'; ++i) {
        if (!check_is_digit(str[i])) {
            error = 1;
            exit(2);
        }
        res = res * 10 + (int) (str[i] - '0');
        if (res != (int) res) {
            error = 2;
            exit(3);
        }
    }
    if (str[0] == '-') res *= -1;
    else if (!check_is_digit(str[0]) && str[0] != '+') {
        error = 1;
        exit(2);
    }
    return (int) res;
}

int
main(int argc, char *argv[]) 
{
    for (int i = 1; i < argc; ++i) {
        error = 0;
        int res = convert_str_to_int(argv[i]);
        if (INCORRECT_POINTER(error)) {
            fprintf(stderr, "error! passed to convert_str_to_int NULL in args\n");
        } else if (INCORRECT_FORMAT(error)) {
            fprintf(stderr, "error! passed to convert_str_to_int not correct string\n");
        } else if (LARGE_NUMBER(error)) {
            fprintf(stderr, "error! passed number to convert_str_to_int is too large\n");
        } else {
            printf("%d\n", res);
        }
    }
}





