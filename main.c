#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <malloc.h>
#include "string_.h"


void reverseWordOrder (char *str)
{
    char *buff = malloc(strlen(str) + 1), str_end;
    WordDescriptor word;
    str_end = buff + strlen(str);
    
    char *src = str;
    char *dest = buff;
    
    while(*src != 0)
    {
        *dest++ = *src++;
    }

    while(getWordReverse(str_end, buff, &word))
    {
        str = copy(word.begin, word.end, str);
    }

    free(buff);
}

bool findSymInWord (char s, WordDescriptor word)
{
    bool flag = false;
    while(word.begin < word.end)
    {
        if(word.begin == s)
        {
            flag = true;
            break;
        }

        word.begin++;
    }

    return flag;
}

void printWordBeforeFirstWordWithA (char *s)
{
    WordDescriptor prev_word, cur_word;
    bool flag = false, first = true;

    while(getWord(s, &cur_word) != 0)
    {
        flag = findSymInWord('a', cur_word) || findSymInWord('A', cur_word);

        if(flag)
        {
            if(!first)
            {
                printWord(prev_word);
            }
            break;
        }

        prev_word = cur_word;

        if(first)
        {
            first = false;
        }

        s = cur_word.end;
    }
}

bool wordCmp (WordDescriptor word1, WordDescriptor word2)
{
    bool flag;

    while(word1.begin < word1.end && word2.begin < word2.end)
    {
        if(*word1.begin == *word2.begin)
        {
            word1.begin++;
            word2.begin++;
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }

    return flag;
}

void findWordInOtherString (char *s1, char *s2)
{
    WordDescriptor word1, word2, mem;
    char s1Start = *s1, s2Start = *s2;
    BagOfWords bag;
    bool flag = false;

    getBagOfWords(&bag, s2);

    while (getWord(s1Start, &word1) == 1)
    {
        for (size_t i = 0; i < bag.size; i++)
        {
            if(wordCmp(word1, bag.words[i]))
            {
                mem = word1;
                flag = true;
            }
        }
    }

    if(flag)
    {
        printWord(mem);
    }
}

// 13
bool FindSameWords (char *s1, char *s2)
{
    WordDescriptor word1, word2;
    char s1Start = *s1, s2Start = *s2;
    BagOfWords bag;
    bool flag = false;

    getBagOfWords(&bag, s2);

    while (getWord(s1Start, &word1) == 1)
    {
        for (size_t i = 0; i < bag.size; i++)
        {
            if(wordCmp(word1, bag.words[i]))
            {
                flag = true;
                break;
            }
        }
    }

    return flag;
}

void getAllUniqueSortedLetters (WordDescriptor *w)
{
    int count = 1;
    char symMem = *w->begin;
    char *wBegin = w->begin,  *wEnd = w->end;
    char mem[w->end - w->begin];
    bool flag;

    mem[0] = symMem;

    while(wBegin < wEnd)
    {
        flag = true;

        for(int i = 0; i < count; i++)
        {
            if(wBegin == mem[i])
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            mem[count++] = *wBegin++;
        }
    }

    copy(&mem[0], &mem[count], w->begin);

    w->end = w->begin + count;
}

void FindSameLettersInWord (char *s)
{
    WordDescriptor word1, word2, mem;
    char sStart = *s;
    BagOfWords bag;
    bool flag = false;
    getBagOfWords(&bag, s);

    while (getWord(sStart, &word1) == 1)
    {
        for (size_t i = 0; i < bag.size; i++)
        {
            if(wordCmp(word1, bag.words[i]))
            {
                mem = word1;
                flag = true;
            }
        }
    }

    if(flag)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

int main()
{
    
}