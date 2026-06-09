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
        N = N + 1; // @@ [The variable 'N' is used inside the function 'Panduan' but is not declared in its scope. Although there is a global 'N', the error message suggests the compiler does not recognize it, possibly due to redeclaration or scoping issues. However, the real issue is that the global 'N' is defined after the function 'Panduan', so at the point of use in 'Panduan', 'N' is not yet declared. In C, global variables must be declared before use in functions defined before them.]
        Panduan(*(L.link));
    }
    else
    {
        return N; // @@ [Same issue: 'N' is not in scope here because the global definition comes after this function.]
    }
    return N; // @@ [Same issue: 'N' is not in scope.]
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