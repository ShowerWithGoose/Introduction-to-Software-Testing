#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int coeffi;
    int exp;
} Term;

Term list_p[20000], list_q[20000], list_new[40000000];
int pCnt, qCnt, newCnt;
char input[2000000];

void read();
int cmp(const void *p, const void *q);

int main()
{
    read();
    for (int i = 1; i <= pCnt; i++)
    {
        for (int j = 1; j <= qCnt; j++)
        {
            list_new[++newCnt].coeffi = list_p[i].coeffi * list_q[j].coeffi;
            list_new[newCnt].exp = list_p[i].exp + list_q[j].exp;
        }
    }
    qsort(list_new + 1, newCnt, sizeof(Term), cmp);
    list_new[newCnt + 1].exp = -1;
    for (int i = 1; i <= newCnt; i++)
    {
        if (list_new[i].exp == list_new[i + 1].exp)
        {
            int j = 1;
            while (list_new[i + j].exp == list_new[i].exp)
            {
                list_new[i].coeffi += list_new[i + j].coeffi;
                j++;
            }
            printf("%d %d ", list_new[i].coeffi, list_new[i].exp);
            i += j - 1;
            continue;
        }
        printf("%d %d ", list_new[i].coeffi, list_new[i].exp);
    }

    return 0;
}

void read()
{
    fgets(input, 2000000, stdin);
    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++)
    {
        list_p[++pCnt].coeffi = atoi(input + i);
        while (input[i++] != ' ')
            ;
        list_p[pCnt].exp = atoi(input + i);
        while (input[i++] != ' ' && input[i] != '\n')
            ;
        i--;
    }
    fgets(input, 2000, stdin);
    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++)
    {
        list_q[++qCnt].coeffi = atoi(input + i);
        while (input[i++] != ' ')
            ;
        list_q[qCnt].exp = atoi(input + i);
        while (input[i++] != ' ' && input[i] != '\n')
            ;
        i--;
    }
}

int cmp(const void *p, const void *q)
{
    Term *a = (Term *)p;
    Term *b = (Term *)q;
    if (a->exp > b->exp)
        return -1;
    return 1;
}
