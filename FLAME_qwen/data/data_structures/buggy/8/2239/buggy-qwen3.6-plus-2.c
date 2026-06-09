#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define maxv 256
int visited[256]={0};
typedef struct edge{
    int adj;
    int wei;
    struct edge *next;
}elink;
typedef struct ver{
    elink *link;
}vlink;
vlink g[maxv];
int shan;
int flag=1;
//elink *insertedge(elink *head,int avex)
//{
//    elink *e,*p,*q;
//    e=(elink *)malloc(sizeof(elink));
//    e->adj=avex;
//    e->wei=1;
//    e->next=NULL;
//    if (head==NULL)
//    {
//        head=e;
//        return head;
//    }
//
//    for (q=head,p=head;p->next!=NULL;p=p->next)
//        ;
//    p->next=e;        
//
//    return head;
//} 
elink *insertedge(elink *head,int avex)
{
    elink *e,*p,*q;
    e=(elink *)malloc(sizeof(elink));
    e->adj=avex;
    e->wei=1;
    e->next=NULL;
    if (head==NULL)
    {
        head=e;
        return head;
    }
    int flag=1;
    for (q=head,p=head;p->next!=NULL;q=p) // @@ Logical error: The loop initialization and condition prevent checking the first node. p starts at head->next, making it impossible to insert a smaller value before the head node.
    {
        p=p->next;
        if (avex<p->adj)
        {
            if (p==head) // @@ Logical error: p is always head->next or later here, so p==head is never true. The code cannot handle insertion before the first node.
            {
                e->next=p;
                head=e;
                flag=0;
                break;
            }
            else 
            {
                e->next=p;
                q->next=e;
                flag=0;
                break;            
            }
        }
    }
    if (flag==1)
    {
        p->next=e; // @@ Logical error: Fails to maintain sorted order when the list has only one node or when avex should be inserted before the first node, violating the requirement to visit adjacent vertices in ascending order.
    }

    return head;
} 
int bian,dian;
void creategraph(vlink graph[])
{
    int v1,v2;
    for (int i=0;i<bian;i++)
    {
        scanf("%d%d",&v1,&v2);
        graph[v1].link=insertedge(graph[v1].link,v2);
        graph[v2].link=insertedge(graph[v2].link,v1);        
    }
}

void dfs(vlink g[],int v)
{
    elink *p;
    visited[v]=1;
    printf("%d ",v);
    for (p=g[v].link;p!=NULL;p=p->next)
    {
        if (!visited[p->adj])
        {
            dfs(g,p->adj);
            
        }
    }
}
void traveldfs(vlink g[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        visited[i]=0;
    }
    if (flag==0)
    {
        visited[shan]=1;
    }
    for (i=0;i<n;i++)
    {
        if (!visited[i])
        {
            dfs(g,i);
        }
    }
    
}

int count=0;
int front=0;
int rear=maxv-1;
int queue[maxv];
void bfs(vlink g[],int v)
{
    elink *p;
    visited[v]=1;
    rear=(rear+1)%maxv;
    queue[rear]=v;
    count+=1;
    while (count!=0)
    {
        v=queue[front];
        count--;
        front=(front+1)%maxv;
        printf("%d ",v);
        for (p=g[v].link;p!=NULL;p=p->next)
        {
            if (!visited[p->adj])
            {
                visited[p->adj]=1;
                rear=(rear+1)%maxv;
                queue[rear]=p->adj;
                count+=1;        
            }
        }
    }
    
}
void travelbfs(vlink g[],int n)
{
    int i;
    count=0;
    front=0;
    rear=maxv-1;
    for (int j=0;j<maxv;j++)
    {
        queue[j]=0;
    }
    for (i=0;i<n;i++)
    {
        visited[i]=0;
    }
    if (flag==0)
    {
        visited[shan]=1;
    }
    for (i=0;i<n;i++)
    {
        if (!visited[i])
        {
            bfs(g,i);
        }
    }
}

//void deleted(vlink g[],int n,int ss)
//{
//    for (int i=ss+1;i<n;i++)
//    {
//        g[i-1]=g[i];
//    }
//    for (int i=0;i<n-1;i++)
//    {
//        elink *p,*q;    
//        for (q=g[i],p=g[i];p->next!=NULL;q=p)
//        {
//            p=p->next;
//            if (ss==p->adj)
//            {
//                q->next=p->next;
//                break;
//            }
//        }        
//    }
//}
int main()
{
    scanf("%d%d",&dian,&bian);
    creategraph(g);
    traveldfs(g,dian);
    printf("\n");
    travelbfs(g,dian);
    printf("\n");
    scanf("%d",&shan);
//    deleted(g,dian,shan);
//    dian-=1;
    flag=0;
    traveldfs(g,dian);
    printf("\n");
    travelbfs(g,dian);    
    

    return 0;
    
}