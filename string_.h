#include <stdio.h>
#include <math.h>
#include <stdbool.h>

size_t  strlen1             (char *s);
char*   find                (char *begin, char *end, int ch);
bool    isSpace             (char sym);
char*   findNonSpace        (char *begin);
char*   findSpace           (char *begin);
char*   findNonSpaceReverse (char *rbegin, const char *rend);
char*   findSpaceReverse    (char *rbegin, const char *rend);
int     strcmp              (const char *lhs, const char *rhs);
char*   copy                (char *beginSource, const char *endSource, char *beginDestination);
char*   copyIf              (char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));
char*   copyIfReverse       (char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));