#ifndef
#define CIOTOOLS_H

#include "CIOTools.c"

int nitos(int n, FILE* stream);

int nftos(double n, int t, FILE* stream);

int dprint(int n, ...);

int print(char* first, ...);

char* input();

char* binput(char* buffer, int bufferSize);

#endif
