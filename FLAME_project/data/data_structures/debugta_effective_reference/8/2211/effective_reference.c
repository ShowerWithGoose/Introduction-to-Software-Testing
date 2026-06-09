#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct elink
{
	int adj;
	struct elink *next;
};
struct vlink
{
	struct elink *link;
};
struct vlink graph[105];
int visited[105],visited[105];
struct elink *insertEdge(struct elink *head,int ver,int );
void travelDFS(struct vlink graph[],int ver_num);
void dfs(struct vlink graph[],int ver);
void travelBFS(struct vlink graph[],int ver_num);
void bfs(struct vlink graph[],int ver);
int main()
{
	int ver_num,edge_num,v1,v2,de_note,i,j;
	scanf("%d%d",&ver_num,&edge_num);
	for(i=0;i<edge_num;i++)
	{
		scanf("%d%d",&v1,&v2);
		//printf("%d %d\n",v1,v2);
		graph[v1].link=insertEdge(graph[v1].link,v2,v1);
		graph[v2].link=insertEdge(graph[v2].link,v1,v2);
	}
	scanf("%d",&de_note);
	//printf("%d %d \n",graph[0].link->adj,graph[0].link->next->adj);
	travelDFS(graph,ver_num);
	printf("\n");
	travelBFS(graph,ver_num);
	for(i=0;i<ver_num;i++)
	{
		visited[i]=0;
		visited[i]=0;
	}
	visited[de_note]=1;
	visited[de_note]=1;
	printf("\n");
	travelDFS(graph,ver_num);
	printf("\n");
	travelBFS(graph,ver_num);
	return 0;
}
struct elink *insertEdge(struct elink *head,int ver,int v1)
{
	struct elink *e,*p;
	e=(struct elink*)malloc(sizeof(struct elink));
	e->adj=ver;
	e->next=NULL;
	if(head==NULL)
	{
		head=(struct elink*)malloc(sizeof(struct elink));
		head->next=NULL;
		head->adj=v1;
		e->next=head->next;
		head->next=e;
		return head;
	}
	else
	{
		for(p=head;p->next!=NULL;p=p->next)
		{
			//printf("!\n");
			if(p->next->adj>ver)
			{
				//printf("! %d\n",head->adj);
				e->next=p->next;
				p->next=e;
				return head;
			}
		}
		p->next=e;
		return head; 
	}
}
void travelDFS(struct vlink graph[],int ver_num)
{
	int i;
	for(i=0;i<ver_num;i++)
	{
		if(visited[i]==0)
		dfs(graph,i);
	}
}
void dfs(struct vlink graph[],int ver)
{
	struct elink *p;
	visited[ver]=1;
	printf("%d ",ver);
	for(p=graph[ver].link;p!=NULL;p=p->next)
	{
		if(visited[p->adj]==0)
		dfs(graph,p->adj);
	}
}
int queue[505],front,rear;
void travelBFS(struct vlink graph[],int ver_num)
{
	int i;
	for(i=0;i<ver_num;i++)
	{
		if(visited[i]==0)
		bfs(graph,i);
	}
}
void bfs(struct vlink graph[],int ver)
{
	struct elink *p;
	printf("%d ",ver);
	visited[ver]=1;
	queue[rear++]=ver;
	while(front<rear)
	{
		ver=queue[front++];
		p=graph[ver].link;
		for(;p!=NULL;p=p->next)
		{
			if(visited[p->adj]==0)
			{
				printf("%d ",p->adj);
				visited[p->adj]=1;
				queue[rear++]=p->adj;
			}
		}
	}
}
/*
4 6
0 3
0 2
3 2
2 1
0 1
3 1
2
*/
/*
9 10

0 2

0 1

1 4

1 3

1 8

8 6

3 6

7 2

7 5

5 2

3
*/


