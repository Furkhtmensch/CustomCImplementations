#include <stdarg.h>
#include <stdio.h>
#include "CIOTools.h"

char* readline(FILE* stream) {
    int maxSize = 100;
    char* pointer;
    pointer = (char*) malloc(maxSize*sizeof(char));
    char last = 1;
    int i = 0;
    while (last != 0 && last != 10 || last > 255) {
        last = getc(stream);
        pointer[i] = last;
        i++;
        if (i >= maxSize) {
            maxSize += 100;
            pointer = realloc(pointer, maxSize*sizeof(char));
        }
    }
    if (pointer[i - 1] == 10) {
        pointer[i - 1] = 0;
    }
    pointer = realloc(pointer, i*sizeof(char));
    return pointer;
}

int writelines(FILE* stream, char* buffer, ...) {
    va_list arguments;
    va_start(arguments, buffer);
    while (buffer != NULL) {
        int i = 0;
        while (buffer[i] != 0) {
            putc(buffer[i], stream);
            i++;
        }
        if (buffer[i - 1] != 10) {
            putc(10, stream);
        }
        buffer = va_arg(arguments, char*);
    }
    return 0;
}



int main() {
    FILE* stream = fopen("text.txt", "a+");
    char* info1 = readline(stream);
    char* info2 = readline(stream);
    print(info1, "\n", info2, 0);
    writelines(stream, info1, info2, 0);
    free(info1);
    free(info2);
    fclose(stream);
    return 0;
}


