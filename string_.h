#include <stdio.h>
#include <math.h>
#include <stdbool.h>

size_t  strlen1         (char *s);
char*   find            (char *begin, char *end, int ch);
bool    isSpace         (char sym);
char*   findNonSpace    (char *begin);
char*   findSpace       (char *begin);