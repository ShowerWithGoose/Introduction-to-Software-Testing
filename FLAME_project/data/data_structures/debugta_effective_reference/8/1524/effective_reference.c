#include <stdio.h>
#include <string.h>
void DFS(int d);
void BFS(int d);
int visited[200]={0};
int weight[200][200];
int que[200];
int b,d;
int main()
{
    int j,k,i,sc;
    scanf("%d %d",&d,&b);
    for(i=0;i<b;i++)
    {
        scanf("%d %d",&j,&k);
        weight[j][k]=weight[k][j]=1;
    }
    DFS(0);printf("\n");
    memset(visited,0,sizeof(visited));
    
	BFS(0);printf("\n");
    memset(visited,0,sizeof(visited));

    scanf("%d",&sc);
    memset(visited,0,sizeof(visited));
    visited[sc]=1;
    DFS(0);printf("\n");
    memset(visited,0,sizeof(visited));
    memset(que,0,sizeof(que[0]));
    visited[sc]=1;
    BFS(0);printf("\n");
    system("pause");
    return 0;
}
void DFS(int k)
{
    int i;
    printf("%d ",k);
    visited[k]=1;
    for(i=0;i<d;i++)
    {
        if(weight[k][i]&&!visited[i])
        {
            DFS(i);
        }
    }
}
void BFS(int k)
{
    int i,head=0,tail=1,tmp;
    que[head]=k;
    while(head<=tail)
    {
        tmp=que[head];
        head++;
        if(visited[tmp]) continue;
        else
        {
            printf("%d ",tmp);
            visited[tmp]=1;
            for(i=0;i<d;i++)
            {
                if(weight[tmp][i]&&!visited[i])
                    que[tail++]=i;
            }
        }
    }
}
