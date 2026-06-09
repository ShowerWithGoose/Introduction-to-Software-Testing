#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define maxV 105
int V,l;
int visited[maxV];
int front,rear;
void enQueue(int Queue[],int v)
{
	Queue[++rear]=v;
}
int deQueue(int Queue[])
{
	int temp;
	temp=Queue[front++];
	return temp;
}
struct edge{
	int adjvex;
	struct edge*next;
};
struct ver{
	struct edge*link;
};
struct ver G[maxV];
struct edge*insertEdge(struct edge*head,int adjv)
{
	struct edge*e,*p;
    e =(struct edge*)malloc(sizeof(struct edge));
    e->adjvex=adjv;
	e->next=NULL;
    if(head == NULL)  
	{ 
		head=e; 
		return head;
	}
	if(head->adjvex>adjv)
	{
		e->next=head;
		return e;
	}
    for(p=head; p->next!=NULL&&p->next->adjvex<adjv; p=p->next)
        ;
    e->next=p->next;
    p->next=e;  
    return head;
}
struct edge*deleteEdge(int del_v)
{
	int i;
	struct edge*p,*q;
	for(i=0;i<V;i++)
	{
		if(i==del_v)
		{
			p=G[i].link;
			while(!p)
			{
				q=p;
				p=p->next;
				free(q);
			}
			G[i].link=NULL;
		}
		else
		{
			if(G[i].link->adjvex==del_v)//特判 
			{
				p=G[i].link; 
				G[i].link=G[i].link->next;
				free(p);
				continue;
			}
			for(p=G[i].link->next,q=G[i].link;p!=NULL;p=p->next,q=q->next)
			{
				if(p->adjvex==del_v)
				{
					q->next=p->next;
					free(p);
					break;
				}
			}
		}
	}
}
void DFS(struct ver G[],int v)
{
	struct edge*p;
	printf("%d ",v);
	visited[v]=1;
	p=G[v].link;
	while(p)
	{
		if(visited[p->adjvex]==0)
		{
			DFS(G,p->adjvex);
		}
		p=p->next;
	}
}
void BFS(struct ver G[ ], int v)
{
 	int Queue[500];
 	struct edge*p;
 	front=0,rear=-1;
    visited[v] = 1;
    enQueue(Queue,v);
    while(front<=rear)
	{
         v = deQueue(Queue);  //取出队头元素
         printf("%d ",v);
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
            if( !visited[p->adjvex] )
			{
                visited[p->adjvex] = 1; //标识某顶点入队
                enQueue(Queue,p->adjvex);
            }
     }
}
int main()
{
	int i;
	int v1,v2;
	int del_v;
	scanf("%d%d",&V,&l);
	for(i=1;i<=l;i++)
	{
		scanf("%d%d",&v1,&v2);
      	G[v1].link=insertEdge(G[v1].link,v2);
		G[v2].link=insertEdge(G[v2].link,v1);
	}
	DFS(G,0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(G,0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	scanf("%d",&del_v);
	deleteEdge(del_v);
	DFS(G,0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(G,0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	return 0;
}

