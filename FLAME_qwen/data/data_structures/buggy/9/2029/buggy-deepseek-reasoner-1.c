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
} Line[NUM], *next; // @@ [Error: link pointers are not initialized to NULL; later, Panduan checks L.link != NULL, but uninitialized pointers may cause undefined behavior]

int Panduan(struct Line L)
{
    if (L.link != NULL)
    {
        N = N + 1; // @@ [Error: variable 'N' is used before declaration; N is defined later as a global variable, but its declaration is after this function, so it is not in scope]
        Panduan(*(L.link));
    }
    else
    {
        return N; // @@ [Error: variable 'N' is used before declaration; same reason as above]
    }
    return N; // @@ [Error: variable 'N' is used before declaration; same reason as above]
}

int N = 1;

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
        N = 1;
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