#ifndef
#define CIOTOOLS_H

int nitos(int n, FILE* stream);

int nftos(double n, int t, FILE* stream);

int dprint(int n, ...);

int print(char* first, ...);

char* input();

char* binput(char* buffer, int bufferSize);

#endif