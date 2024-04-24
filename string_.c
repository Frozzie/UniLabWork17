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

char* findNonSpaceReverse(char *rbegin, const char *rend)
{
    char *sym = rbegin;

    while(*sym > *rend)
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

    while(*sym > *rend)
    {
        if (isSpace (*sym))
        {
            break;
        }
        sym--;
    }
    
    return sym;
}

int strcmp(const char *lhs, const char *rhs)
{
    while(*lhs > 0 && *rhs > 0)
    {
        if(*lhs != *rhs)
        {
            break;
        }
        lhs++;
        rhs++;
    }

    return (int)(*lhs - *rhs);
}

char* copy(char *beginSource, const char *endSource, char *beginDestination)
{
    while(beginSource < endSource)
    {
        *beginDestination++ = *beginSource++;
    }

    return beginSource;
}

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int))
{
    while(beginSource < endSource)
    {
        if(f)
        {
            *beginDestination++ = *beginSource++;
        }
    }

    return beginSource;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int))
{
    while(rbeginSource < rendSource)
    {
        if(f)
        {
            *beginDestination++ = *rbeginSource--;
        }
    }

    return rbeginSource;
}