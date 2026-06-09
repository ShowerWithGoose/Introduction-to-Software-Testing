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
        N = N + 1; // @@ [Variable 'N' is used without being declared in this scope; it's a global variable but recursive function should avoid relying on global state for counting]
        Panduan(*(L.link));
    }
    else
    {
        return N; // @@ [Returning 'N' which is a global variable leads to incorrect behavior in recursion because multiple calls interfere with each other]
    }
    return N; // @@ [Same issue: using global 'N' makes the function non-reentrant and logic incorrect for counting chain length]
}

int N = 1; // @@ [Global variable 'N' causes incorrect counting in recursive calls since it's shared across all invocations of Panduan]

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
                Line[i].link = &Line[j]; // @@ [This overwrites 'link' if multiple matches exist; however, problem states no three segments share an endpoint, so at most one match—this may be acceptable, but loop continues unnecessarily]
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        N = 1; // @@ [Resetting global 'N' before each call—fragile design, but might work if no concurrency; however, recursion in Panduan modifies global N during execution, leading to race-like logic errors]
        len[i] = Panduan(Line[i]); // @@ [Passing struct by value causes slicing and breaks pointer linkage; 'L.link' inside Panduan points to original array, but copying the struct means the recursive call uses a copy, not the original node—this breaks the chain traversal]
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