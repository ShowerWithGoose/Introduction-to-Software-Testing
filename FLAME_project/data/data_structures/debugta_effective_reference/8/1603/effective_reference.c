#include<stdio.h>
#include<stdlib.h>

typedef struct ver
{
	int flag;
	int vertex;
	struct edge *next;
}VLink;

typedef struct edge
{
	int eno;
	int adjver;
	struct edge *next;
}ELink;

void insertEdge(int vetn, int vertex);
void dltver(int n1);
void travelDFS(struct ver G[]);
void DFS(struct ver G[],int v);
void travelBFS(struct ver G[]);
void BFS(struct ver G[],int v);
struct ver G[1000];

int i,vetn,edgen,ver,v1,v2,i,visited[1000],Q[10000],rear=-1,top=0;

int main()
{
	scanf("%d %d",&vetn,&edgen);
	
	for(i=0;i<vetn;i++)
	{
		G[i].vertex=i;
		G[i].flag=1;
	}
	
	for(i=1;i<=edgen;i++)
	{
		scanf("%d %d",&v1,&v2);
		insertEdge(v1,v2);
		insertEdge(v2,v1);
	}
	
	scanf("%d",&v1);
	/*
	for(i=0;i<n;i++)
	{
		printf("%d: ",i);
		struct edge *p=G[i].next;
		while(p!=NULL)
		{
			printf("%d ",p->adjver);
			p=p->next;
		}
		puts("");
	}
	*/
	
	travelDFS(G);
	travelBFS(G);
	
	
	dltver(v1);
	
	travelDFS(G);
	travelBFS(G);
	
	/*
	puts(""); 
	for(i=0;i<n;i++)
	{
		if(i==v1)
			continue;
		printf("%d: ",i);
		struct edge *p=G[i].next;
		while(p!=NULL)
		{
			printf("%d ",p->adjver);
			p=p->next;
		}
		puts("");
	}
	*/
	return 0;
}

void insertEdge(int vetn, int vertex)
{
	struct edge *p,*edgen;
	edgen=(struct edge*)malloc(sizeof(struct edge));
	edgen->adjver=vertex;
	edgen->next=NULL;
	if(G[vetn].next==NULL)
	{
		G[vetn].next=edgen;
	}
	else
	{
		if(edgen->adjver<G[vetn].next->adjver)
		{
			p=(struct edge*)malloc(sizeof(struct edge));
			p=G[vetn].next;
			G[vetn].next=edgen;
			edgen->next=p;
		}
		
		else
		{
			p=G[vetn].next;
			while(p->next!=NULL)
			{
				
				if(edgen->adjver<p->next->adjver)
				{
					edgen->next=p->next;
					p->next=edgen;
					return ;
				}
				
				p=p->next;
			}
			p->next=edgen;
		}
	}
	return ;
}

void dltver(int n1)
{
	
	G[n1].flag=0;
	int i;
	struct edge *p;
	for(i=0;i<vetn;i++)
	{
		if(G[i].flag)
		{
			p=G[i].next;
			if(p!=NULL)
			{
				if(p->adjver==n1)
				{
					G[i].next=p->next;
				}
				else
				{
					while(p->next!=NULL)
					{
						if(p->next->adjver==n1)
						{
							p->next=p->next->next;
							break; 
						}
						p=p->next;
					}
				}
			}
		}
	}
	return ;
}

void travelDFS(struct ver G[])
{
	int i;
	for(i=0;i<vetn;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<vetn;i++)
	{
		if(G[i].flag==1&&!visited[i])
		{
			DFS(G,i);
		}
	}
	puts("");
	return ;
}
void DFS(struct ver G[],int v)
{
	struct edge *p;
	visited[v]=1;
	printf("%d ",G[v].vertex);
	for(p=G[v].next;p!=NULL;p=p->next)
	{
		if(!visited[p->adjver])
		{
			DFS(G,p->adjver);
		}
	}
}

void travelBFS(struct ver G[])
{
    int i;
    for(i=0; i<vetn; i++) visited[i] = 0 ;
    for(i=0; i<vetn; i++)
        if(!visited[i]&&G[i].flag==1) 
			BFS(G, i);
	puts("");
	return ;
}

void BFS(struct ver G[],int v)
{
	struct edge *p;
    printf("%d ",G[v].vertex);
    visited[v] = 1;
    Q[++rear]=v;
    while(rear>=top)
	{
        v = Q[top++];
        p = G[v].next;        
        for(; p != NULL ; p = p->next ) 
            if(!visited[p->adjver]&&G[p->adjver].flag==1) 
			{
                printf("%d ",p->adjver); 
                visited[p->adjver] = 1;
                Q[++rear]=p->adjver;
           }
    }	
}


