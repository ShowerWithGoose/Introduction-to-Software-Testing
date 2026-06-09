#include <stdio.h>
#include <stdlib.h>
#define Maxnum 120
int n, m, matrix[Maxnum][Maxnum], Visited[Maxnum], Queue[2000], head, end, num;
void travelDFS();
void DFS(int v);
void travelBFS();
void BFS(int v);
int main()
{
    int a, b, c, i;
    scanf("%d%d", &n, &m);
    num = n;
    while (m--)
    {
        scanf("%d%d", &a, &b);
        matrix[a][b] = matrix[b][a] = 1;
    }
    travelDFS();
    puts("");
    travelBFS();
    puts("");
    scanf("%d", &c);
    for (i = 0; i < n; i++)
        matrix[i][c] = matrix[c][i] = 0;
    Visited[c] = 1;
    travelDFS();
    puts("");
    Visited[c] = 1;
    travelBFS();
    system("pause");
    return 0;
}
void travelDFS()
{
    int i;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            DFS(i);
    for (i = 0; i < num; i++)
        Visited[i] = 0;
}
void DFS(int v)
{
    int i;
    Visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
    {
        if ((!Visited[i]) && matrix[v][i])
            DFS(i);
    }
}
void travelBFS()
{
    head = 0;
    end = -1;
    int i;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            BFS(i);
    for (i = 0; i < num; i++)
        Visited[i] = 0;
    for (i = 0; i < 2000; i++)
        Queue[i] = 0;
    for (i = 0; i < num; i++)
        Visited[i] = 0;
}
void BFS(int v)
{
    int i;
    printf("%d ", v);
    Visited[v] = 1;
    Queue[++end] = v;
    while (head <= end)
    {                           //  循环，直到队空为止
        v = Queue[head++];      //取出队头元素,获取该顶点第一个邻接顶点
        for (i = 0; i < n; i++) //访问该顶点下的每个邻接顶点
            if ((!Visited[i]) && matrix[v][i])
            {
                printf("%d ", i); //访问当前顶点
                Visited[i] = 1;   //标识某顶点被访问过
                Queue[++end] = i; //邻接顶点依次分别入队
            }
    }
}
