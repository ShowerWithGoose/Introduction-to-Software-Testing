#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct edge{
	int adjvex;
	int weight;
	struct edge* link;
};
struct ver{
	struct edge* link;
};
struct ver G[1000];
int numv,nume,visited[1000],flag=0;
struct edge* insertG(int v1,struct edge* head,int v)
{
	struct edge *e,*p=head;
	e=(struct edge*)malloc(sizeof(struct edge));
	e->weight=1; e->link=NULL; e->adjvex=v;
	if(head==NULL)
	{
		head=e; return head;
	}
	if(head->adjvex > v)
	{
		G[v1].link=e; e->link=head;
		return G[v1].link;
	}
	while(p->link!=NULL && p->link->adjvex < v) //排序 
	{
		p=p->link;
	}
	e->link=p->link;
	p->link=e;
	return head;
}
void DFS(int v,int delate)
{
	struct edge* p=G[v].link;
	visited[v]=1;
	printf("%d ",v);
	while(p!=NULL)
	{
		if(visited[p->adjvex]==0 && (flag==0 || p->adjvex!=delate))
			DFS(p->adjvex,delate); 
		p=p->link;
	}
}
void travelDFS(int delate)
{
	int i=0; memset(visited,0,1000);
	while(i<numv)
	{
		if(visited[i]==0 && (flag==0 || i!=delate))
			DFS(i,delate);
		i++;
	}
}
int queue[1000],rear=-1,front=-1;
void push(int v)
{
	rear++;
	queue[rear]=v;
}
int pop()
{
	front++;
	printf("%d ",queue[front]);
	return queue[front];
}
void BFS(int v,int delate)
{
	struct edge* p;
	int ver; 
	push(v);
	visited[v]=1;
	while(rear-front!=0)
	{
		ver=pop();
		p=G[ver].link;
		while(p!=NULL)
		{
			if(visited[p->adjvex]==0 && (flag==0 || p->adjvex != delate))
			{
				visited[p->adjvex]=1;
				push(p->adjvex);
			}
			p=p->link;
		}
	}
}
void travelBFS(int delate)
{
	int i=0; memset(visited,0,1000);
	while(i<numv)
	{
		if(visited[i]==0 && (flag==0 || i!=delate))
			BFS(i,delate);
		i++;
	}
}
int main()
{
	scanf("%d %d",&numv,&nume);
	int i=0,v1,v2,v3;
	while(i<nume)
	{
		scanf("%d%d",&v1,&v2);
		G[v1].link=insertG(v1,G[v1].link,v2);
		G[v2].link=insertG(v2,G[v2].link,v1);
		i++;
	}
	scanf("%d",&v3); //要删除的结点 
	travelDFS(v3); printf("\n");
	travelBFS(v3); printf("\n");
	flag=1;
	travelDFS(v3); printf("\n");
	travelBFS(v3); printf("\n");
	return 0;
}

