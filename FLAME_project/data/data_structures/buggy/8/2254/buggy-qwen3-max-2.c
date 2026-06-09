#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MaxV 256
typedef struct edge{
    int adj;
    int wei;
    struct edge *next;
}Elink;
typedef struct ver{
    Elink *link;
}Vlink;
void createGraph(Vlink gragh[]);
void travelBFS(Vlink G[],int n,int x);
void travelDFS(Vlink G[],int n,int x);
Elink *insertEdge(Elink *head,int avex);
Vlink graph[MaxV];
int n,m; 
int main()
{
    scanf("%d%d",&n,&m);
    createGraph(graph);
    travelDFS(graph,n,-1);
    travelBFS(graph,n,-1);
    int x;
    scanf("%d",&x);
    travelDFS(graph,n,x);
    travelBFS(graph,n,x);
    return 0;
}
void createGraph(Vlink gragh[])
{
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link,v2);
        graph[v2].link=insertEdge(graph[v2].link,v1);
    }
}
Elink *insertEdge(Elink *head,int avex)
{
    Elink *e,*p,*q=NULL;
    e=(Elink *)malloc(sizeof(Elink));
    e->adj=avex;e->wei=1;e->next=NULL;
    if(head==NULL)
    {
        head=e;
        return head;
    }
 for(p=head; p->next != NULL; p=p->next)
        ;
    p->next = e;
    return head;

}
int Visited[MaxV]={0};
void DFS(Vlink G[],int v)
{
    Elink *p;
    Visited[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
    if(!Visited[p->adj])
    DFS(G,p->adj);
}
void travelDFS(Vlink G[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
    Visited[i]=0;
        if(x>=0)
    Visited[x]=1;
    for(i=0;i<n;i++)
    if(!Visited[i])
    DFS(G,i);
    printf("\n");
}
#define MAXSIZE 1000
int Q[MAXSIZE]; 
int rear=MAXSIZE-1,front=0,count=0;
int emptyQ(void)
{
    if(count==0)
    return 1;
    else
    return 0;
}
void enQueue(int queue[],int item)
{
    rear=(rear+1)%MAXSIZE;
    queue[rear]=item;
    count++;
}
int deQueue(int queue[])
{
    int e;
    e=queue[front];
    count--;
    front=(front+1)%MAXSIZE;
    return e;
}
void BFS(Vlink G[],int v)
{
    Elink *p;
    Visited[v]=1;
    enQueue(Q,v);
    while(!emptyQ( ))
    {
        v=deQueue(Q);
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next)
        if(!Visited[p->adj])
        {
            Visited[p->adj]=1;
            enQueue(Q,p->adj);
        }
    }
}
void travelBFS(Vlink G[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
    Visited[i]=0;
    if(x>=0)
    Visited[x]=1;
    for(i=0;i<n;i++)
    {
        if(!Visited[i])
        BFS(G,i);
        printf("\n"); // @@ [This printf("\n") is inside the for-loop, causing a newline after each connected component. Since the graph is connected (per problem statement), this results in only one traversal but still prints a newline immediately after it. However, more critically, when the deleted vertex disconnects nothing (graph remains connected), it's okay, but the real issue is that in the original reference, the newline is printed once after the entire BFS. Here, even for a single component, it prints a newline right after BFS(G,i), and since the loop runs n times, but only one component is traversed, it still prints one newline — BUT the bigger error is that the BFS function itself does not reset the queue state, and global queue variables are reused without reinitialization between calls. However, the most visible formatting error causing WA is the extra newlines: the expected output has exactly 4 lines, but this code may output more due to misplaced newline. Actually, looking at test output: buggy output shows two blank lines between first two and last two outputs. The real issue is that in travelBFS, the printf("\n") is inside the for-loop, so after processing vertex 0 (the only unvisited), it prints the BFS sequence and then a newline. But then i continues from 1 to n-1, and for each i, if visited, it skips BFS but still executes printf("\n") — NO! Wait: the printf("\n") is inside the for-loop body but NOT inside the if(!Visited[i]) block. So for every i from 0 to n-1, it prints a newline! That means for n=3, it prints 3 newlines after the BFS sequence, which matches the buggy output showing an extra blank line. This is the critical error.]
    }
}