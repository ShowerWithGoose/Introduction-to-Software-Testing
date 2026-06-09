//
//  main.c
//  1
//
//  Created by  on 2024/6/6.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
    int adjvex;
    int weight;
    struct edge *next;
}ELink;
typedef struct ver
{
    int vertex;
    ELink *link;
}VLink;

VLink graph [200];
int vertexnum=0;
int edgenum=0;
int deletnum=0;
int Visited [200]={0};
int VISITED [200]={0};
int table [100] [3];
int k=0;
int front=0;
int rear=0;
int Queue [200];

void createGraph (void);
void bubble (void);
ELink *insertedge (ELink*,int);
void travelDFS (void);
void DFS (int);
void travelBFS (void);
void BFS (int);
void enQueue (int);
int deQueue (void);
int emptyQ (void);
void travelDFSde (void);
void DFSde (int);
void travelBFSde (void);
void BFSde (int);

int main(int argc, const char * argv[])
{
    scanf("%d%d",&vertexnum,&edgenum);
    bubble();
    scanf("%d",&deletnum);
    createGraph();
    travelDFS();
    printf("\n");
    travelBFS();
    printf("\n");
    travelDFSde();
    printf("\n");
    travelBFSde();
    printf("\n");
    return 0;
}

void bubble (void)
{
    int t1,t2;
    for(int i=0;i<edgenum;i++)
    {
        scanf("%d%d",&table[k][0],&table[k][1]);
        k++;
    }
    for(int i=0;i<edgenum;i++)
    {
        if(table[i][0]>table[i][1])
        {
            t1=table[i][0];
            table[i][0]=table[i][1];
            table[i][1]=t1;
        }
    }
    for(int i=0;i<edgenum;i++)
    {
        for(int j=0;j<edgenum-i-1;j++)
        {
            if(table[j][0]>table[j+1][0])
            {
                t1=table[j][0];
                t2=table[j][1];
                table[j][0]=table[j+1][0];
                table[j][1]=table[j+1][1];
                table[j+1][0]=t1;
                table[j+1][1]=t2;
            }
            else if (table[j][0]==table[j+1][0])
            {
                if(table[j][1]>table[j+1][1])
                {
                    t1=table[j][1];
                    table[j][1]=table[j+1][1];
                    table[j+1][1]=t1;
                }
            }
        }
    }
}

void createGraph (void)
{
    int a,b;
    for(int i=0;i<edgenum;i++)
    {
        a=table[i][0];
        b=table[i][1];
        graph[a].vertex=a;
        graph[b].vertex=b;
        graph[a].link=insertedge(graph[a].link, b);
        graph[b].link=insertedge(graph[b].link, a);
    }
}

ELink *insertedge (ELink* head,int avex)
{
    ELink *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->adjvex= avex; e->weight=1; e->next=NULL;
    if(head == NULL)
    {
        head=e;
        return head;
    }
    for(p=head;p->next != NULL; p=p->next);
    p->next = e;
    return head;
}

void travelDFS(void)
{
    int i;
    for (i = 0; i < vertexnum; i++)
        if (!Visited[i])
            DFS(i);
}

void DFS(int v)
{
    ELink *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",graph[v].vertex);
    for (p = graph[v].link; p != NULL; p = p->next)
        if (!Visited[p->adjvex])
            DFS(p->adjvex);
}

void travelBFS(void)
{
    int i;
    for (i = 0; i < vertexnum; i++)
        if (!VISITED[i])
            BFS(i);
}

void BFS(int v){
    ELink *p;
    printf("%d ",graph[v].vertex);
    VISITED[v] = 1; //标识某顶点被访问过
    enQueue(v);
    while (emptyQ()!=0)
    {
        v = deQueue(); //取出队头元素
        if(graph[v].link!=NULL)
        {
            p = graph[v].link; //获取该顶点第一个邻接顶点
            //访问该顶点下的每个邻接顶点
            for (; p != NULL; p = p->next)
            if (!VISITED[p->adjvex])
            {
                printf("%d ",p->adjvex);
                VISITED[p->adjvex] = 1; //标识某顶点被访问过
                enQueue(p->adjvex);
            }
        }
    }
}

void enQueue (int a)
{
    Queue[rear++]=a;
}

int deQueue (void)
{
    return Queue[front++];
}

int emptyQ (void)
{
    if(front==rear)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void travelDFSde (void)
{
    int i;
    for (i = 0; i < vertexnum; i++)
    {
        Visited[i]=0;
    }
    for (i = 0; i < vertexnum; i++)
        if (!Visited[i]&&i!=deletnum)
            DFSde(i);
}
void DFSde (int v)
{
    ELink *p;
    Visited[v] = 1; //标识某顶点被访问过
    if(graph[v].vertex!=deletnum)
    {
        printf("%d ",graph[v].vertex);
        for (p = graph[v].link; p != NULL; p = p->next)
            if (!Visited[p->adjvex])
                DFSde(p->adjvex);
    }
}

void travelBFSde(void)
{
    int i;
    rear=front=0;
    for(int i=0;i<vertexnum;i++)
    {
        VISITED[i]=0;
    }
    for (i = 0; i < vertexnum; i++)
        if (!VISITED[i]&&i!=deletnum)
            BFSde(i);
}

void BFSde(int v){
    ELink *p;
    if(graph[v].vertex!=deletnum)
    {
        printf("%d ",graph[v].vertex);
        VISITED[v] = 1; //标识某顶点被访问过
        enQueue(v);
        while (emptyQ()!=0)
        {
            v = deQueue(); //取出队头元素
            if(graph[v].link!=NULL)
            {
                p = graph[v].link; //获取该顶点第一个邻接顶点
                //访问该顶点下的每个邻接顶点
                for (; p != NULL; p = p->next)
                if ((VISITED[p->adjvex]!=1)&&p->adjvex!=deletnum)
                {
                    printf("%d ",p->adjvex);
                    VISITED[p->adjvex] = 1; //标识某顶点被访问过
                    enQueue(p->adjvex);
                }
            }
        }
    }
}



