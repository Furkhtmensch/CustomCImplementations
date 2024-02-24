#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int nitos(int n, FILE* stream) {
    if (n == 0) {
        putc(48, stream);
    }
    int size = 1;
    int m = n;
    while (m > 0) {
        m = m / 10;
        size = size * 10;
    }
    while (size >= 10) {
        size = size / 10;
        putc(((n / size) % 10) + 48, stream);
    }
    return 0;
}

int nftos(double n, int t, FILE* stream) {
    int m = n;
    nitos(m, stdout);
    if (t == 0) {
        return 0;
    }
    putc(46, stream);
    while (t > 0) {
        n = (n - m);
        n = n * 10;
        m = n;
        putc(m + 48, stream);
        t--;
    }
    return 0;
}

int nprint(char* first, ...) {
    va_list arguments;
    va_start(arguments, first);
    int nextargs = 0;
    char* argument = first;
    while (argument != NULL) {
        int i = 0;
        while (argument[i]) {
            if (argument[i] == '%') {
                i++;
                switch (argument[i]) {
                    case 'c': {
                        putc(va_arg(arguments, int), stdout);
                        break;
                    }
                    case 'i': {
                        nitos(va_arg(arguments, int), stdout);
                        break;
                    }
                    case 's': {
                        char* ptr = va_arg(arguments, char*);
                        int j = 0;
                        while (ptr[j]) {
                            putc(ptr[j], stdout);
                            j++;
                        }
                        break;
                    }
                    case '.': {
                        float temp = va_arg(arguments, double);
                        if (argument[i + 1]) {
                            i += 1;
                        } else {
                            nprint("\nERROR! Following a '.' (for floating point representation) the must be the number of decimal places, ending the number with an 'f'! (the limit for them is 255!) \n", NULL);
                            return 3;
                        }
                        if (argument[i] == 'f') {
                            nftos(temp, 2, stdout);
                            break;
                        }
                        int c = 0;
                        int flag = 2;
                        while (argument[i] && (argument[i] >= 48 && argument[i] <= 57 || argument[i] == 102)) {
                            if (argument[i] == 102) {
                                flag = 0;
                                break;
                            }
                            c += 10*c + argument[i] - 48;
                            if (c > 256) {
                                nprint("\nERROR! The maximum number of decimal places is 255! (also, just in case, don't forget to follow the number of decimal places with an 'f') \n", NULL);
                                return 999;
                            }
                            i++;
                        }
                        if (flag) {
                            nprint("\nERROR! You must follow then number of decimal places with an 'f'! \n", NULL);
                            return 3;
                        }
                        nftos(temp, c, stdout);
                        break;
                    }
                    case 'f': {
                        float temp = va_arg(arguments, double);
                        nftos(temp, 2, stdout);
                    }
                    default: {
                        putc(argument[i - 1], stdout);
                        putc(argument[i], stdout);
                        break;
                    }
                }
                i++;
            } else {
                putc(argument[i], stdout);
                i++;
            }
        }
        putc(' ', stdout);
        argument = va_arg(arguments, char*);
    }
    va_end(arguments);
    putc(10, stdout);
    return 0;
}


/*

Example of usage:

*/

/*

int main() {
    nprint("Hi there, %c' Great %s! \n", 'O', "Miquella!", "There you go: %.13f! \n", 3.031234, NULL);
    return 0;
}

*/

/*

The function call must end in NULL (as in last argument) or else it won't work!
%<char> will work for c (char), s (string) and i (integers ONLY, which means that if you use float then it will not be represented properly) 
If you use any other character then it will print the whole %<char>
Use at your own caution (although I don't think this will ever be able to cause any issues)
That's all. Enjoy a version of printf which takes more than one string! (Not complete yet, I have yet to implement the rest of the %<char>)

*/
