#include <stdio.h>
#include <stdlib.h>


int 
main()
{
    char *str = calloc(100, sizeof(*str));
    scanf("%s", str);
    printf("%s\n", str); 
    // ' ' '\n' 
    // strlen(char *str)
    // strcpy(char *dst, char *src)
    // strncpy(char *dst, char *src, int n)
    // strcmp(char *str1, char *str2)
    // strstr(char *str, char *pattern)


    return 0;
}
