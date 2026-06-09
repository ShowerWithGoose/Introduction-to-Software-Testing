#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long

int visit[102] = {0}, queue[102], nq = 0,del;

void enQueue(int *q, int v)
{
}

void DFS(int g[][102], int v, int n)
{
    int i;
    visit[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
    {
        if (g[v][i] && !visit[i])
            DFS(g, i, n);
    }
}
void travelDPS(int g[][102], int st, int n)
{
    int i;
    for (i = 0; i < n; i++)
        visit[i] = 0;
    for (i = 0; i < n; i++)
    {
        if(i==del)continue;
        if (!visit[i])
            DFS(g, i, n);
    }
}

void BFS(int g[][102], int v, int n)
{
    int i;
    visit[v] = 1;
    queue[nq++] = v;
    while (nq)
    {
        v = queue[0];
        for (i = 1; i < nq; i++)
            queue[i - 1] = queue[i];
        nq--;
        printf("%d ", v);
        for (i = 0; i < n; i++)
        {
            if (g[v][i] && !visit[i])
            {
                visit[i] = 1;
                queue[nq++] = i;
            }
        }
    }
}
void travelBPS(int g[][102], int st, int n)
{
    int i;
    for (i = 0; i < n; i++)
        visit[i] = 0;
    for (i = 0; i < n; i++)
    {
        if(i==del)continue;
        if (!visit[i])
            BFS(g, i, n);
    }
}

int main()
{
    int n, l, v1, v2, i, j, gra[102][102] = {0};
    scanf("%d%d", &n, &l);
    for (i = 0; i < l; i++)
    {
        scanf("%d%d", &v1, &v2);
        gra[v1][v2] = gra[v2][v1] = 1;
    }
    scanf("%d",&del);
    travelDPS(gra, 0, n);
    printf("\n");
    travelBPS(gra, 0, n);
    for ( i = 0; i < n; i++)
    {
        gra[i][del]=0;
        gra[del][i]=0;
    }
    printf("\n");
    travelDPS(gra, 0, n);
    printf("\n");
    travelBPS(gra, 0, n);
    return 0;
}
