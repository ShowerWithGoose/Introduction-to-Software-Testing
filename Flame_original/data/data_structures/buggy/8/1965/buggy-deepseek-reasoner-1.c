#include<stdio.h>
#include<stdlib.h>
#define vertype int
#define MAXV 110
typedef struct edge{    //边结点类型
int adjvex;
struct edge *next;
}ELink;
typedef struct ver{     //顶点节点类型
int vertex;
ELink *link;
}VLink;
VLink G[MAXV];

int Visited[MAXV]={0};
int vno,eno;
int Q[110];
int front=-1,rear=-1;
int deleteVno;
void createGraph();
ELink *insertEdge(ELink *head,int avex);
void travelDFS();
void DFS(int v);
void travelBFS();
void BFS(int v);
void travelDFS1();
void DFS1(int v);
void travelBFS1();
void BFS1(int v);
int deQueue();
void enQueue(int num);
void deleteVex(int num);
int temp1[110],temp2[110],temp3[110],temp4[110],i1=0,i2=0,i3=0,i4=0;
int main()
{
    createGraph();
    int i=0;
    for(i=0;i<vno;i++)
    {
        ELink *p;
        for(p=G[i].link;p!=NULL;p=p->next)
            printf("%d ",p->adjvex);
        printf("\n");
    } // @@ 此处打印了邻接表，这是题目不要求的额外输出，会导致结果错误。
    travelDFS();
    travelBFS();
    scanf("%d",&deleteVno);
    //printf("%d\n",deleteVno);
    deleteVex(deleteVno);
    travelDFS1();
    travelBFS1();
    for(i=0;i<i1;i++)
        printf("%d ",temp1[i]);
    printf("\n");
    for(i=0;i<i2;i++)
        printf("%d ",temp2[i]);
    printf("\n");
    for(i=0;i<i3;i++)
        printf("%d ",temp3[i]);
    printf("\n");
    for(i=0;i<i4;i++)
        printf("%d ",temp4[i]);
    printf("\n");
    return 0;
}


void createGraph()
{
    int i,v1,v2;
    scanf("%d%d",&vno,&eno);
    for(i=0;i<vno;i++) G[i].link = NULL; // @@ 缺少初始化邻接表头指针，导致未定义行为。
    for(i=0;i<eno;i++)
    {
        scanf("%d%d",&v1,&v2);
        //printf("%d %d\n",v1,v2);
        G[v1].link=insertEdge(G[v1].link,v2);  //在链表尾插入一个结点
        G[v2].link=insertEdge(G[v2].link,v1);
    }
    return;
}
ELink *insertEdge(ELink *head,int avex)
{
    ELink *e,*p;
    e=(ELink*)malloc(sizeof(ELink));
    e->adjvex=avex;
    e->next=NULL;
    if(head==NULL)
    {
        head=e;
        return head;
    }
    else
    {
        if(head->next==NULL&&head->adjvex<avex)
            head->next=e;
        else if(head->adjvex>avex)
        {
            e->next=head;
            head=e;
        }
        else
        {
            for(p=head; p->next!=NULL; p=p->next)
            {
                if(p->adjvex < avex&&p->next->adjvex >avex)
                    break;
            }
            e->next=p->next;
            p->next=e;
        }
        return head;
    }
} // @@ 插入函数逻辑复杂且存在缺陷，例如当新结点应插入在最后一个结点之后但p->next==NULL时，循环结束后没有处理；且重复边可能被插入多次。建议使用参考程序中的有序插入方式。


void travelDFS()
{
    int i=0;
    for(i=0;i<vno;i++)
    {
        Visited[i]=0;
    }
    for(i=0;i<vno;i++)
    {
        if(Visited[i]==0)
            DFS(i);
    }
    return;
}

void DFS(int v)
{
    ELink *p=NULL;
    Visited[v]=1;
    temp1[i1++]=v;
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(Visited[p->adjvex]==0)
            DFS(p->adjvex);
    }
    return;
}

void travelBFS()
{
    int i;
    for(i=0; i<vno; i++)
        Visited[i]=0;
    for(i=0; i<vno; i++)
        if(Visited[i]==0)
           BFS(i);
    return;
}

void BFS(int v)
{
    ELink  *p;
    temp2[i2++]=v;
    Visited[v]=1;
    front = -1; rear = -1; // @@ 缺少队列初始化，导致之前调用残留的数据影响本次遍历。
    enQueue(v);
    while(front!=rear){ // @@ 条件错误，应为 while(front < rear) 或类似；当前条件使得循环只执行一次，无法遍历所有结点。
         v=deQueue(Q);
         p=G[v].link;
         for(; p != NULL ; p = p->next )
         {
             if(Visited[p->adjvex]==0) {
                    temp2[i2++]=p->adjvex;
                    Visited[p->adjvex] = 1;
                    enQueue(p->adjvex);
             }
         }

     }
     return;
}




void travelDFS1()
{
    int i=0;
    for(i=0;i<vno;i++)
    {
        Visited[i]=0;
    }
    for(i=0;i<vno;i++)
    {
        if(Visited[i]==0&&i!=deleteVno)
            DFS1(i);
    }
    return;
}

void DFS1(int v)
{
    ELink *p=NULL;
    Visited[v]=1;
    temp3[i3++]=v;
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(v==deleteVno) // @@ 此条件永远不成立，因为调用DFS1时v必然不是deleteVno，属于冗余代码。
            continue;
        if(Visited[p->adjvex]==0&&p->adjvex!=-1)
            DFS1(p->adjvex);
    }
    return;
}

void travelBFS1()
{
    int i;
    for(i=0; i<vno; i++)
        Visited[i]=0;
    for(i=0; i<vno; i++)
        if(Visited[i]==0&&i!=deleteVno)
           BFS1(i);
    return;
}

void BFS1(int v)
{
    ELink  *p;
    temp4[i4++]=v;
    Visited[v]=1;
    front = -1; rear = -1; // @@ 缺少队列初始化。
    enQueue(v);
    while(front!=rear){ // @@ 同BFS中的错误，条件导致只处理一个顶点。
         v=deQueue(Q);
         p=G[v].link;
         for(; p != NULL ; p=p->next )
         {
             if(v==deleteVno) // @@ 此条件永远不成立，因为v不是deleteVno。
                continue;
             if(Visited[p->adjvex]==0&&p->adjvex!=-1) {
                    temp4[i4++]=p->adjvex;
                    Visited[p->adjvex] = 1;
                    enQueue(p->adjvex);
             }
         }
     }
     return;
}

int deQueue()
{
    int num;
    num=Q[++front];
    return num;
}

void enQueue(int num)
{
    if(rear==MAXV-1)
        return;
    else
    {
        Q[++rear]=num;
        return;
    }
} // @@ 队列未实现循环，且没有处理空队列情况；但这里的主要问题是条件错误，不影响队列本身的正确性。

void deleteVex(int num)
{
    ELink *p=NULL;
    int i;
    for(i=0;i<vno;i++)
    {
        for(p=G[i].link;p!=NULL&&i!=num;p=p->next)
        {
            if(p->adjvex==num)
                p->adjvex=-1;
        }
    }
    return;
} // @@ 将边标记为-1的方式可以接受，但注意没有从被删顶点的邻接表中删除边（因为该顶点后续不会访问）。