#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <math.h>

enum
{
    RAND_RANGE = 1000,
    KBYTE = 1 << 10
};

char *
gen_name(int n, int t, int stream) 
{
    int mlen = (int) ceil(log10(t + 1));
    int len = (int) ceil(log10(n + 1));
    char *res = calloc(KBYTE, sizeof(*res));
    for (int i = 0; i < mlen - len; ++i) {
        strcat(res, "0");
    }
    char *tmp = calloc(len + 1, sizeof(*tmp));
    sprintf(tmp, "%d", n);
    strcat(res, tmp);
    free(tmp);
    if (!stream) {
        strcat(res, ".in"); 
    } else if (stream == 1) {
        strcat(res, ".out");
    } else {
        strcat(res, ".ans");
    }
    return res;
}

char *
get_cmd(char *prog_name, char *exe_name)
{
    char *cmd = calloc(KBYTE, sizeof(*cmd));
    strcpy(cmd, "gcc ");
    strcat(cmd, prog_name);
    strcat(cmd, " -o");
    strcat(cmd, exe_name);
    return cmd;
}

int
main(int argc, char *argv[]) 
{
    int t = strtol(argv[1], NULL, 10);
    char *compile_cmd = get_cmd(argv[2], argv[3]);
    if (system(compile_cmd)) {
        return 0;
    }
    free(compile_cmd);
    compile_cmd = get_cmd(argv[4], argv[5]);
    if (system(compile_cmd)) {
        return 0;
    }
    free(compile_cmd);
    srand(time(NULL));
    for (int k = 1; k <= t; ++k) {
        char *in_name = gen_name(k, t, 0);
        FILE *in_file = fopen(in_name, "w");
        int n = rand() % RAND_RANGE;
        fprintf(in_file, "%d\n", n);
        for (int i = 0; i < n; ++i) {
            fprintf(in_file, "%d ", rand() % RAND_RANGE);
        }
        fprintf(in_file, "\n");
        fclose(in_file);
        char *out_name = gen_name(k, t, 1);
        char *ans_name = gen_name(k, t, 2);
        for (int i = 3; i <= 5; i += 2) {
            char cmd[KBYTE] = {};
            strcpy(cmd, "./");
            strcat(cmd, argv[i]);
            strcat(cmd, " <");
            strcat(cmd, in_name);
            strcat(cmd, " >");
            strcat(cmd, i == 3 ? out_name : ans_name);
            //printf("%s\n", cmd);
            if (system(cmd) && i == 3) {
                printf("Run time error!\n");
                break;
            }
        }
        char diff_cmd[KBYTE];
        strcpy(diff_cmd, "diff ");
        strcat(diff_cmd, out_name);
        strcat(diff_cmd, " ");
        strcat(diff_cmd, ans_name);
        strcat(diff_cmd, " >>diffs");
        if (system(diff_cmd)) {
            printf("Wrong Answer!\n");
        } else {
            printf("Ok\n");
        }
    }
    return 0;
}

