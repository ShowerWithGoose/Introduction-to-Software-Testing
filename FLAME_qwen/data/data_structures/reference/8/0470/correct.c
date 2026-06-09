#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int visited[20]={0};
typedef struct graph
{
int  adj;
struct graph*  next;
}elink;

typedef struct ver
{
       elink*  link;
}vlink;
vlink g[256];

elink  *insertEdge(elink *head, int avex)
{
    elink *e,*p,*q;
    e =(elink *)malloc(sizeof(elink));
    e->adj= avex; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    q=head;
	for(p=head; p!= NULL; q=p,p=p->next)
        {
        	if(e->adj<p->adj)
        	{
        		if(p==head)
        		{
				e->next=p;
				head=e;
				return head;
			}
			e->next=p;
			q->next=e; 
			return head;
			}
		}
	q->next = e;  
    return head;
}

void dfs(vlink h[],int v)
{
    elink  *p;
    visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for(p = g[v].link; p !=NULL;  p=p->next)
         if( !visited[p->adj] )
             dfs(g, p->adj);
}

int queue[100];
int front=0,rear=0;
void enQueue(int v)
{
queue[rear++]=v;
}
int empty()
{
	return front==rear;
}
int deQueue()
{
	return queue[front++];
}

void bfs(vlink h[],int v)
{
	elink  *p;
    visited[v] = 1; //标识某顶点已入队
    enQueue(v);
    while(!empty()){
         v = deQueue();  //取出队头元素
         printf("%d ",v);//访问当前顶点
         for(p=g[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !visited[p->adj] ) {
                    visited[p->adj] = 1; //标识某顶点入队
                    enQueue(p->adj);           
					}
}
}

int main()
{
int num1;
int num2;
scanf("%d %d",&num1,&num2);
int i=0;
int b1,b2;
for(;i<num2;i++)
{
	scanf("%d %d",&b1,&b2);
	g[b1].link=insertEdge(g[b1].link, b2);
	g[b2].link=insertEdge(g[b2].link, b1);
}
    for(i=0; i<num1; i++) visited[i] = 0 ;//
    for(i=0; i<num1; i++)
        if( !visited[i] ) dfs(g, i);
        printf("\n");
    for(i=0; i<num1; i++) visited[i] = 0 ;//
    for(i=0; i<num1; i++)
        if( !visited[i] ) bfs(g, i);
        printf("\n");
        int c;
        scanf("%d",&c);
        for(i=0; i<num1; i++) visited[i] = 0 ;//
        visited[c]=1;
    for(i=0; i<num1; i++)
        if( !visited[i] ) dfs(g, i);
        printf("\n");
    for(i=0; i<num1; i++) visited[i] = 0 ;//
    visited[c]=1;
    for(i=0; i<num1; i++)
        if( !visited[i] ) bfs(g, i);
return 0;
}


