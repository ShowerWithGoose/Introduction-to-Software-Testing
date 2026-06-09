#include <stdio.h>
#include <string.h>
#define MAXNUM 100
int weight[MAXNUM][MAXNUM] = {0};//0无边，1有边
int visited[MAXNUM] = {0};//0未访问，1访问
int head = 0, tail = -1;//队列

void dfs(int v, int n);
void bfs(int v, int n);
void in(int *d, int v);
int getfirst(int *d);
int isempty();
int main()
{
    int n_ver, n_edg, del;
    int a, b;
    scanf("%d%d", &n_ver, &n_edg);
    for (int i = 0; i < n_edg;i++)
    {
        scanf("%d%d", &a, &b);
        weight[a][b] = weight[b][a] = 1;
    }
    scanf("%d", &del);
    dfs(0, n_ver);
    memset(visited, 0, sizeof(int) * n_ver);
    printf("\n");
    bfs(0, n_ver);
    memset(visited, 0, sizeof(int) * n_ver);
    for (int i = 0; i < n_ver;i++)
    {
        weight[i][del] = weight[del][i] = 0;
    }
    head = 0, tail = -1;
    printf("\n");
    dfs(0, n_ver);
    memset(visited, 0, sizeof(int) * n_ver);
    printf("\n");
    bfs(0, n_ver);
    memset(visited, 0, sizeof(int) * n_ver);
}
void dfs(int v, int n)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n;i++)
    {
        if(visited[i] == 0 && weight[v][i] == 1)
            dfs(i, n);
    }
}
void bfs(int v, int n)
{
    int dui[2 * MAXNUM] = {0};
    visited[v] = 1;
    in(dui, v);
    while(!isempty())
    {
        v = getfirst(dui);
        printf("%d ", v);
        for (int i = 0; i < n;i++)
        {
            if(weight[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                in(dui, i);
            }
        }
    }
}
void in(int *d, int v)
{
    d[++tail] = v;
}
int getfirst(int *d)
{
    return d[head++];
}
int isempty()
{
    if(head - tail == 1)
        return 1;
    else
        return 0;
}


