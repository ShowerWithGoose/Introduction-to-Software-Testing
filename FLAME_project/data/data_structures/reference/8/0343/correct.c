//我学到的：1.巧妙利用visited数组实现顶点删除  2.层次遍历前的队列初始化

#include<stdio.h>
#include<stdlib.h>

#define MaxV 105
#define N 105//顶点数

typedef struct edg
{
    int adjvex;//边的另一端在头结点数组的位置
    int weight;
    struct edg* next;
}Edge;
typedef struct ver
{
    int vertex_data;
    Edge* link;
    int tag;
}Vertex;

Vertex graph[MaxV];
int visited[N];
int queue_for_BFS[MaxV];

int front_for_BFS,rear_for_BFS,count_for_BFS;

void createGraph(Vertex g[],int n_dege);//传参与否均可//第一行为图的顶点个数，第二行开始第一个数为顶点序号，第二个数开始为该顶点的邻接点，每行以-1结束
Edge* insertEdge(Edge* head,int advertex);//输入头结点指针和邻接点，将邻接点插入表尾并返回头结点指针
void Depth_First_Search(Vertex g[],int v);//深度优先搜索下标为v的节点，可以负责一个连通分量的遍历
void travelDFS_delete(Vertex g[],int n,int delete_v);//n为顶点数,深度优先遍历
void Breadth_First_Search(Vertex g[],int v);//广度优先搜索下标为v的节点
void travelBFS_delete(Vertex g[],int n,int delete_v);//n为顶点数，广度优先遍历
int initialqueue_for_BFS();
int isempty_for_BFS();
int isfull_for_BFS();
int enqueue_for_BFS(int v);
int dequeue_for_BFS();
void delete(int v,int n_ver);

int main()
{
    int i=0;
    for(i=0;i<MaxV;i++)
        graph[i].tag=0;
    int num_vertex,num_edge;
    scanf("%d%d",&num_vertex,&num_edge);
    createGraph(graph,num_edge);
    travelDFS_delete(graph,num_vertex,-1);
    printf("\n");
    travelBFS_delete(graph,num_vertex,-1);
    printf("\n");
    //////////////////////////////////////////////////////////////////////////////
    int vertex_to_delete;
    scanf("%d",&vertex_to_delete);
    travelDFS_delete(graph,num_vertex,vertex_to_delete);
    printf("\n");
    travelBFS_delete(graph,num_vertex,vertex_to_delete);
    printf("\n");
    system("pause");
    return 0;
}

void createGraph(Vertex g[],int n_edge)
{
    int i=0;
    int v1=0,v2=0;
    for(i=0;i<n_edge;i++)
    {
        scanf("%d%d",&v1,&v2);
        g[v1].link=insertEdge(g[v1].link,v2);
        g[v2].link=insertEdge(g[v2].link,v1);//无向图,插两次
    }
}

Edge* insertEdge(Edge* head,int advertex)
{
    Edge *e,*p,*q;
    e=(Edge*)malloc(sizeof(Edge));
    e->adjvex=advertex;
    e->weight=1;
    e->next=NULL;
    if(head==NULL)
    {
        head=e;
        return head;
    }
    for(p=head;p!=NULL;p=p->next)
    {
        if(p->adjvex>e->adjvex)
        {
            if(p==head)
            {
                e->next=p;
                head=e;
                return head;
            }
            for(q=head;q->next!=p;q=q->next)
                continue;
            e->next=p;
            q->next=e;
            return head;
        }
    }
    for(p=head;p->next!=NULL;p=p->next)
        continue;
    p->next=e;//插入到表尾
    return head;
}

void Depth_First_Search(Vertex g[],int v)
{
    Edge* p;
    visited[v]=1;//标志此节点已被访问
    printf("%d ",v);//////////////访问行为自定义
    for(p=g[v].link;p!=NULL;p=p->next)
    {
        if(!visited[p->adjvex])
            Depth_First_Search(g,p->adjvex);
    }
}

void travelDFS_delete(Vertex g[],int n,int delete_v)
{
    int i=0;
    for(i=0;i<n;i++)
        visited[i]=0;//初始化
    if(delete_v!=-1)
        visited[delete_v]=1;
    for(i=0;i<n;i++)
    {
        if(!visited[i])
            Depth_First_Search(g,i);//完成一个连通分量的遍历
    }
}

void Breadth_First_Search(Vertex g[],int v)//广度优先搜索下标为v的节点
{
    Edge* p;
    visited[v]=1;//标志节点已访问，已入队
    enqueue_for_BFS(v);
    while(!isempty_for_BFS())
    {
        v=dequeue_for_BFS();//不论是否删除都出队
        printf("%d ",v);//访问行为自定义
        for(p=g[v].link;p!=NULL;p=p->next)
        {
            if(!visited[p->adjvex])
            {
                visited[p->adjvex]=1;
                enqueue_for_BFS(p->adjvex);
            }
        }
    }
}

void travelBFS_delete(Vertex g[],int n,int delete_v)//n为顶点数
{
    initialqueue_for_BFS();
    int i=0;
    for(i=0;i<n;i++)
        visited[i]=0;//初始化
    if(delete_v!=-1)
        visited[delete_v]=1;
    for(i=0;i<n;i++)
    {
        if(!visited[i])
            Breadth_First_Search(g,i);
    }
}

int initialqueue_for_BFS()
{
    front_for_BFS=0;
    rear_for_BFS=MaxV-1;
    count_for_BFS=0;
    return 0;
}

int isempty_for_BFS()
{
    return count_for_BFS==0;
}

int isfull_for_BFS()
{
    return count_for_BFS==MaxV;
}

int enqueue_for_BFS(int v)
{
    static int cnt=0;
    if(isfull_for_BFS())
    {
        printf("error");
        return 1;
    }
    cnt++;
    rear_for_BFS=(rear_for_BFS+1)%MaxV;
    queue_for_BFS[rear_for_BFS]=v;
    count_for_BFS++;
    return 0;
}

int dequeue_for_BFS()
{
    if(isempty_for_BFS())
    {
        printf("error");
    }
    int temp=queue_for_BFS[front_for_BFS];
    count_for_BFS--;
    front_for_BFS=(front_for_BFS+1)%MaxV;
    return temp;
}
