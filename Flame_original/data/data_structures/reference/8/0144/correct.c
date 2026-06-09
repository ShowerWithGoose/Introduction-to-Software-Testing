#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//边结点
struct edge{
	int adj;
	struct egde *next;
}; 

//顶点结点
struct ver{
	struct edge *link;
};  
struct ver graph[105];

int visited[105]={0};
void travelDFS(struct ver graph[],int vnum,int op)
{
	int i=0;
	for(i=0;i<vnum;i++)
	{
		if(i==op)
		visited[i]=1;
		else
		visited[i]=0;
	}
	for(i=0;i<vnum;i++)
	{
	    if(visited[i]==0)
	    {
	    	DFS(graph,i);
		}
	}
}
void DFS(struct ver graph[],int v)
{
	struct edge *p=NULL;
	
	printf("%d ",v);
	visited[v]=1;
	
	for(p=graph[v].link;p!=NULL;p=p->next)
	{
		if(visited[p->adj]==0)
		{
			DFS(graph,p->adj);
		}
	}
}

void travelBFS(struct ver graph[],int vnum,int op)
{
	int i=0;
	for(i=0;i<vnum;i++)
	{
        if(i==op)
		visited[i]=1;
		else
		visited[i]=0;
	 }
	for(i=0;i<vnum;i++)
	{
	    if(visited[i]==0)
	    {
	    	BFS(graph,i);
		}
	}
}

void BFS(struct ver graph[],int v)
{
	struct edge *queue[105],*p=NULL;
	int rear=-1,top=-1;
	int num=0;
	
	//访问头结点 
    printf("%d ",v);
	visited[v]=1;
	
	for(p=graph[v].link;p!=NULL;p=p->next)
	{
		if(visited[p->adj]==0)
	    {
		top++;
		num++;
		queue[top]=p;
		visited[p->adj]=1;
	    }
	}
	while(num>0)
	{
		rear++;
		printf("%d ",queue[rear]->adj);
		//visited[queue[rear]->adj]=1;
		num--;
		
		for(p=graph[queue[rear]->adj].link;p!=NULL;p=p->next)
	    {
	    	if(visited[p->adj]==0)
	    	{
		        top++;
		        num++;
		        queue[top]=p;
		        visited[p->adj]=1;
		    }
	    }
	}
}

int main()
{
	int vnum=0,Enum=0;
	int i=0;
	int v1=0,v2=0;
	struct edge *p=NULL,*q=NULL,*r=NULL,*t=NULL;	
	
	scanf("%d%d",&vnum,&Enum);
	
	for(i=0;i<Enum;i++)
	{
		scanf("%d%d",&v1,&v2);
		
		//构造图
		p=(struct edge*)malloc(sizeof(struct edge));
		p->adj=v2;
		p->next=NULL; 
		if(graph[v1].link==NULL)
		{
			graph[v1].link=p;
		}

		else 
		{
			//与最后一个比较
			for(q=graph[v1].link;q->next!=NULL;q=q->next);
			
			if(q->adj<v2)
			q->next=p;
			
			else if(graph[v1].link->adj>v2)
			{
			  p->next=graph[v1].link;
			  graph[v1].link=p;
		    }
			else
			{
			//寻找插入位置 
			for(q=graph[v1].link,t=graph[v1].link;q->adj<v2;q=q->next)
			{
				t=q;
			}
			p->next=t->next;
			t->next=p;
		    }
		}
		
		r=(struct edge*)malloc(sizeof(struct edge));
		r->adj=v1;
		r->next=NULL; 
		if(graph[v2].link==NULL)
		{
			graph[v2].link=r;
		}
		
		else if(graph[v2].link->adj>v1)
		{
			r->next=graph[v2].link;
			graph[v2].link=r;
		}
		
		else 
		{
			for(q=graph[v2].link;q->next!=NULL;q=q->next);
			
			if(q->adj<v1)
			q->next=r;

			else
			{
			//寻找插入位置 
			for(q=graph[v2].link,t=graph[v2].link;q->adj<v1;q=q->next)
			{
				t=q;
			}
			r->next=t->next;
			t->next=r;
		    }
		}
	}
    
    /*
    for(i=0;i<vnum;i++)
    {
    	for(p=graph[i].link;p!=NULL;p=p->next)
    	{
    		printf("%d ",p->adj);
		}
		printf("\n");
	}
	*/
	
	int op1=-1,op=0;
		
    scanf("%d",&op);
    
	travelDFS(graph,vnum,op1);
	printf("\n");
	travelBFS(graph,vnum,op1);
	
	printf("\n");
	
	travelDFS(graph,vnum,op);
	printf("\n");
	travelBFS(graph,vnum,op);
	
	//深度优先遍历

	
	
	/*
	printf("\n");
	travelDFS(graph1,vnum1);
	printf("\n");
	travelBFS(graph1,vnum1);
	*/
	
}




/*
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
*/ 









