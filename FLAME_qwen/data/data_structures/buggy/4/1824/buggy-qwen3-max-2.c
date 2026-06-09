/*********************************************************************
    程序名: C/E6789 - ABCDEFGHIJ
    版权:
    作者:
    日期: 2024-04-14 10:47
    说明: Chinese Cabbage Dog
*********************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8

int f(char x)
{
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
    {
        return 1;
    }
    return 0;
}

char g(char x)
{
    if (x >= 'A' && x <= 'Z')
        return x + 'a' - 'A';
    return x;
}


int cmp(const void *x, const void *y)
{
    return strcmp((char *)x, (char *)y);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main()
{
    freopen("article.txt", "r", stdin);
    char s[1000][15] = {{0}};
    char s1[15] = {0};
    int len = 0;
    int num = 0;
    char c = 0;
    while (scanf("%c", &c) != EOF)
    {
        if (f(c))
        {
            c = g(c);
            s1[len] = c;
            len++;
        }
        else
        {
            if (len == 0)
                continue;
            else
            {
                for (int i = 0; i < len; i++)
                {
                    s[num][i] = s1[i];
                }
                s[num][len] = '\0'; // @@ [Missing null terminator when storing word into s[num], leading to undefined behavior in strcmp/qsort]
                num++;
                len = 0;
            }
        }

    }
    if (len != 0)
    {
        for (int i = 0; i < len; i++)
        {
            s[num][i] = s1[i];
        }
        s[num][len] = '\0'; // @@ [Missing null terminator for the last word if file doesn't end with non-letter character]
        num++;
    }

    qsort(s, num, sizeof(s[0]), cmp);

    char *word;
    int num0 = 0;
    for (int i = 0; i < num; i++)
    {
        if (num0 = 0) // @@ [Assignment instead of comparison; should be '==' not '='. This causes num0 to always be 0, breaking frequency counting logic]
        {
            word = s[i];
            num0++;
        }
        else
        {
            if (strcmp(word, s[i]) == 0)
            {
                num0++;
            }
            else
            {
                printf("%s %d\n", word, num0);
                word = s[i];
                num0 = 1;
            }
        }
    }
    if (num > 0) printf("%s %d\n", word, num0); // @@ [If input file is empty (num==0), word is uninitialized and printing it causes undefined behavior. Also, original prints even when no words exist]
}