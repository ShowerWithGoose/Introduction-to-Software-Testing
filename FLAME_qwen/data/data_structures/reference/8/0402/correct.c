#include <stdio.h>
#include <string.h>
void DFS(int n);
void BFS(int n);
int visited[200]={0};
int weight[200][200];
int que[200];
int m,n;
int main()
{
    int u,v,i,del;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        weight[u][v]=weight[v][u]=1;
    }
    DFS(0);printf("\n");
    memset(visited,0,sizeof(visited));
    
	BFS(0);printf("\n");
    memset(visited,0,sizeof(visited));

    scanf("%d",&del);
    memset(visited,0,sizeof(visited));
    visited[del]=1;
    DFS(0);printf("\n");
    memset(visited,0,sizeof(visited));
    memset(que,0,sizeof(que[0]));
    visited[del]=1;
    BFS(0);printf("\n");
    system("pause");
    return 0;
}
void DFS(int v)
{
    int i;
    printf("%d ",v);
    visited[v]=1;
    for(i=0;i<n;i++)
    {
        if(weight[v][i]&&!visited[i])
        {
            DFS(i);
        }
    }
}
void BFS(int v)
{
    int i,head=0,tail=1,tmp;
    que[head]=v;
    while(head<=tail)
    {
        tmp=que[head];
        head++;
        if(visited[tmp]) continue;
        else
        {
            printf("%d ",tmp);
            visited[tmp]=1;
            for(i=0;i<n;i++)
            {
                if(weight[tmp][i]&&!visited[i])
                    que[tail++]=i;
            }
        }
    }
}
