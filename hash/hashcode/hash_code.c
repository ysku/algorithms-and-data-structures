#include <string.h>
#include "hash_code.h"

int hash_code(char s[]) {
    int n = strlen(s);
    int h = 0;
    for (int i = 0; i < n; i++) {
        h = 31 * h + s[i];
    }
    return h;
}
