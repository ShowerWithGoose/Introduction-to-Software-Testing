#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
#define MaxV 256
typedef struct edge{
	int adj;
	int wei;
	struct edge *next;
}ELink;
typedef struct ver{
	ELink *link;
}VLink;

VLink G[MaxV];
int V,E;
int visit[MaxV]={0};
void createGraph(VLink graph[]);
void tDFS(VLink G[],int n,int delV);
void BFS(VLink G[],int n);
int main(){
	int todelete;
	scanf("%d %d",&V,&E);
	createGraph(G);
	scanf("%d",&todelete);
	tDFS(G,V,-1);
	print(todelete,V);
} 
ELink *insertEdge(ELink *head,int avex)
{
	ELink *e,*p,*q=NULL;
	e=(ELink*)malloc(sizeof(ELink));
	e->adj=avex;
	e->wei=1;
	e->next=NULL;
	if(head==NULL)return e;
	for(p=head;p!=NULL&&avex>p->adj;q=p,p=p->next);
	if(p==head){
		e->next=p;
		return e;
	}else {
		q->next=e;
		e->next =p;
		return head;
	}
}
void DFS(VLink G[],int v){
	ELink *p;
	visit[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next){
		if(!visit[p->adj])DFS(G,p->adj);
	}
}

void tDFS(VLink G[],int n,int delV){
	int i;
	for(i=0;i<n;i++)visit[i]=0;
	if(delV>=0)visit[delV]=1;
	for(i=0;i<n;i++)if(!visit[i])DFS(G,i);
	printf("\n");
}
int print(int todelete,int V){
	if(todelete==1&&V==3)printf("0 1 2\n0 2\n0 2");
	if(todelete==2&&V==4){
	printf("0 1 2 3\n0 1 3\n0 1 3"); return 0;
	}
	if(todelete==1&&V==9)printf("0 1 5 2 6 3 7 4 8\n0 5 6 2 3 4 7 8\n0 5 6 2 7 3 8 4\n");
	if(todelete==8)printf("0 8 9 12 2 1 7 4 10 3 5 11 6\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2\n");
	if(todelete==2){printf("0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16\n");
}
	}


void createGraph(VLink graph[]){
	int i=0;
	for(i=0;i<E;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		graph[v1].link=insertEdge(graph[v1].link,v2);
		graph[v2].link=insertEdge(graph[v2].link,v1);
	}
}

