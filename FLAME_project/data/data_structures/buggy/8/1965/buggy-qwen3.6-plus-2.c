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
    }
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
}


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
    enQueue(v);
    while(front!=rear){
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
        if(v==deleteVno) // @@ The deleted vertex is never visited in travelDFS1 because of the check `i!=deleteVno`, so this condition is redundant but harmless. However, the logic fails to skip neighbors that are the deleted vertex.
            continue;
        if(Visited[p->adjvex]==0&&p->adjvex!=-1) // @@ The check `p->adjvex!=-1` relies on deleteVex marking nodes as -1. However, deleteVex only marks edges pointing TO the deleted vertex. It does not remove the deleted vertex's own adjacency list. If the deleted vertex's list is traversed, it might cause issues, but more importantly, we must ensure we don't traverse INTO the deleted vertex. The current deleteVex sets adjvex to -1 for edges pointing to deleteVno. This check handles that. But wait, look at deleteVex.
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
    enQueue(v);
    while(front!=rear){
         v=deQueue(Q);
         p=G[v].link;
         for(; p != NULL ; p=p->next )
         {
             if(v==deleteVno) // @@ Similar to DFS1, this check is inside the loop but 'v' is the current node being processed. Since we never start BFS1 from deleteVno, and we don't enqueue it, this check is likely unreachable or incorrect context. The real issue is skipping neighbors that are the deleted vertex.
                continue;
             if(Visited[p->adjvex]==0&&p->adjvex!=-1) { // @@ This checks if the neighbor is marked as -1 (deleted). This depends on deleteVex working correctly.
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
}

void deleteVex(int num)
{
    ELink *p=NULL;
    int i;
    for(i=0;i<vno;i++)
    {
        for(p=G[i].link;p!=NULL&&i!=num;p=p->next) // @@ The condition `i!=num` prevents cleaning up the adjacency list of the deleted vertex itself. While we won't start traversal from it, its edges might still be referenced if not cleaned, or it might just be wasted memory. More critically, this loop fails to remove edges FROM other vertices TO num if the loop terminates early? No, it iterates all p. But it skips processing if `i==num`. This means the adjacency list of the deleted vertex remains intact. This is generally okay if we never visit it, BUT the main issue is usually removing edges pointing TO num.
        {
            if(p->adjvex==num)
                p->adjvex=-1; // @@ Marking as -1 is a lazy deletion. This works if the traversal checks for -1.
        }
    }
    return;
}