#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <malloc.h>
#include "string_.h"

void deleteWord(char *s, WordDescriptor w)
{
    if(*w.end > 0)
    {
        w.end++;
        while(*w.end > 0)
        {
            *w.begin++ = *w.end++;
        }
        
    }
    w.begin = 0;
}

//17
void deletePalindromeWords (char *s)
{
    WordDescriptor word;
    while(getWord(s, &word) == 1)
    {
        if(isWordPalindrome(word))
        {
            deleteWord(s, word);
        }
    }
}

int main()
{
    
}