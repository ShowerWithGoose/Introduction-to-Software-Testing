/*
 * @Author:
 * @Date: 2022-06-03 19:24:16
 * @LastEditors:
 * @LastEditTime: 2022-06-03 19:37:42
 * @Description: 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
//#define ll long long
#define N 110
int map[N][N];
int n, en, w;
int queue[N];
int visited[N];
int head = -1;
int tail = 0;
void DFS(int u);
void BFS(int u);
void Delete(int w);
void MapDFS();
void MapBFS();
int main()
{
    int u, v;
    scanf("%d %d",&n, &en);
    int t = en;
    while(t--)
    {
        scanf("%d %d",&u,&v);
        map[u][v] = 1;
        map[v][u] = 1;
    }
    MapDFS();
    MapBFS();
    scanf("%d",&w);
    Delete(w);
    head  =-1; tail = 0;
    MapDFS();
    MapBFS();
    return 0;
}
void Delete(int u)
{
    for(int i = 0; i < n; i++)
    {
        map[u][i]  =0;
        map[i][u]  =0;
    }
}
void MapDFS()
{
    DFS(0);
    puts("");
    memset(visited,0,sizeof(int)*N);
}
void MapBFS()
{
    BFS(0);
    puts("");
    memset(visited,0,N*sizeof(int));
}
void DFS(int u)
{
    visited[u] = 1;
    printf("%d ",u);
    for(int i = 0; i < n; i++)
        if(map[u][i] && !visited[i])
            DFS(i);
}
void BFS(int u)
{
    visited[u] = 1;
    printf("%d ",u);
    queue[tail++] = u;
    while(head < tail)
    {
        int u0 = queue[++head];
        for(int i = 0; i < n; i++)
        {
            if(map[u0][i] && !visited[i])
            {
                visited[i] = 1;
                printf("%d ",i);
                queue[tail++] = i;
            }
        }
    }
}   
