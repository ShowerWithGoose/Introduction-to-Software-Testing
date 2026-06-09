#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
int jz[110][110]={0},visited[110]={0},q[110];
int n,line;
void DFS(int a)
{
    int b;
    printf("%d ",a);
    visited[a]=1;
    for(b=0;b<n;b++)
    {
        if(jz[a][b]==1&&visited[b]==0)
        {
            DFS(b);
        }
    }
}
void BFS(int a)
{
    int b,front=0,rear=1,t;
    q[front]=a;
    while(front<=rear)
    {
        t=q[front];front++;
        if(visited[t]==1)
        {
            continue;
        }
        else
        {
            printf("%d ",t);
            visited[t]=1;
            for(b=0;b<n;b++)
            {
                if(jz[t][b]==1&&visited[b]==0)
                {
                    q[rear++]=b;
                }
            }
        }
    }
}
int main()
{
    int x,y,i,k;
    scanf("%d %d",&n,&line);
    for(i=0;i<line;i++)
    {
        scanf("%d %d",&x,&y);
        jz[x][y]=1;jz[y][x]=1;
    }
    scanf("%d",&k);
    DFS(0);printf("\n");
    memset(visited,0,sizeof(visited));
    BFS(0);printf("\n");
    memset(visited,0,sizeof(visited));
    memset(q,0,sizeof(q));
    for(i=0;i<n;i++)
    {
        jz[i][k]=0;jz[k][i]=0;
    }
    DFS(0);printf("\n");
    memset(visited,0,sizeof(visited));
    BFS(0);
    return 0;
}

