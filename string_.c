#include <stdio.h>
#include <math.h>
#include <stdbool.h>

size_t strlen1(char *s)
{
    char *end = s;

    while (*end != '\0')
    {
        end++;
    }
    
    return end - s;
}

char* find(char *begin, char *end, int ch)
{
    while(begin != end && *begin != ch)
    {
        begin++;
    }

    return begin;
}

bool isSpace(char sym)
{
    bool answ = false;

    if(sym >= '0' && sym <= '9')
    {
        answ = true;
    }
    else if(sym >= 'A' && sym <= 'Z')
    {
        answ = true;
    }
    else if(sym >= 'a' && sym <= 'z')
    {
        answ = true;
    }

    return answ;
}

char* findNonSpace (char *begin)
{
    char *sym = begin;

    while(*sym > 0)
    {
        if (!isSpace (*sym))
        {
            break;
        }
        sym++;
    }
    
    return sym;
}

char* findSpace (char *begin)
{
    char *sym = begin;

    while(*sym > 0)
    {
        if (isSpace (*sym))
        {
            break;
        }
        
        sym++;
    }
    
    return sym;
}