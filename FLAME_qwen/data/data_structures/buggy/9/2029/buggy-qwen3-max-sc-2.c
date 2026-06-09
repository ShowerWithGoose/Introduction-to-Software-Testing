#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM 100

struct Line
{
    int x, y, z, l;
    struct Line *link;
} Line[NUM], *next;
int Panduan(struct Line L)
{
    if (L.link != NULL)
    {
        N = N + 1; // @@ [Variable 'N' is used before declaration in this scope; although 'N' is declared globally later, recursive function design with global state causes incorrect counting and undefined behavior due to lack of reinitialization per call path]
        Panduan(*(L.link));
    }
    else
    {
        return N; // @@ [Returning value from a function that modifies a global variable leads to inconsistent results; also, the return value is not consistently used since other paths fall through]
    }
    return N; // @@ [Redundant return; control flow already returns in both branches, but more critically, using global 'N' makes recursion stateful and incorrect across multiple calls]
}

int N = 1; // @@ [Global variable 'N' is shared across all recursive calls to 'Panduan', causing incorrect segment counts when multiple chains are evaluated]

int main()
{
    int n, i, j, len[NUM], max = 0, Q, Z;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d %d %d", &Line[i].x, &Line[i].y, &Line[i].z, &Line[i].l);
    }
    for (i = 1; i <= n; i++)
    {
        Line[i].link = NULL; // @@ [Missing initialization of 'link' pointer to NULL; without this, uninitialized pointers may cause undefined behavior when checked in 'Panduan']
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if ((Line[i].z == Line[j].x) && (Line[i].l == Line[j].y))
            {
                Line[i].link = &Line[j];
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        N = 1; // @@ [Resetting global 'N' here is error-prone because recursive calls during 'Panduan(Line[i])' can interfere if interrupted or if stack unwinding doesn't restore state properly; better to use local variables]
        len[i] = Panduan(Line[i]);
    }
    for (i = 1; i <= n; i++)
    {
        if (len[i] > max)
        {
            max = len[i];
            Q = i;
        }
    }
    printf("%d %d %d", len[Q], Line[Q].x, Line[Q].y);
    return 0;
}