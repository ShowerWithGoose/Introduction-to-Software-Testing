#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int map[105][105];
int arr[105];
int m, n, a, b, target; //顶点数和边数
void addedge(int, int);
void DFS(int);
void BFS(int);
int queue[105];
int front = -1, rear = -1;
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        addedge(a, b);
    }
    DFS(0);
    printf("\n");
    memset(arr, 0, sizeof(arr));
    BFS(0);
    printf("\n");
    scanf("%d", &target);
    for (int i = 0; i < n; i++)
    {
        map[i][target] = 0;
    }
    DFS(0);
    printf("\n");
    memset(arr, 0, sizeof(arr));
    BFS(0);
    printf("\n");
    system("PAUSE");
    return 0;
}
void addedge(int a, int b)
{
    map[a][b] = 1;
    map[b][a] = 1;
}
void DFS(int ver)
{
    if (arr[ver] == 0)
    {
        printf("%d ", ver);
        arr[ver] = 1;
        for (int i = 0; i < m; i++)
        {
            if (map[ver][i] != 0)
                DFS(i);
        }
    }
    else
        return;
}
void BFS(int ver)
{
    queue[++rear] = ver;
    while (front < rear)
    {
        if (arr[queue[++front]] == 0)
        {
            printf("%d ", queue[front]);
            arr[queue[front]] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            if (map[queue[front]][i] != 0 && arr[i] == 0)
            {
                queue[++rear] = i;
            }
        }
    }
    memset(arr, 0, sizeof(arr));
    memset(queue, 0, sizeof(queue));
    front = rear = -1;
}
