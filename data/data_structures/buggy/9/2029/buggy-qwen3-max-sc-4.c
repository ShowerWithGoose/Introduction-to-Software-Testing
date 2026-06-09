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
        N = N + 1; // @@ [Variable 'N' is used without being declared in this scope; also, recursion modifies global 'N' incorrectly]
        Panduan(*(L.link));
    }
    else
    {
        return N; // @@ [Variable 'N' is not declared in this function's scope; relies on global but logic is flawed due to shared state]
    }
    return N; // @@ [Same issue: 'N' is global but recursive calls interfere with each other due to shared state]
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
        Line[i].link = NULL; // @@ [Missing initialization of link pointer; may cause undefined behavior when checking L.link]
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
        len[i] = Panduan(Line[i]); // @@ [Recursive function uses and modifies global 'N', causing incorrect counts when multiple chains are evaluated]
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