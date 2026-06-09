#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int weight[101][101]={0};
int visited[101]={0};
int n_vertex,n_edge;
int quene[101];

void DFS(int st)
{
    printf("%d ",st);
    visited[st]=1;
    for(int i=0;i<n_vertex;i++)
    {
        if(weight[st][i]&&visited[i]==0)
        DFS(i);
    }
}

void BFS(int st)
{
    int end=0;
    int head=0;
    quene[end]=st;
    visited[end]=1;
    while(head<=end)
    {
        for(int i=0;i<n_vertex;i++)
        {
            if(weight[quene[head]][i]&&visited[i]==0)
            {
                end++;
                quene[end]=i;
                visited[i]=1;
            }
        }
        printf("%d ",quene[head]);
        head++;
    }
}


int main()
{
    scanf("%d %d",&n_vertex,&n_edge);
    for (int i = 0; i < n_edge; i++)
    {
       int u,v;
       scanf("%d %d",&u,&v);
       weight[u][v]=1;
       weight[v][u]=1;
    }

    DFS(0);
    printf("\n");
    memset(visited,0,sizeof(visited));

    BFS(0);
    printf("\n");
    memset(visited,0,sizeof(visited));

    int u;
    scanf("%d",&u);
    visited[u]=1;
    DFS(0);
    printf("\n");
    memset(visited,0,sizeof(visited));

    visited[u]=1;
    BFS(0);
    printf("\n");
    memset(visited,0,sizeof(visited));

    system("pause");
    return 0;
}
