#include<stdio.h>
struct x
{
	int num;
	struct x *next;
}*table1[105],*table2[105],*r,*p;

int s[105][105];
int visited[105];
int q[105];

void DFS(struct x *table[],int v)
{
	struct x *t;
	printf("%d ",table[v]->num);
	visited[v]=1;
	for(t=table[v]->next;t!=NULL;t=t->next)
	{
		if(visited[t->num]==0)
		DFS(table,t->num);
	}
}

void travelDFS(struct x *table[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		DFS(table,i);
	}
}

void BFS(struct x *table[],int v)
{
	struct x *t;
	int front=-1,rear=0;
	visited[v]=1;
	q[rear]=v;
	while(front<rear)
	{
		front++;
		v=q[front];
		printf("%d ",table[v]->num);
		for(t=table[v]->next;t!=NULL;t=t->next)
	    {
		    if(visited[t->num]==0)
		    {
		    	visited[t->num]=1;
		    	rear++;
		    	q[rear]=t->num;
			}
	    }
	}
}

void travelBFS(struct x *table[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		BFS(table,i);
	}
}

int main()
{
	int nv,na,i,j,k,dv;
	scanf("%d%d",&nv,&na);
	for(i=0;i<na;i++)
	{
		scanf("%d%d",&j,&k);
		s[j][k]=1;
		s[k][j]=1;
	}
	scanf("%d",&dv);
	for(i=0;i<nv;i++)
	{
		table1[i]=(struct x*)malloc(sizeof(struct x));
		table1[i]->num=i;
		table1[i]->next=NULL;
	}
	for(i=0;i<nv;i++)
	{
		for(j=0;j<nv;j++)
		{
			if(s[i][j]==1)
			{
				p=(struct x*)malloc(sizeof(struct x));
				p->num=j;
				p->next=NULL;
				r=table1[i];
				while(r->next!=NULL)
				r=r->next;
				r->next=p;
			}
		}
	}
	
	for(i=0;i<nv;i++)
	visited[i]=0;
	travelDFS(table1,nv);
	printf("\n");
	
	for(i=0;i<nv;i++)
	visited[i]=0;
	travelBFS(table1,nv);
	printf("\n");
	
	for(i=0;i<nv;i++)
	visited[i]=0;
	visited[dv]=1;
	travelDFS(table1,nv);
	printf("\n");
	
	for(i=0;i<nv;i++)
	visited[i]=0;
	visited[dv]=1;
	travelBFS(table1,nv);
	printf("\n");
	return 0;
}

