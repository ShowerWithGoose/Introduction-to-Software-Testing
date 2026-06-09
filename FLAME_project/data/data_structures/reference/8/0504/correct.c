#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data[1000];
    int front;
    int rear;
};
void DFS(int p,int HaveVisit[],int num,int **map);
void BFS(int p,int *HaveVisit,int num,int **map,struct node *q);

int main()
{
    int n;
    int line;
    scanf("%d%d",&n,&line);
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
    int deletenum;
    for(int i=1;i<=line;i++)
    {
        scanf("%d%d",&a,&b);
        graph[a][b]=graph[b][a]=1;
    }
    scanf("%d",&deletenum);
    int *visit=(int *)malloc(sizeof(int)*(n+2));
    for(int i=0;i<n;i++)visit[i]=0;
    DFS(0,visit,n,graph);
    printf("\n");
    for(int i=0;i<n;i++)visit[i]=0;
    struct node *queue=(struct node*)malloc(sizeof(struct node));
    queue->front=0;
    queue->rear=0;
    for(int i=0;i<100;i++)queue->data[i]=-1;
    BFS(0,visit,n,graph,queue);
    printf("\n");
    for(int i=0;i<n;i++)visit[i]=0;
    for(int i=0;i<n;i++)
    {
        graph[i][deletenum]=0;
        graph[deletenum][i]=0;
    }
    DFS(0,visit,n,graph);
    printf("\n");
    for(int i=0;i<n;i++)visit[i]=0;
    for(int i=0;i<queue->rear+1;i++)queue->data[i]=0;
    queue->rear=queue->front=0;
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
void BFS(int p,int *HaveVisit,int num,int **map,struct node *q)
{
    if(q->rear==0)
    {
        q->data[q->rear]=p;
        q->rear++;
        HaveVisit[p]=1;
        BFS(p,HaveVisit,num,map,q);
    }
    else
    {
        q->front++;
        printf("%d ",p);
        for(int i=0;i<num;i++)
        {
            if(HaveVisit[i]==0&&map[p][i]==1)
            {
                q->data[q->rear]=i;

                q->rear++;
                HaveVisit[i]=1;
            }
        }
        if(q->rear==q->front)return ;
        else
        {
            BFS(q->data[q->front],HaveVisit,num,map,q);
        }
    }

}
