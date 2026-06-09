#include<stdio.h>
#include<string.h>
#include<stdio.h>
#define MaxSize 100
typedef struct QNode *Queue;
typedef int Elemtype;
struct QNode{
    Elemtype data[MaxSize];
    int front;  //记录队头
    int rear;  //记录队尾
};
Queue Q;
Queue CreatQueue()
{
    Queue Q;
    Q=(Queue)malloc(sizeof(struct QNode));
    Q->front=0;
    Q->rear=0;
    return Q;
}
int IsFull(Queue Q)
{
    if((Q->rear+1)%MaxSize==Q->front) return 1;
    return 0;
}
int EnQueue(Queue Q,Elemtype e)
{
    if(IsFull(Q)) return 0;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MaxSize;
    return 1;
}
int DeQueue(Queue Q)
{
        int a=Q->data[Q->front];
        Q->front=(Q->front+1)%MaxSize;
        return a;
}
int Isempty(Queue Q)
{
    if(Q->front==Q->rear)
        return 1;
    else return 0;
}
int graph[105][105];
int visit[105];
int v,e;
void DFS(int G[][105],int vertex)
{
    visit[vertex]=1;
    printf("%d ",vertex);
    for(int i=0;i<v;i++){
        if(i!=vertex&&G[vertex][i]&&!visit[i])
        DFS(G,i);
    }
}
void BFS(int G[][105],int vertex)
{
    visit[vertex]=1;
    EnQueue(Q,vertex);
    while(!Isempty(Q)){
        vertex=DeQueue(Q);
        printf("%d ",vertex);
        for(int i=0;i<v;i++){
            if(i!=vertex&&G[vertex][i]&&!visit[i]){
                visit[i]=1;
                EnQueue(Q,i);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&v,&e);
    for(int i=1;i<=e;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int delete;
    scanf("%d",&delete);
    DFS(graph,0);
    printf("\n");
    Q=CreatQueue();
    memset(visit,0,104);
    BFS(graph,0);
    memset(visit ,0,104);
    printf("\n");
    for(int j=0;j<v;j++){
        graph[delete][j]=0;
        graph[j][delete]=0;
    }
        DFS(graph,0);
    printf("\n");
    Q=CreatQueue();
    memset(visit,0,104);
    BFS(graph,0);
    memset(visit ,0,104);
    printf("\n");
        
}
