#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <malloc.h>
#include "string_.h"

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

    return beginDestination;
}

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, bool (*f)(int))
{
    while(beginSource < endSource)
    {
        if(f((int)*beginSource))
        {
            *beginDestination++ = *beginSource++;
        }
    }

    return beginSource;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, bool (*f)(int))
{
    while(rbeginSource > rendSource)
    {
        if(f((int)*rbeginSource))
        {
            *beginDestination++ = *rbeginSource--;
        }
    }

    return rbeginSource;
}

void removeNonLetters(char *s) 
{
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, !isSpace);
    *destination = '\0';
}

void removeExtraSpaces(char *s)
{
    bool flag = false;
    char *destination = s;
    while(s != 0)
    {
        if(isSpace(s))
        {
            if(!flag)
            {
                *destination++ = s++;
                flag = true;
            }
            else
            {
                s++;
            }
        }
        else
        {
            *destination++ = s++;
            flag = false;
        }
    }

    *destination = '\0';
}

int getWord(char *beginSearch, WordDescriptor *word)
{
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
    {
        return 0;
    }

    word->end = findSpace(word->begin);
    return 1;
}

int getWordReverse(char *rbegin, char *rend, WordDescriptor *word)
{
    word->begin = findNonSpaceReverse(rbegin, rend);

    if (*word->begin == '\0' && word->begin != rend)
    {
        return 0;
    }

    word->end = findSpace(word->begin);
    return 1;
}

bool isNum(char *sym)
{
    bool answ = false;

    if(sym >= '0' && sym <= '9')
    {
        answ = true;
    }

    return answ;
}

void addNumOfSpaces(char *s)
{
    char *destination = s;
    
    while(s != 0)
    {
        if(isNum(s))
        {
            for(int i = 0; i < (int)*s; i++)
            {
                *destination++ = ' ';
            }
        }
        else
        {
            *destination++ = s++;
        }
    }

    *destination = '\0';
}

void replace(char *source, char *w1, char *w2) 
{
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr, _stringBuffer;
    
    if (w1Size >= w2Size) 
    {
        readPtr = source;
        recPtr = source;
    } 
    else 
    {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }
}

int WordsCmp(WordDescriptor w1, WordDescriptor w2)
{
    int cmp;

    while(w1.begin < w1.end && w2.begin < w2.end)
    {
        cmp = (int)*w1.begin - (int)*w2.begin;

        if(cmp != 0)
        {
            break;
        }
        else
        {
            w1.begin++;
            w2.begin++;
        }
    }

    if(w1.begin == w1.end && w2.begin != w2.end)
    {
        cmp = -1;
    }
    else if(w2.begin == w2.end && w1.begin != w1.end)
    {
        cmp = 1;
    }

    return cmp;
}

bool isAlphabeticalOrder(char *str)
{
    bool answ = true;
    WordDescriptor prev, next;

    if(getWord(str, &prev) != 0)
    {
        while(getWord(prev.end, &next) == 1)
        {
            if(WordsCmp(prev, next) > 0)
            {
                answ = false;
                break;
            }

            prev = next;
        }
    }

    return answ;
}

void getBagOfWords(BagOfWords *bag, char *s)
{
    WordDescriptor word;
    bag->size = 0;

    while(getWord(s, &word) == 1)
    {
        bag->words[bag->size++] = word;
    }
}

void printWord(WordDescriptor w)
{
    while(w.begin < w.end)
    {
        printf("%c", *w.begin);
        w.begin++;
    }
    printf("\n");
}

void PrintWordsBackwards (char *str)
{
    BagOfWords words;
    words.size = 0;

    while(getWord(str, &words.words[words.size]) == 1)
    {
        words.size++;
    }

    for(size_t i = words.size; i > 0; i--)
    {
        printWord(words.words[i - 1]);
    }
}

bool isWordPalindrome (WordDescriptor word)
{
    bool flag = true;
    while(word.begin < word.end)
    {
        if(*word.begin != *(word.end - 1))
        {
            flag = false;
            break;
        }
        else
        {
            word.begin++;
            word.end--;
        }
    }

    return flag;
}

int wordsPalindrome (char *str)
{
    int answ = 0;
    WordDescriptor word;

    while(getWord(str, &word) != 0)
    {
        if(isWordPalindrome(word))
        {
            answ++;
        }
        str = word.end;
    }

    return answ;
}

char *alternatingStringWords (char *s1, char *s2)
{
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2, *output;

    output = malloc(strlen(s1) + strlen(s2) + 1);

    while ((isW1Found = getWord(beginSearch1, &word1)), (isW2Found = getWord(beginSearch2, &word2)), isW1Found || isW2Found) 
    {
        if(isW1Found)
        {
            output = copy(word1.begin, word1.end, output);
            beginSearch1 = word1.end;
            *output++ = ' ';
        }

        if(isW2Found)
        {
            output = copy(word2.begin, word2.end, output);
            beginSearch2 = word2.end;
            *output++ = ' ';
        }
    }

    *output = 0;
    
    return output;
}