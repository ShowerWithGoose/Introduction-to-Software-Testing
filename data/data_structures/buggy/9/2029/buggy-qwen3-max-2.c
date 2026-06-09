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
        N = N + 1; // @@ [Variable 'N' is used without being declared in this scope; it's a global variable but modified recursively without proper reinitialization per call]
        Panduan(*(L.link));
    }
    else
    {
        return N; // @@ [Returning 'N' here but the function doesn't consistently return a value in all paths before this point, and 'N' is global causing interference between calls]
    }
    return N; // @@ [Same issue: using global 'N' leads to incorrect counts due to shared state across recursive calls]
}

int N = 1; // @@ [Global variable 'N' causes incorrect behavior because it's shared across all recursive calls to Panduan; each call should have its own counter]

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
        Line[i].link = NULL; // @@ [Missing initialization of link pointers to NULL, leading to undefined behavior when checking L.link != NULL]
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
        N = 1; // @@ [Resetting global 'N' here is error-prone; recursive calls from other iterations may interfere]
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