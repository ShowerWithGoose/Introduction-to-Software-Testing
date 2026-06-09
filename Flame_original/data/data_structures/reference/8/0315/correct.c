#include <stdio.h>
#include <string.h>
int point[100];
int raw[100][100];
int graph[100][100];
int n,l,del;
int initpoint(int s)
{
    for(int i = 0; i < n; i++)
        point[i] = 1;
    if(s!=0)
        point[s] = 0;
}

void dfs(int p)
{
    printf("%d ", p);
    point[p] = 0;
    for(int i = 0; i < n; i++)
    {
        if(graph[p][i] && point[i])
        {
            graph[p][i] = graph[i][p] = 0;
            dfs(i);
        }
    }
}

void bfs()
{
    int queue[100] = {0};
    int cnt = 1, front = 0, rear = 0;
    while(cnt != 0)
    {
        int ele = queue[front];
        printf("%d ",ele);
        for(int i = 0; i < n; i++)
        {
            if(graph[ele][i] && point[i])
            {
                graph[ele][i] = graph[i][ele] = 0;
                rear = (rear+1)%100;
                queue[rear] = i;
                point[i] = 0;
                cnt++;
            }
        }
        cnt--;
        front = (front+1)%100;
    }
    
}
int main()
{
    int a,b;
    scanf("%d%d",&n,&l);
    initpoint(0);
    for(int i = 0; i < l; i++)
    {
        scanf("%d%d",&a,&b);
        raw[a][b] = raw[b][a] = 1;
    }
    memcpy(graph, raw, sizeof(raw));
    dfs(0);
    printf("\n");
    initpoint(0);
    memcpy(graph, raw, sizeof(raw));
    bfs(0);
    printf("\n");
    int del;
    scanf("%d",&del);
    memcpy(graph, raw, sizeof(raw));
    initpoint(del);
    dfs(0);
    printf("\n");
    initpoint(del);
    memcpy(graph, raw, sizeof(raw));
    bfs(0);
    return 0;
}
