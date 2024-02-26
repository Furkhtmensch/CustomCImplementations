#ifndef CIOTOOLS_H
#define CIOTOOLS_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int nitos(int n, FILE* stream);

int nftos(double n, int t, FILE* stream);

int dprint(int n, ...);

int print(char* first, ...);

char* input();

char* binput(char* buffer, int bufferSize);

int nstoi(char* s);

#endif
