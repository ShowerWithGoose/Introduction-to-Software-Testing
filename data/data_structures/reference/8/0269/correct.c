#include <stdio.h>
#include <string.h>
int weights[200][200], visited[200], que[200];
int num_vertex, num_edge;
void DFS(int v)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < num_vertex; i++)
        if (weights[v][i] && !visited[i])
            DFS(i);
}
void BFS(int v)
{
    int i, head = 0, tail = 1, tmp;
    que[head] = v;
    while (head <= tail)
    {
        tmp = que[head++];
        if (!visited[tmp])
        {
            printf("%d ", tmp);
            visited[tmp] = 1;
            for (i = 0; i < num_vertex; i++)
                if (weights[tmp][i] && !visited[i])
                    que[tail++] = i;
        }
    }
}
int main()
{
    int u, v, i, del;
    scanf("%d %d", &num_vertex, &num_edge);
    for (i = 0; i < num_edge; i++)
    {
        scanf("%d %d", &u, &v); 
        weights[u][v] = 1;
        weights[v][u] = 1;
    }
    DFS(0);
    puts(""); 
    memset(visited, 0, sizeof(visited)); //初始化!!!
    BFS(0);
    puts(""); 
    memset(visited, 0, sizeof(visited)); 
    scanf("%d", &del);
    visited[del] = 1;                    //算法核心：将要删除的元素设置为已访问
    DFS(0);
    puts(""); 
    memset(visited, 0, sizeof(visited));
    memset(que, 0, sizeof(que)); //队列初始化不要忘了
    visited[del] = 1; 
    BFS(0);
    puts("");
    return 0;
}

