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
        N = N + 1; // @@ [Variable 'N' is used without being declared in this scope; it's a global variable but recursion with global state causes incorrect counting]
        Panduan(*(L.link));
    }
    else
    {
        return N;
    }
    return N;
}

int N = 1; // @@ [Global variable 'N' leads to incorrect recursive counting because it's shared across all calls to Panduan]

int main()
{
    int n, i, j, len[NUM], max = 0, Q, Z;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) // @@ [Array indexing starts at 1, but C arrays are 0-indexed; this skips Line[0] and may access Line[n] which is out of bounds when i == n]
    {
        scanf("%d %d %d %d", &Line[i].x, &Line[i].y, &Line[i].z, &Line[i].l);
    }
    for (i = 1; i <= n; i++) // @@ [Same off-by-one error: should iterate from 0 to n-1]
    {
        for (j = 1; j <= n; j++) // @@ [Same off-by-one error: should iterate from 0 to n-1]
        {
            if ((Line[i].z == Line[j].x) && (Line[i].l == Line[j].y))
            {
                Line[i].link = &Line[j];
            }
        }
    }
    for (i = 1; i <= n; i++) // @@ [Same off-by-one error: should iterate from 0 to n-1]
    {
        N = 1;
        len[i] = Panduan(Line[i]);
    }
    for (i = 1; i <= n; i++) // @@ [Same off-by-one error: should iterate from 0 to n-1]
    {
        if (len[i] > max)
        {
            max = len[i];
            Q = i;
        }
    }
    printf("%d %d %d", len[Q], Line[Q].x, Line[Q].y); // @@ [If no segments form a chain, len[Q] might be uninitialized or based on incorrect indexing]
    return 0;
}