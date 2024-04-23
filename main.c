#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "string_.h"

char* findNonSpaceReverse(char *rbegin, const char *rend)
{
    char *sym = rbegin;

    while(*sym > 0)
    {
        if (!isSpace (*sym))
        {
            break;
        }
        sym--;
    }
    
    return sym;
}

char* findSpaceReverse(char *rbegin, const char *rend)
{
    char *sym = rbegin;

    while(*sym > 0)
    {
        if (isSpace (*sym))
        {
            break;
        }
        sym--;
    }
    
    return sym;
}


int main()
{
    char s[10];
    char character;

    for(int i = 0; i < 10; i++)
    {
        scanf("%c", &character);
        s[i] = character;
    }
    
}