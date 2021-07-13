#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning (disable:4996)

int main() {
    int x, c = 0, flag = 0;
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    while (fscanf(fin, "%d", &x) != EOF) {
        if (flag) {
            if (x != c)
                fprintf(fout, "%d ", x);
            c = x;
        }
        else {
            fprintf(fout, "%d ", x);
            flag = 1;
            c = x;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}