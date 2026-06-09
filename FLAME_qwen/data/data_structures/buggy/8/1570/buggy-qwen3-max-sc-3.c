#include<stdio.h>
#include<stdlib.h>

#define MAXV 105
 
typedef struct edge{
    int adj;
    int wei;
    struct edge *next;
}Elink;
typedef struct ver{
    Elink *link;
}Vlink;
Vlink G[MAXV];

int Nd,Nb,pos;//顶点个数、边的个数、删除位置 
 
void create(Vlink graph[]);//创建邻接表
Elink *insert(Elink *head,int avex);
void travelDFS(Vlink graph[],int k);
void travelBFS(Vlink graph[],int k); 
void DFS(Vlink graph[],int v);
void BFS(Vlink graph[],int v);
int Visited[MAXV]={0};

int Q[MAXV];
int front,rear,count;
void initQueue();
int isEmpty();
void enQueue(int queue[],int item);
int deQueue(int queue[]);

int main()
{
    //输入 
    scanf("%d%d",&Nd,&Nb);
    create(G);
    //读入删除位置
    scanf("%d",&pos);
    
    travelDFS(G,-1); 
    travelBFS(G,-1);
    travelDFS(G,pos);
    travelBFS(G,pos);
    
    return 0;
} 

void create(Vlink graph[])
{
    int i,v1,v2;
    for(i=0;i<Nb;i++)
    {
        scanf("%d%d",&v1,&v2);
        graph[v1].link=insert(graph[v1].link,v2);
        graph[v2].link=insert(graph[v2].link,v1); 
    }
}
Elink *insert(Elink *head,int avex) 
{
    Elink *e,*p,*q;
    e=(Elink*)malloc(sizeof(Elink));
    e->adj=avex;e->wei=1;e->next=NULL;
    
    if(head==NULL)
    {
        head=e;
        return head;
    }
    ///////////////////////////////////////////////////////////////////////////////////问题始终出现在此处 
    //for(p=head;(p!=NULL)&&(avex>p->adj);p=p->next);//此处实现插入位置的有序性 
    //q=p;p=e;p->next=q;
    for(p=head;p->next!=NULL&&avex>p->next->adj;p=p->next);    /////////////////////此处注意！！！ 
    q=p->next;p->next->next=q;p->next=e; // @@ [This line has incorrect pointer manipulation. It should insert 'e' between 'p' and 'p->next', but instead it sets p->next->next = q (which is redundant) and then overwrites p->next with e, losing the original p->next. Also, if avex is smaller than head->adj, this loop doesn't handle insertion at the front.]

    /*for(p=head;(p!=NULL)&&(avex>p->adj);q=p,p=p->next);
    if(p==head)
    {
        e->next=p;
        return e;
    }
    else
    {
        q->next=e;e->next=p;return head;
    }*/
    return head;
}
void travelDFS(Vlink graph[],int k)
{
    //当k的值为-1时表示删除前，否则K为删除的位置下标――>(直接置其访问标志为1是否可行）  
    //访问操作为输出 
    int i;
    for(i=0;i<Nd;i++)Visited[i]=0;
    if(k!=-1)Visited[k]=1;
    
    for(i=0;i<Nd;i++)
        if(!Visited[i])
            DFS(graph,i);
    printf("\n");
}
void DFS(Vlink graph[],int v)
{
    Elink *p;
    Visited[v]=1;
    printf("%d ",v);
    
    for(p=graph[v].link;p!=NULL;p=p->next)
        if(!Visited[p->adj])
            DFS(graph,p->adj);
}

void travelBFS(Vlink graph[],int k)
{
    //当k的值为-1时表示删除前，否则K为删除的位置下标 
    //访问操作为输出 
    int i;
    for(i=0;i<Nd;i++)Visited[i]=0;
    if(k!=-1)Visited[k]=1;
    
    for(i=0;i<Nd;i++)
        if(!Visited[i])
            BFS(graph,i);
    printf("\n");
}
void BFS(Vlink graph[],int v) 
{
    Elink *p;
    initQueue(); 
    //printf("%d ",v);
    Visited[v]=1;
    enQueue(Q,v);//需要建一个队列（对 图.c 进行相应操作）
    while(!isEmpty(Q))
    {
        v=deQueue(Q);
        printf("%d ",v);
        
        for(p=graph[v].link;p!=NULL;p=p->next)
            if(!Visited[p->adj])
            {
                //printf("%d ",p->adj);
                Visited[p->adj]=1;
                enQueue(Q,p->adj);
            }
    } 
}
//队列相关函数 

void initQueue()
{
    front=0;
    rear=MAXV-1;
    count=0;
}    
int isEmpty()
{
    return count==0;
}
void enQueue(int queue[],int item)
{
    rear=(rear+1)%MAXV;
    queue[rear]=item;
    count++;
} 
int deQueue(int queue[])
{
    int e;
    e=queue[front];
    count--;
    front=(front+1)%MAXV;
    return e;
}