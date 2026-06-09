#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLENGTH 105
int num_vertex, num_edge;
int graph[MAXLENGTH][MAXLENGTH] = {{0}};
int temp[MAXLENGTH] = {0};
int tmp[MAXLENGTH] = {0};
int flag;
void Dfs(int p);
void Bfs(int p);
int main()
{
    int vertex, edge;
    int i = 0;
    scanf("%d%d", &num_vertex, &num_edge);
    for (i=1; i<=num_edge; i++) //建立邻接表
    {
        scanf("%d%d", &vertex, &edge);
        graph[vertex][edge] = 1;
        graph[edge][vertex] = 1;
    }
    Dfs(0);
    printf("\n");
    memset(temp, 0, sizeof(temp)/temp[0]);
    flag = 0;
    Bfs(0);
    printf("\n");
    memset(temp, 0, sizeof(temp)/temp[0]);
    flag = 0;
    int delete;
    scanf("%d",&delete);
    temp[delete] = 1;
    Dfs(0);
    printf("\n");
    memset(temp, 0, sizeof(temp)/temp[0]);
    flag = 0;
    temp[delete] = 1;
    Bfs(0);
    printf("\n");
}

void Dfs(int p)
{
    int i = 0;
    if (!flag)
    {
        printf("%d", p);
        flag = 1;
    }
    else
        printf(" %d", p);
    temp[p] = 1;
    for (i=1; i <= num_vertex; i++)
        if (graph[p][i]&&!temp[i])
            Dfs(i);
}

void Bfs(int p)
{
    int t;
    int i = 0;
    int j = 0;
    int k = 0;
    tmp[1] = p;
    for (i=1,j=1; i<=j;)
    {
        t = tmp[i++];
        if (temp[t])
            continue;
        if (!flag)
        {
            printf("%d", t);
            flag = 1;
        }
        else
            printf(" %d", t);
        temp[t] = 1;
        for (k=1; k<=num_vertex; k++)
            if (graph[t][k]&&!temp[k])
                tmp[++j] = k;
    }
}


