#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define check(VAR, CONV) printf("check:" #VAR "=%" #CONV "\n", VAR)
typedef long long ll;
typedef double db;
typedef struct term_
{
    int index;
    int power;
    struct term_ *lower;
} term;
int len = 0, k;
term terms[1000];
void add(int index, int power)
{
    if (len == 0)
    {
        terms[0].index = index;
        terms[0].power = power;
        len++;
    }
    else
    {
        for (k = 0; k < len; k++)
        {
            if (terms[k].power == power)
            {
                terms[k].index += index;
                break;
            }
        }
        if (k == len)
        {
            terms[len].index = index;
            terms[len].power = power;
            len++;
        }
    }
}
int Cmp(const void *pa, const void *pb)
{
    int a = ((term *)pa)->power;
    int b = ((term *)pb)->power;
    if (a < b)
        return 1;
    else
        return -1;
}
int main()
{
    int i, j;
    char temp;
    int aindex[100], apower[100], bindex[100], bpower[100], alen = 0, blen = 0;

    while (scanf("%d%d%c", &aindex[alen], &apower[alen], &temp))
    {
        alen++;
        if (temp == '\n')
            break;
    }
    while (scanf("%d%d", &bindex[blen], &bpower[blen]) != EOF)
    {
        blen++;
    }
    // for (i = 0; i < alen; i++)
    // {
    //     printf("%d %d ", aindex[i], apower[i]);
    // }
    // puts("");
    // for (i = 0; i < alen; i++)
    // {
    //     printf("%d %d ", bindex[i], bpower[i]);
    // }
    // puts("");
    for (i = 0; i < alen; i++)
        for (j = 0; j < blen; j++)
        {
            add(aindex[i] * bindex[j], apower[i] + bpower[j]);
        }
    qsort(terms, len, sizeof(term), Cmp);
    for (k = 0; k < len; k++)
    {
        printf("%d %d ", terms[k].index, terms[k].power);
    }

    return 0;
}
