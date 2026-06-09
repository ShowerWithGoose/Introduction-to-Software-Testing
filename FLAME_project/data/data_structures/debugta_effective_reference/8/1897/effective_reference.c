#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct e{
	int w;
	int vv;
	struct e* next;
}E;

typedef struct v{
	E* link;
}V;

V matrix[105];
int visited[105];

int queue[105];
int head=0,tail=104,cnt=0;

E* insert(int v2, E* root)
{
	E *p,*edge;
	p=root;
	edge=(E*)malloc(sizeof(E));
	edge->vv=v2;
	edge->w=1;
	edge->next=NULL;
	if(p==NULL)
	{
		p=edge;
		return p;
	}
	else if(p->vv>v2)
	{
		edge->next=p;
		root=edge;
		return root;
	}
	for(;p->next!=NULL&&((p->next->vv)<v2);p=p->next);
	if(p->next==NULL)
	{
		p->next=edge;
		return root;
	}
	else {
		edge->next=p->next;
		p->next=edge;
		return root;
	}
}

void dfs(V matrix[],int vi)
{
	E *p;
	printf("%d ",vi);
	visited[vi]=1;
	for(p=matrix[vi].link;p!=NULL;p=p->next)
	{
		if(!visited[p->vv])
		{
			dfs(matrix,p->vv);
		}
	}
}

void bfs(V matrix[],int vi)
{
	E *p;
	printf("%d ",vi);
	visited[vi]=1;
	tail=(tail+1)%105;
	queue[tail]=vi;
	cnt++;
	
	while(cnt)
	{
		vi=queue[head];
		head=(head+1)%105;
		cnt--;
		p=matrix[vi].link;
		for(;p!=NULL;p=p->next)
		{
			if(!visited[p->vv])	
			{
				printf("%d ",p->vv);
				visited[p->vv]=1;
				tail=(tail+1)%105;
				queue[tail]=p->vv;
				cnt++;
			}
		} 
	}
}

int main()
{
	int Vnum,Enum;
	scanf("%d%d",&Vnum,&Enum);
	int v1,v2;
	int i=0;
	for(i=0;i<Enum;i++)
	{
		scanf("%d%d",&v1,&v2);
		matrix[v1].link=insert(v2,matrix[v1].link);
		matrix[v2].link=insert(v1,matrix[v2].link);
	}
	
	for(i=0;i<Vnum;i++)
	{
		if(!visited[i])
		{
			dfs(matrix,i);
		}
	}
	putchar(10);
	memset(visited,0,sizeof(visited));
	
	for(i=0;i<Vnum;i++)
	{
		if(!visited[i])
		{
			bfs(matrix,i);
		}
	}
	putchar(10);
	memset(visited,0,sizeof(visited));
	memset(queue,0,sizeof(queue));
	head=0,tail=104,cnt=0;
	
	int del;
	scanf("%d",&del);
	
	visited[del]=1;
	
	for(i=0;i<Vnum;i++)
	{
		if(!visited[i])
		{
			dfs(matrix,i);
		}
	}
	putchar(10);
	memset(visited,0,sizeof(visited));
	
	visited[del]=1;
	for(i=0;i<Vnum;i++)
	{
		if(!visited[i])
		{
			bfs(matrix,i);
		}
	}
	putchar(10);
	
	return 0;
 } 



