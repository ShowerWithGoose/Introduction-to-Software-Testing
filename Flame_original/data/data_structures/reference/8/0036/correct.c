#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int graph[200][200];
int visit[200];
int temp[200];
void DFS(int p,int a)
{
    int i;
    visit[p]=1;
    printf("%d ",p);
    for(i=0;i<a;i++)
    {
        if(graph[p][i]==1&&visit[i]==0)
        {
            DFS(i,a);
        }
    }
}
void BFS(int p,int a)
{
    int i,j,t,r;
    temp[1]=p;
    for(j=1,r=1;j<=r;)
    {
        t=temp[j];
        j++;
        if(visit[t]==1)
        {
            continue;
        }
        else
        {
            printf("%d ",t);
        }
        visit[t]=1;
        for(i=0;i<a;i++)
        {
            if(graph[t][i]==1&&visit[i]==0)
            {
                r++;
                temp[r]=i;
            }
        }
    }


}
int main()
{
    int i,j,a,b,point,number,del;
    scanf("%d%d",&point,&number);
    for(i=1;i<=number;i++)
    {
        scanf("%d%d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    DFS(0,point);
    printf("\n");
    for(i=0;i<=200;i++)
    {
        visit[i]=0;
    }
    BFS(0,point);
    printf("\n");
    scanf("%d",&del);
    for(i=0;i<=point;i++)
    {
        graph[del][i]=0;
        graph[i][del]=0;
    }
    for(i=0;i<=200;i++)
    {
        visit[i]=0;
    }
    DFS(0,point);
    printf("\n");
    for(i=0;i<=200;i++)
    {
        visit[i]=0;
    }
    BFS(0,point);
    return 0;
}

