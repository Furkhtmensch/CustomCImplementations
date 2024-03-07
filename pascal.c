#include <stdio.h>
#include <stdlib.h>

void buildPascal(unsigned long** result, int n, int k) {
    for (int i = 0; i < k; i++) {
        result[k][i] += result[k - 1][i];
        result[k][i + 1] += result[k - 1][i];
    }
    if (k < n - 1) {
        buildPascal(result, n, k + 1);
    }
    return;
}

unsigned long** initPascal(int n) {
    unsigned long** result;
    result = (unsigned long**)malloc(n*sizeof(unsigned long*));
    int mem = 1;
    for (int i = 0; i < n; i++) {
        result[i] = (unsigned long*)malloc(mem*sizeof(unsigned long));
        for (int j = 0; j < mem; j++) {
            result[i][j] = 0;
        }
        mem++;
    }
    result[0][0] = 1;
    if (n > 0) {
        buildPascal(result, n, 1);
    }
    return result;
}

void printPascal(int n, int yoffset, int xoffset, int yoptions) {
    if (yoptions < 2) {
        for (int i = 0; i < yoffset; i++) {
            printf("\n");
        }
    }
    int mem = 1;
    unsigned long** triangle = initPascal(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - mem + xoffset; j++) {
            printf(" ");
        }
        for (int j = 0; j < mem; j++) {
            printf("%u ", triangle[i][j]);
        }
        printf("\n");
        mem++;
    }
    if (yoptions == 1) {
        for (int i = 0; i < yoffset; i++) {
            printf("\n");
        }
    }
    free(triangle);
    return;
}

/*
int main() {
    printPascal(50, 4, 10, 1);
    return 0;    
}
*/
