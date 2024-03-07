#include <stdio.h>
#include <stdlib.h>

void buildPascal(int** result, int n, int k) {
    for (int i = 0; i < k; i++) {
        result[k][i] += result[k - 1][i];
        result[k][i + 1] += result[k - 1][i];
    }
    if (k < n - 1) {
        buildPascal(result, n, k + 1);
    }
    return;
}

int** initPascal(int n) {
    int** result;
    result = (int**)malloc(n*sizeof(int*));
    int mem = 1;
    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(mem*sizeof(int));
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
    int** triangle = initPascal(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - mem + xoffset; j++) {
            printf(" ");
        }
        for (int j = 0; j < mem; j++) {
            printf("%d ", triangle[i][j]);
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
    printPascal(5, 4, 10, 1);
    return 0;    
}
*/