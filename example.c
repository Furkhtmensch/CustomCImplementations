#include "CIOTools.h"

int main() {
    char* inp = input();
    print(inp, 0);
    free(inp);
    char newinp[20];
    binput(newinp, 20);
    // as you can see, binput() changes the char container in-place, which means you dont have to get a new pointer for it. still, it will return the pointer in case you might need it :D
    // don't forget that you can disable this feature
    print(newinp);
    float x = 0.4, y = 2.0 / 3, z = 3.12;
    dprint(-3, x, y, z);
    int a = 3, b = 98541, c = 135;
    dprint(3, a, b, c);
    dprint(5, 1, 3, 5, 7, 9);
    print("Let's go %s, only %i days to go before the %.f killers come!", "guys", 10, 3.1416, "\nYeah! Let's do this before Mr. %c shows up!", 'K', NULL);
    return 0;
}
