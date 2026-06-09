#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <memory.h>
#define mian main
typedef long long ll;
typedef unsigned long long ull;
#define forsx(i, a, b) for (int i = (a); i < (b); ++i)
#define forjx(i, a, b) for (int i = (a); i > (b); --i)
#define __MAX_LENGTH__ 50
#define ElementType int
typedef struct node
{
    char word[100];
    int count;
} Node, *wordNode;
ElementType max(ElementType a, ElementType b)
{
    return a > b ? a : b;
}

ElementType min(ElementType a, ElementType b)
{
    return a < b ? a : b;
}
char tmp;
Node wordn[30000];
int cmpfunc(const void *a, const void *b)
{
    return strcmp(((wordNode)a)->word, ((wordNode)b)->word);
}
int main(int argc, const char *argv[])
{
    freopen("article.txt", "r", stdin);
    int num = 0;
    int arr = 0;
    for (int i = 0; i < 30000; ++i)
    {
        memset(wordn[i].word, 0, sizeof(wordn[i].word));
        wordn[i].count = 0;
    }
    while ((tmp = getchar()) != EOF)
    {
        if (isalpha(tmp))
        {
            wordn[num].word[arr] = tolower(tmp);
            ++arr;
        }
        else
        {
            arr = 0;
            num++;
        }
    }
    qsort(wordn, num + 1, sizeof(wordn[0]), cmpfunc);
    for (int i = 0; i < num + 1; ++i)
    {
        if (strlen(wordn[i].word) > 0)
        {
            wordn[i].count = 1;
        }
        else
        {
            wordn[i].count = 0;
        }
    }
    for (int i = 0; i < num; ++i)
    {
        if (strcmp(wordn[i].word, wordn[i + 1].word) == 0)
        {
            wordn[i + 1].count += wordn[i].count;
            wordn[i].count = 0;
        }
    }
    for (int i = 0; i < num + 1; ++i)
    {
        if (wordn[i].count > 0)
        {
            printf("%s %d\n", wordn[i].word, wordn[i].count);
        }
    }
    return 0;
}
