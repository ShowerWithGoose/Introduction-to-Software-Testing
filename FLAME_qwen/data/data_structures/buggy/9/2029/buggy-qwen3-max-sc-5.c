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
        N = N + 1; // @@ [Variable 'N' is used without being declared in this scope; it's a global variable but modified inside a recursive function which may lead to incorrect counting due to shared state across calls]
        Panduan(*(L.link));
    }
    else
    {
        return N; // @@ [Returning 'N' here but the function doesn't consistently return a value in all paths before this point, and 'N' is global so its value is corrupted by other calls]
    }
    return N; // @@ [Same issue: using global 'N' makes recursion stateful and incorrect for multiple chains]
}

int N = 1; // @@ [Global variable 'N' causes incorrect behavior in recursive function 'Panduan' because it's shared across all recursive calls and iterations]

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
                Line[i].link = &Line[j]; // @@ [Overwrites 'link' if multiple matches exist; should break after first match or ensure only one successor per segment as per problem constraints]
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        N = 1; // @@ [Resetting global 'N' before each call, but recursive calls during Panduan() will interfere with each other if called again before completion]
        len[i] = Panduan(Line[i]); // @@ [Passing struct by value causes slicing and breaks pointer linkage; should pass by pointer instead]
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