#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int visited[100] = {};

void bfs(int (*)[100], int n, int v);
void dfs(int (*)[100], int n, int v);
int main()
{
    #ifdef ACU
    freopen("in.txt", "r", stdin);
    #endif
    int vrtxnum = 0, edgenum = 0, graph[100][100] = {}, dnode = 0, dgraph[100][100] = {};
    scanf("%d%d", &vrtxnum, &edgenum);
    for (size_t i = 0; i < edgenum; i++)
    {
        int j = 0, k = 0;
        scanf("%d%d", &j, &k);
        graph[j][k] = graph[k][j] = 1;
    }
    scanf("%d", &dnode);
    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 100; j++)
        {
            if (i != dnode && j != dnode)
                dgraph[i][j] = graph[i][j];
        }
    }
     
    dfs(graph, vrtxnum, 0);putchar('\n');
    memset(visited, 0, sizeof(int) * vrtxnum);
    bfs(graph, vrtxnum, 0);putchar('\n');
    memset(visited, 0, sizeof(int) * vrtxnum);
    dfs(dgraph, vrtxnum, 0);putchar('\n');
    memset(visited, 0, sizeof(int) * vrtxnum);
    bfs(dgraph, vrtxnum, 0);
    return 0;
}


void bfs(int (*graph)[100], int n, int v)
{
    int queue[100] = {}, head = -1, tail = 0, pos = v;
    visited[v] = 1;
    printf("%d ", pos);
        for (size_t i = 0; i < n; i++)
        {
            if((graph[pos][i] != 0) && (visited[i] == 0))
                visited[i] = 1, queue[tail++] = i;
        }
    while(head+1 != tail)
    {
        pos = queue[++head];
        printf("%d ", pos);
        for (size_t i = 0; i < n; i++)
        {
            if((graph[pos][i] != 0) && (visited[i] == 0))
                visited[i] = 1, queue[tail++] = i;
        }
    }
}

void dfs(int (*graph)[100], int n, int v)
{
    printf("%d ", v);
    visited[v] = 1;
    for (size_t i = 0; i < n; i++)
    {
        if ((graph[v][i] != 0) && (visited[i] == 0))
            dfs(graph, n, i);
    }
}
