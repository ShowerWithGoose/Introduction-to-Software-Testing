#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

int vertex[110][110], Isvertex[110], Queue[110];
void DFS(int v, int t);
void beforeD(int v);
void BFS(int v, int t);
void beforeB(int v);

int main()
{
    int i, j, n, dd, side;
    scanf("%d%d", &dd, &side);
    for (n = 0; n < side; n++)
    {
        scanf("%d %d", &i, &j);
        vertex[i][j] = vertex[j][i] = 1;
    }

    beforeD(dd);
    memset(Isvertex, 0, sizeof(Isvertex));
    beforeB(dd);
    int d;
    scanf("%d", &d);
    for (i = 0; i < dd; i++)
        vertex[i][d] = vertex[d][i] = 0;

    memset(Isvertex, 0, sizeof(Isvertex));
    beforeD(dd);
    memset(Queue, -1, sizeof(Queue));
    memset(Isvertex, 0, sizeof(Isvertex));
    beforeB(dd);
}

void DFS(int v, int t)
{
    Isvertex[t] = -1;
    printf("%d ", t);
    int i;
    for (i = 0; i < v; i++)
    {
        if (vertex[t][i] == 1)
        {
            if (Isvertex[i] != -1)
            {
                DFS(v, i);
            }
        }
    }
}

void beforeD(int v)
{
    int i, j;
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            if (vertex[i][j] == 1)
                if (Isvertex[i] != -1)
                {
                    DFS(v, i);
                    break;
                }
    printf("\n");
    return;
}

void BFS(int v, int t)
{
    int i, start = 0, end = -1;
    printf("%d ", t);
    Isvertex[t] = -1;
    Queue[++end] = t;
    while (start <= end)
    {
        t = Queue[start++];
        for (i = 0; i < v; i++)
        {
            if (vertex[t][i])
                if (Isvertex[i] != -1)
                {
                    printf("%d ", i);
                    Isvertex[i] = -1;
                    Queue[++end] = i;
                }
        }
    }
    return;
}

void beforeB(int v)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            if (vertex[i][j] == 1)
                if (Isvertex[i] != -1)
                {
                    BFS(v, i);
                    break;
                }
    }
    printf("\n");
    return;
}

