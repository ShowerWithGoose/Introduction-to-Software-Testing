#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct NODE{
	int apex;
	struct NODE *next;
}node;
typedef struct QUEUE{
	node *ver;
	struct QUEUE *next;
}queue;

int num,edge;
node *vertex[102];
queue *front=NULL,*rear=NULL;
int first=0,last=-1;
int sign[102];
int visited[102];
int visited1[102];
int del;

void initialize();
void plusnode(int ver1,int ver2);
void search(int flag);
void search1(int flag);
void DFS(node *pver);
void BFS(node *pver);
void add(node *pver);
void reset();
void Delete();
void allfree();
void put(int flag)
{
	int i;
	node *p;
	for(i=0;i<num;i++)
	{
		if(flag==1&&i==del)
		continue;
		p=vertex[i];
		while(p!=NULL)
		{
			printf("%d ",p->apex); 
			p=p->next;
		}
		printf("\n");
	}
}
int main()
{
	initialize();	
//	put(0);
	search(1);
	search(2);
	
	reset();
	Delete();
//	put(1);
	search1(1);
	search1(2);
	allfree();
	return 0;
 } 
void initialize()
{
	scanf("%d %d",&num,&edge);	
	
	int i,ver1,ver2;
	for(i=0;i<edge;i++)
	{
		scanf("%d %d",&ver1,&ver2);
		plusnode(ver1,ver2);
		plusnode(ver2,ver1);
	}
	scanf("%d",&del);
}
void plusnode(int ver1,int ver2)
{
		node *p,*t,*q;
		if(sign[ver1]==0)
		{
			p=(node *)malloc(sizeof(node));
			p->apex=ver1;
			p->next=NULL;
			vertex[ver1]=p;
			sign[ver1]=1;
		}
		p=(node *)malloc(sizeof(node));
		p->apex=ver2;
		p->next=NULL;
		t=vertex[ver1]->next;
		q=vertex[ver1];
		while(t!=NULL)
		{
			if(ver2<t->apex)
			{
				p->next=t;
				q->next=p; 
				break;
			}
			t=t->next;
			q=q->next;
		}
		if(t==NULL)
		{
			q->next=p;
		}
}
void search(int flag)
{
	int i;
	for(i=0;i<num;i++)
	{
		if(visited[i]==0&&flag==1)
		{
			DFS(vertex[i]);
		}
		else if(visited1[i]==0&&flag==2)
		{	
			BFS(vertex[i]);
		}
	}
	printf("\n");
}
void search1(int flag)
{
	int i;
	for(i=0;i<num;i++)
	{
		if(i==del)
			continue;
		if(visited[i]==0&&flag==1)
		{
			DFS(vertex[i]);
		}
		else if(visited1[i]==0&&flag==2)
		{	
			BFS(vertex[i]);
		}
	}
	printf("\n");
}
void DFS(node *pver)
{
	if(visited[pver->apex]==0)
	{
		visited[pver->apex]=1;
		printf("%d ",pver->apex);
	}
	node *p;
	p=pver->next;
	while(p!=NULL)
	{
		if(visited[p->apex]==0)
			DFS(vertex[p->apex]);
		p=p->next;
	}
}
void BFS(node *pver)
{
	if(visited1[pver->apex]==0)
	{
		visited1[pver->apex]=1;
		printf("%d ",pver->apex);
	}
	add(pver);
	node *p;
	queue *t;
	while(front!=NULL)
	{
		p=front->ver->next;
		t=front;
		front=front->next;
		free(t);
		while(p!=NULL)
		{
			if(visited1[p->apex]==0)
			{
				printf("%d ",p->apex);
				add(vertex[p->apex]);
				visited1[p->apex]=1;
			}
			p=p->next;
		}
	}
	
}
void add(node *pver)
{
	queue *p;
	p=(queue *)malloc(sizeof(queue));
	p->ver=pver;
	p->next=NULL;
	
	if(front==NULL)
	{
		front=p;
		rear=p;
	}
	else
	{
		rear->next=p;
		rear=p;
	}
}
void reset()
{
	int i;
	for(i=0;i<num;i++)
	{
		visited[i]=0;
		visited1[i]=0;
	}
}
void Delete()
{
	int i;
	node *p,*q;
	for(i=0;i<num;i++)
	{	
		q=vertex[i];
		p=q->next;
		if(i==del)
		{
			while(p!=NULL)
			{
				free(q);
				q=p;
				p=p->next;
			}
			free(q);
			vertex[i]=NULL;
		}
		else
		{
			while(p!=NULL)
			{
				if(p->apex==del)
				{
					q->next=p->next;
					free(p);
					break;
				}
				q=p;
				p=p->next;
			}
		}
		
	}
}
void allfree()
{
	int i;
	node *p,*q;
	for(i=0;i<num;i++)
	{
		if(vertex[i]==NULL)
			continue;
		q=vertex[i];
		p=q->next;
		while(p!=NULL)
		{
			free(q);
			q=p;
			p=p->next;
		}
		free(q);
	}
}

