#include <stdio.h>
#include <stdlib.h>
#define N 100    //顶点数目的最大值
typedef int VertexType;    //顶点类型应由用户定义

/*边表结点*/
typedef struct EdgeNode
{
    int adjvex;    //该弧所指向的顶点的下标或者位置
    struct EdgeNode *next;    //指向下一个与当前顶点相连的邻接点构成的边
}EdgeNode;

/*顶点表结点*/
typedef struct VertexNode
{
    VertexType data;    //顶点域，存储顶点信息
    EdgeNode* firstedge;    //边表头指针
}VertexNode, AdjList[N];

/*邻接表*/
typedef struct
{
    AdjList adjList; //邻接表，adjList是一个VertexNode类型的数组的数组名，该数组的长度为N
    int vexnum, arcnum;    //图中当前顶点数和边数
}Graph;

int visited[N]={0};    //访问标记数组

// 获取图G中顶点v的第一个邻接点
int FirstNeighbor(Graph G, int v)
{
    if (v < 0 || v >= G.vexnum || G.adjList[v].firstedge == NULL)
        return -1; // 顶点无效或没有邻接点
    int min=N;
    EdgeNode* current = G.adjList[v].firstedge;
    while(current!=NULL)
    {
        if(current->adjvex<min && visited[current->adjvex]==0)
            min=current->adjvex;
        current=current->next;
    }
    if(min!=N)
        return min; // 返回第一个邻接点的编号
    else
        return -1;
}

/*从顶点出发，深度优先遍历图G*/
void DFS(Graph G, int v)
{
    printf("%d ",v);    //访问顶点
    visited[v] = 1;    //设已访问标记
    int w= FirstNeighbor(G,v);
    for(; w>=0;w= FirstNeighbor(G,v))
    {
        if(visited[w]==0)    //w为u的尚未访问的邻接顶点
            DFS(G,w);
    }
}

/*遍历图*/
void DFSTraverse(Graph G)
{
    for(int v=0;v<G.vexnum;v++)//从v=0开始遍历
    {
        if(!visited[v])
            DFS(G,v);
    }
}

typedef struct name
{
    int data[N];//存放队列元素
    int front;//队头指针
    int rear;//队尾指针
}queue;

//初始化队列
queue* queue_create()
{
    queue* p=(queue* )malloc(sizeof(queue));
    p->front=p->rear=-1;
    return p;
}

//销毁队列
void queue_destroy(queue* p)
{
    free(p);
    p=NULL;
}

//判断队列是否为空
int isEmpty(queue* p)
{
    return (p->front==p->rear);
}

//入队
int queue_en(queue* p,int data)
{
    if(p->rear==N-1)
        return -1;
    p->data[++p->rear]=data;
    return 1;
}

//出队
int queue_de(queue* p)
{
    if(p->front==p->rear)
        return -1;
    return (p->data[++p->front]);
}

void BFSTraverse(Graph G)
{
    int i;
    queue* Q=queue_create();    //初始化一辅助用的队
    for(i=0; i<G.vexnum; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;    //设置当前访问过
            printf("%d ",i);    //访问顶点
            queue_en(Q, i);    //将此顶点入队列
            //若当前队列不为空
            while(!isEmpty(Q))
            {
                int current = queue_de(Q); // 顶点current出队列
                int j=FirstNeighbor(G, current);
                for(; j>=0; j=FirstNeighbor(G, current))
                {
                    //检验所有邻接点
                    if(!visited[j])
                    {
                        printf("%d ",j);    //访问顶点
                        visited[j] = 1;    //访问标记
                        queue_en(Q, j);    //顶点j入队列
                    }
                }
            }
        }
    }
}

void insert_line(Graph *G,int dot1,int dot2)
{
    EdgeNode* p=(EdgeNode*)malloc(sizeof(EdgeNode));
    p->adjvex=dot2;
    p->next=NULL;
    if(G->adjList[dot1].firstedge==NULL)
        G->adjList[dot1].firstedge=p;
    else
    {
        EdgeNode* q=G->adjList[dot1].firstedge;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
    }
}

void delete_vex(Graph G,int v)
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(i!=v)
        {
            EdgeNode* p=G.adjList[i].firstedge;
            if(p!=NULL)
            {
                if(p->adjvex==v)
                    p->next = p->next->next;  // @@ Error: Incorrectly attempts to remove the first node. Should update firstedge, and also fails when p->next is NULL.
                else
                {
                    EdgeNode* q=p;
                    p=p->next;
                    while(p!=NULL)
                    {
                        if(p->adjvex==v)
                        {
                            q->next=p->next;   // line B
                            break;
                        }
                        else
                        {
                            p=p->next;
                            q=q->next;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    //删除节点前
    //读入图的信息
    Graph G;
    int dot1,dot2,delete_dot;//顶点个数，边的个数
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for(int i=0;i<G.vexnum;i++)
    {
        G.adjList[i].data=i;
        G.adjList[i].firstedge=NULL;
    }
    for(int i=0;i<G.arcnum;i++)
    {
        getchar();
        scanf("%d %d",&dot1,&dot2);
        insert_line(&G,dot1,dot2);
        insert_line(&G,dot2,dot1);
    }
    //深度优先遍历
    DFSTraverse(G);
    printf("\n");
    for(int i=0; i<G.vexnum; i++)
        visited[i]=0;//第二次遍历需要重置访问数组
    BFSTraverse(G);
    printf("\n");

    //删除节点后
    getchar();
    scanf("%d",&delete_dot);
    delete_vex(G,delete_dot);

    for(int i=0; i<G.vexnum; i++)
        visited[i]=0;//第二次遍历需要重置访问数组
    visited[delete_dot]=1;
    DFSTraverse(G);
    printf("\n");

    for(int i=0; i<G.vexnum; i++)
        visited[i]=0;//第二次遍历需要重置访问数组
        visited[delete_dot]=1;

    BFSTraverse(G);
    printf("\n");
    return 0;
}