//7-1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct item{
	int name;
	struct item* next;
}*p=NULL,*q=NULL;
struct vertex{
	int name;
	struct item* link;
}head[105];
struct que{
	int name;
	struct que* next;
}*front=NULL,*rear=NULL,*k=NULL;
int visited[105];
int emptyqueue()
{
	return front==NULL;
}
void enqueue(int x)
{
	if(front==NULL)
	{
		front=(struct que*)malloc(sizeof(struct que));
		front->name=x;
		front->next=NULL;
		rear=front;
	}
	else
	{
		k=(struct que*)malloc(sizeof(struct que));
		k->name=x;
		k->next=NULL;
		rear->next=k;
		rear=k;
	}
}
int dequeue()
{
	int t;
	t=front->name;
	front=front->next;
	return t;
}
void DFS(int x)
{
	struct item* r=NULL;
	visited[x]=1;
	printf("%d ",x);
	for(r=head[x].link;r!=NULL;r=r->next)
	{
		if(visited[r->name]==0)
			DFS(r->name);
	}
} 
void BFS(int x)
{
	struct item* r=NULL;
	visited[x]=1;
	enqueue(x);
	while(!emptyqueue())
	{
		x=dequeue();
		printf("%d ",x);
		for(r=head[x].link;r!=NULL;r=r->next)
		{
			if(visited[r->name]==0)
			{
				visited[r->name]=1;
				enqueue(r->name);
			}
		}
	}
}
int main()
{
	int vert,edge,i,t1,t2,dele,flag;
	scanf("%d%d",&vert,&edge);
	for(i=0;i<edge;i++)
	{
		scanf("%d%d",&t1,&t2);
		p=(struct item*)malloc(sizeof(struct item));
		p->name=t2;
		p->next=NULL;
		if(head[t1].link==NULL)
		{
			head[t1].link=p;
			head[t1].name=t1;
		}
		else
		{
			q=head[t1].link;
			if(q->name>p->name)
			{
				p->next=q;
				head[t1].link=p;
			}
			else
			{
				flag=0;
				while(q->next!=NULL)
				{
					if(q->name<p->name && q->next->name>p->name)
					{
						p->next=q->next;
						q->next=p; 
						flag=1;
						break;
					}
					q=q->next;
				}
				if(flag==0)
					q->next=p;
			}
		}
		p=(struct item*)malloc(sizeof(struct item));
		p->name=t1;
		p->next=NULL;
		if(head[t2].link==NULL)
		{
			head[t1].name=t1;
			head[t2].link=p;
		}	
		else
		{
			q=head[t2].link;
			if(q->name>p->name)
			{
				p->next=q;
				head[t2].link=p;
			}
			else
			{
				flag=0;
				while(q->next!=NULL)
				{
					if(q->name<p->name && q->next->name>p->name)
					{
						p->next=q->next;
						q->next=p; 
						flag=1;
						break;
					}
					q=q->next;
				}
				if(flag==0)
					q->next=p;
			}
		}
	}
	scanf("%d",&dele);
	memset(visited,0,sizeof(visited));
	DFS(0);
	putchar('\n');
	memset(visited,0,sizeof(visited));
	BFS(0);
	putchar('\n');
	p=head[dele].link;
	while(p!=NULL)
	{
		t1=p->name;
		q=head[t1].link;
		if(q->name==dele)
			head[t1].link=q->next;
		else
		{
			while(q->next->name!=dele)
				q=q->next;
			q->next=q->next->next;
		}
		p=p->next;
	}
	memset(visited,0,sizeof(visited));
	DFS(0);
	putchar('\n');
	memset(visited,0,sizeof(visited));
	BFS(0);
	putchar('\n');
	return 0;
}


