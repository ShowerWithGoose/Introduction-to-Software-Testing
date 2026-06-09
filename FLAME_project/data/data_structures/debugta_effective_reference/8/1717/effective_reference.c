#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data[1000];
    int h;
    int t;
};
void DFS(int p,int HaveVisit[],int num,int **map);
void BFS(int p,int *HaveVisit,int num,int **map,struct node *dui);

int main()
{
    int n;
    int e;
    scanf("%d%d",&n,&e);
    int **graph=(int **)malloc(sizeof(int *)*(n+2));
    for(int i=0;i<=n;i++)
    {
        graph[i]=(int *)malloc(sizeof(int)*(n+2));
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    int a;
    int b;
    int d;
    for(int i=1;i<=e;i++)
    {
        scanf("%d%d",&a,&b);
        graph[a][b]=graph[b][a]=1;
    }
    scanf("%d",&d);
    int *visit=(int *)malloc(sizeof(int)*(n+2));
    for(int i=0;i<n;i++)visit[i]=0;
    DFS(0,visit,n,graph);
    printf("\n");
    for(int i=0;i<n;i++)visit[i]=0;
    struct node *queue=(struct node*)malloc(sizeof(struct node));
    queue->h=0;
    queue->t=0;
    for(int i=0;i<100;i++)queue->data[i]=-1;
    BFS(0,visit,n,graph,queue);
    printf("\n");
    for(int i=0;i<n;i++)visit[i]=0;
    for(int i=0;i<n;i++)
    {
        graph[i][d]=0;
        graph[d][i]=0;
    }
    DFS(0,visit,n,graph);
    printf("\n");
    for(int i=0;i<n;i++)visit[i]=0;
    for(int i=0;i<queue->t+1;i++)queue->data[i]=0;
    queue->t=queue->h=0;
    for(int i=0;i<n;i++)visit[i]=0;
    BFS(0,visit,n,graph,queue);
    return 0;
}
void DFS(int p,int HaveVisit[],int num,int **map)
{
    HaveVisit[p]=1;
    printf("%d ",p);
    for(int i=0;i<num;i++)
    {
        if(map[p][i]==1&&HaveVisit[i]==0)
        {
            DFS(i,HaveVisit,num,map);
        }
    }
}
void BFS(int p,int *HaveVisit,int num,int **map,struct node *dui)
{
    if(dui->t==0)
    {
        dui->data[dui->t]=p;
        dui->t++;
        HaveVisit[p]=1;
        BFS(p,HaveVisit,num,map,dui);
    }
    else
    {
        dui->h++;
        printf("%d ",p);
        for(int i=0;i<num;i++)
        {
            if(HaveVisit[i]==0&&map[p][i]==1)
            {
                dui->data[dui->t]=i;

                dui->t++;
                HaveVisit[i]=1;
            }
        }
        if(dui->t==dui->h)return ;
        else
        {
            BFS(dui->data[dui->h],HaveVisit,num,map,dui);
        }
    }

}
