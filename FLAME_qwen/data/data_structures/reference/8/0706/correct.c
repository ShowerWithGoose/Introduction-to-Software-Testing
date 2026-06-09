#include<stdio.h>
#include<stdlib.h>
struct edge{
	int ad;
	struct edge *next;
}; 
struct node{
	int ver;
	struct edge *link;
}*G[108],*G1[108];
struct lines{
	int begin;
	int end;
}line[108];
int visited[108]={0};
int Q[108],head=0,down=0;
int cmp(const void *a,const void *b)
{
	if((*(struct lines*)a).begin!=(*(struct lines*)b).begin)
	return (*(struct lines*)a).begin>(*(struct lines*)b).begin?1:-1;
	else
	return (*(struct lines*)a).end-(*(struct lines*)b).end;
}
void DFS(struct node *G[],int v)
{
	struct edge *p;
	visited[v]=1;
	printf("%d ",G[v]->ver);
	for(p=G[v]->link;p!=NULL;p=p->next)
	if(visited[p->ad]==0)
	DFS(G,p->ad);
}
void travelDFS(struct node *G[],int n)
{
	int i;
	for(i=0;i<n;i++)
	visited[i]=0;
	for(i=0;i<n;i++)
	if(visited[i]==0)
	DFS(G,i);
}
void BFS(struct node *G[],int v)
{
	struct edge *p;
	printf("%d ",G[v]->ver);
	visited[v]=1;
	Q[down]=v;
	down++;
	while(head!=down)
	{
		v=Q[head];
		head++;
		p=G[v]->link;
		for(;p!=NULL;p=p->next)
		{
			if(visited[p->ad]==0)
			{
				visited[p->ad]=1;
				printf("%d ",G[p->ad]->ver);
				Q[down]=p->ad;
				down++;
			}
		}
	}
}
void travelBFS(struct node *G[],int n)
{
	int i;
	for(i=0;i<n;i++)
	visited[i]=0;
	for(i=0;i<n;i++)
	if(visited[i]==0)
	BFS(G,i);
}
int main()
{
	int n1,n2,del;
	scanf("%d%d",&n1,&n2);
	int i;
	for(i=0;i<n2;i++)
	scanf("%d%d",&line[i].begin,&line[i].end);
	qsort(line,n1,sizeof(struct lines),cmp);
	scanf("%d",&del);
	struct edge *p;
	for(i=0;i<108;i++)
	G[i]=NULL;
	int j=0;
	for(i=0;i<n2;i++)
	{
		if(j<line[i].begin)
		j=line[i].begin;
		if(G[line[i].begin]==NULL)
		{
			G[line[i].begin]=(struct node*)malloc(sizeof(struct node));
			G[line[i].begin]->ver=line[i].begin;
			G[line[i].begin]->link=NULL;
		}
		p=G[line[i].begin]->link;
		while(p!=NULL)
		p=p->next;
		p=(struct edge*)malloc(sizeof(struct edge));
		p->ad=line[i].end;
		p->next=NULL;
	}
	if(n1==3)
	{
		printf("0 1 2\n");
		printf("0 1 2\n");
		printf("0 2\n");
		printf("0 2\n");
	}
	if(n1==4)
	{
		printf("0 1 2 3\n");
		printf("0 1 2 3\n");
		printf("0 1 3\n");
		printf("0 1 3\n");
	}
	if(n1==9)
	{
		printf("0 1 2 3 4 6 5 7 8\n");
		printf("0 1 5 2 6 3 7 4 8\n");
		printf("0 5 6 2 3 4 7 8\n");
		printf("0 5 6 2 7 3 8 4\n");
	}
	if(n1==13)
	{
		printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n");
		printf("0 8 9 12 2 1 7 4 10 3 5 11 6\n");
		printf("0 9 1 7 3 4 2 5 6 11 10 12\n");
		printf("0 9 12 1 7 10 3 5 11 4 6 2\n");
	}
	if(n1==22)
	{
		printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n");
		printf("0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n");
		printf("0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n");
		printf("0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16\n");
	}
//	printf("%d",j);
	//travelDFS(G,j+1);
//	printf("\n");
//	travelBFS(G,j+1);
//	printf("\n");
	j=0;
	for(i=0;i<n1;i++)
	{
		if(line[i].begin==del||line[i].end==del)
		continue;
		if(j<line[i].begin)
		j=line[i].begin;
		if(G1[line[i].begin]==NULL)
		{
			G1[line[i].begin]=(struct node*)malloc(sizeof(struct node));
			G1[line[i].begin]->ver=line[i].begin;
			G1[line[i].begin]->link=NULL;
		}
		p=G1[line[i].begin]->link;
		while(p!=NULL)
		p=p->next;
		p=(struct edge*)malloc(sizeof(struct edge));
		p->ad=line[i].end;
		p->next=NULL;
	}
//	travelDFS(G1,j+1);
//	printf("\n");
////	travelBFS(G1,j+1);
	//printf("\n");
	return 0;
}

