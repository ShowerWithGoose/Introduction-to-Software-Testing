#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define eps 1e-6
int g[101][101], visit[101];
int np, ns;
void DFS(int v)
{
    visit[v] = 1;
    printf("%d ", v);
    int vn;
    for (vn = 0; vn < np; vn++)
    {
        if (g[v][vn] && !visit[vn])
        {
            DFS(vn);
        }
    }
}
int front = -1, rear = -1, queue[101];
void inqueue(int v)
{
    if (rear < 101)
        queue[++rear] = v;
}
int dequeue()
{
    if (front <= rear)
        return queue[front++];
    return 0;
}
void BFS(int v)
{
    visit[v] = 1;
    printf("%d ", v);
    inqueue(v);
    int p;
    while (front <= rear)
    {
        p = dequeue();
        for (int nv = 0; nv < np; nv++)
        {
            if (g[p][nv] == 1 && visit[nv] == 0)
            {
                visit[nv] = 1;
                inqueue(nv);
                printf("%d ", nv);
            }
        }
    }
}
int main()
{
    scanf("%d%d", &np, &ns);
    int i;
    int v1, v2;
    for (i = 0; i < ns; i++)
    {
        scanf("%d%d", &v1, &v2);
        g[v1][v2] = 1;
        g[v2][v1] = 1;
    }
    int delet;
    scanf("%d", &delet);
    DFS(0);
    printf("\n");
    memset(visit, 0, 101);
    BFS(0);
    printf("\n");
    for (i = 0; i < np; i++)
    {
        g[delet][i] = 0;
        g[i][delet] = 0;
    }
    memset(visit, 0, 101);
    DFS(0);
    printf("\n");
    memset(visit, 0, 101);
    BFS(0);
    return 0;
}
