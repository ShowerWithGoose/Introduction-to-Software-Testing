//使用指针数组版
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxlen 100

typedef struct word
{
    char w[maxlen];
    int num;
} word;

int structcmp(const void *a, const void *b)
{
    const word *aa = *(word **)a;
    const word *bb = *(word **)b;
    for (int i = 0; i < maxlen; i++)
    {
        if (aa->w[i] < bb->w[i])
        {
            return -1;
        }
        if (aa->w[i] > bb->w[i])
        {
            return 1;
        }
    }
}

int struct_diccmp(const void *a, const void *b)
{
    const word *aa = *(word **)a;
    const word *bb = *(word **)b;
    int re=strcmp(aa->w,bb->w);
    if (re<0)
    {
        return -1;
    }
    return 1;
}

int fgetword(FILE *a, char *s)
{
    memset(s, 0, maxlen * sizeof(char));
    char c;
    int n = 0;
    while ((c = fgetc(a)) != EOF)
    {
        if (c && isalpha(c) != 0)
        {
            break;
        }
    }
    if (c == EOF)
    {
        return EOF;
    }
    s[0] = tolower(c);
    n = 1;
    while ((c = fgetc(a)) != EOF)
    {
        if (c && isalpha(c) != 0)
        {
            s[n] = tolower(c);
            n++;
        }
        else
        {
            return n;
        }
    }
}

int main()
{
    word *wl[8192] = {NULL};
    FILE *a, *b;
    if ((a = fopen("article.txt", "r+")) == NULL)
    {
        perror("open article.txt err");
        return 0;
    }
    char in[maxlen] = {0};
    int n = 0, fl = 1;
    while (fgetword(a, in) != EOF)
    {
        //词处理
        fl = 1;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(wl[i]->w, in) == 0)
            {
                wl[i]->num++;
                fl = 0;
                break;
            }
        }
        if (fl)
        {
            wl[n] = (word *)malloc(sizeof(word));
            strcpy(wl[n]->w, in);
            wl[n]->num = 1;
            n++;
        }
    }
    qsort(wl, n, sizeof(word *), struct_diccmp);
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", wl[i]->w, wl[i]->num);
    }
}
