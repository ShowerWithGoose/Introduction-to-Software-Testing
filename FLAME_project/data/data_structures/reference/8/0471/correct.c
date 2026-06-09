#include <stdio.h>
#include <malloc.h>
typedef struct edge
{
	int adjvex;
	struct edge *next;
}ELink;
typedef struct ver
{
	int degree;
	int num;
	ELink *link;
}TOPOVLink;
TOPOVLink verdata[105],QUEUE[50];
int tail=-1,front=-1,flat=0;
void DFS(int visited[],int i)
{
	int w,min=100,j=0;
	ELink *p=NULL;
	if(verdata[i].num==0)
	{
		if(flat==0)
		{
			printf("%d ",verdata[i].num);
			flat++;
		}
	}
	else
	printf("%d ",verdata[i].num);
	visited[i]=1;
	p=verdata[i].link;
	if(p==NULL)
	w=-1;
	else
	{
		min=100;
		while(p!=NULL)
		{
			if(p->adjvex<min&&visited[p->adjvex]==0)
			{
				if(p->adjvex!=0)
				min=p->adjvex;
			}
			p=p->next;
		}
		w=min;
		j++;
	}
	while(j<=verdata[i].degree)
	{
		if(visited[w]==0)
		DFS(visited,w);
		p=verdata[i].link;
		min=100;
		while(p!=NULL)
		{
			if(p->adjvex<min&&visited[p->adjvex]==0)
			{
				if(p->adjvex!=0)
				min=p->adjvex;
			}
			p=p->next;
		}
		w=min;
		j++;
	}
	return ;
}
void TRAVEL_DFS(int visited[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	flat=0;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		DFS(visited,i);
	}
	return ;
}
void BFS(int visited[],int i)
{
	int w,min=100,j=0;
	TOPOVLink p;
	ELink *q;
	printf("%d ",verdata[i].num);
	visited[i]=1;
	QUEUE[++front]=verdata[i];
	if(front==49)
	front=-1;
	while(tail!=front)
	{
		p=QUEUE[++tail];
		j=0;
		if(tail==49)
		tail=-1;
		if(p.link==NULL)
		w=-1;
		else
		{
			min=100;
			q=p.link;
			while(q!=NULL)
			{
				if(q->adjvex<min&&visited[q->adjvex]==0)
				min=q->adjvex;
				q=q->next;
			}
			w=min;
			j++;
		}
		while(w!=-1)
		{
			if(visited[w]==0)
			{
				printf("%d ",verdata[w].num);
				QUEUE[++front]=verdata[w];
				if(front==49)
				front=-1;
				visited[w]=1;
			}
			if(j==p.degree)
			w=-1;
			else
			{
				min=100;
				q=p.link;
			    while(q!=NULL)
			    {
			    	if(q->adjvex<min&&visited[q->adjvex]==0)
			    	min=q->adjvex;
			    	q=q->next;
				}
				w=min;
				j++;
			}
		}
	}
	return ;
}
void TRAVEL_BFS(int visited[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		BFS(visited,i);
	}
}
int main()
{
	int n=0,te=0,i=0,num1=0,num2=0,delete_num=0;//n为顶点数，te为边的数目 
	int visited[100]={0};
	ELink *p=NULL,*q=NULL;
	scanf("%d %d",&n,&te); 
	for(i=0;i<n;i++)
	{
		verdata[i].degree=0;
		verdata[i].link=NULL;
	}
	for(i=0;i<te;i++)
	{
		scanf("%d %d",&num1,&num2);
		verdata[num1].degree++;
		verdata[num1].num=num1;
		verdata[num2].degree++;
		verdata[num2].num=num2;
		q=(ELink *)malloc(sizeof(ELink));
		q->adjvex=num2;
		q->next=NULL;
		if(verdata[num1].link==NULL)
		verdata[num1].link=q;
		else
		{
			p=verdata[num1].link;
			while(p->next)
			p=p->next;
			p->next=q;
		}
		q=(ELink *)malloc(sizeof(ELink));
		q->adjvex=num1;
		q->next=NULL;
		if(verdata[num2].link==NULL)
		verdata[num2].link=q;
		else
		{
			p=verdata[num2].link;
			while(p->next)
			p=p->next;
			p->next=q;
		}
	}
	scanf("%d",&delete_num);
	TRAVEL_DFS(visited,n);
	printf("\n");
	TRAVEL_BFS(visited,n);
	printf("\n");
	p=verdata[delete_num].link;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	for(i=delete_num;i<n-1;i++)
	{
		verdata[i].degree=verdata[i+1].degree;
		verdata[i].num=verdata[i+1].num;
		verdata[i].link=verdata[i+1].link;
	}
	n--;
	for(i=0;i<n;i++)
	{
		p=verdata[i].link;
		while(p!=NULL)
		{
			if(p->adjvex==delete_num)
			{
				if(p==verdata[i].link)
				verdata[i].link=p->next;
				else
				q->next=p->next;
				q=p;
				p=p->next;
				free(q);
				verdata[i].degree--;
			}
			else
			{
				if(p->adjvex>delete_num)
				p->adjvex--;
				q=p;
				p=p->next;
			}
		}
	}
	TRAVEL_DFS(visited,n);
	printf("\n");
	TRAVEL_BFS(visited,n);
	return 0;
}

