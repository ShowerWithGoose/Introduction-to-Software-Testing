#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxV 101
struct edge{
	int adjvex;
	int weight;
	struct edge *next;
};
typedef struct edge ELink;
struct ver{
	int vertex;
	int flag;
	ELink *link;
};
typedef struct ver VLink;
VLink G[MaxV];
int n, m, Visited[MaxV], Ver[MaxV], Queue[MaxV], Front, Rear=MaxV-1, j;
void createGraph();
ELink* insertEdge(ELink *head,int avex);
void deleteVer(int avex);
void travelDFS();
void DFS(int i);
void travelBFS();
void BFS(int i);
void enQueue(int v);
int deQueue();
int main(){
	int x, i;
	createGraph();
	travelDFS();
	for(i=0;i<m;i++){
		printf("%d ",Ver[i]);
		Ver[i]=0;
		Visited[i]=0;
	}
	printf("\n");
	j=0;
	travelBFS();
	for(i=0;i<m;i++){
		printf("%d ",Ver[i]);
		Ver[i]=0;
		Visited[i]=0;
	}
	printf("\n");
	j=0;
	scanf("%d",&x);
	deleteVer(x);
	Visited[x]=1;
	travelDFS();
	for(i=0;i<m-1;i++){
		printf("%d ",Ver[i]);
		Ver[i]=0;
		Visited[i]=0;
	}
	Ver[i]=0;
	Visited[i]=0;
	printf("\n");
	j=0;
	Visited[x]=1;
	travelBFS();
	for(i=0;i<m-1;i++){
		printf("%d ",Ver[i]);
		Ver[i]=0;
		Visited[i]=0;
	}
	printf("\n");
	return 0;
}
void createGraph(){
	int i, v1, v2;
	scanf("%d %d",&m, &n);
	for(i=0;i<n;i++){
		scanf("%d %d",&v1, &v2);
		G[v1].link=insertEdge(G[v1].link,v2);
		G[v2].link=insertEdge(G[v2].link,v1);
		G[v1].flag=1;G[v2].flag=1;
	} 
}
ELink* insertEdge(ELink *head,int avex){
	ELink *e, *p, *q;
	e=(ELink*)malloc(sizeof(ELink));
	e->adjvex=avex;e->next=NULL;
	if(head==NULL){
		head=e;
		return head;
	}
	for(p=head;p!=NULL && p->adjvex<=avex;q=p,p=p->next){
		;
	}
	if(p!=head){
		q->next=e;
		e->next=p;
	}
	else{
		e->next=p;
		head=e;
	}
	return head;
}
void deleteVer(int avex){
	int i;
	ELink *p, *q;
	for(i=0;i<m;i++){
		for(p=G[i].link;p->next!=NULL;q=p,p=p->next){
			if(p->adjvex==avex){
				if(p==G[i].link){
					G[i].link=p->next;
				}
				else{
					q->next=p->next;
				}
			}
		}
	}
}
void travelDFS(){
	int i;
	for(i=0;i<m;i++){
		if(Visited[i]!=1) DFS(i);
	}
}
void DFS(int i){
	ELink *p;
	Visited[i]=1;
	Ver[j]=i;
	j++;
	for(p=G[i].link;p!=NULL;p=p->next){
		if(Visited[p->adjvex]!=1){
			DFS(p->adjvex);
		}
	}
}
void travelBFS(){
	int i;
	for(i=0;i<m;i++){
		if(Visited[i]!=1) BFS(i);
	}
}
void BFS(int i){
	ELink *p;
	Visited[i]=1;
	enQueue(i);
	while(Front<=Rear){
		i=deQueue();
		Ver[j]=i;
		j++;
		for(p=G[i].link;p!=NULL;p=p->next){
			if(Visited[p->adjvex]!=1){
				Visited[p->adjvex]=1;
				enQueue(p->adjvex);
			}
		}
	}
}
void enQueue(int v){
	Rear=(Rear+1)%MaxV;
	Queue[Rear]=v;
}
int deQueue(){
	int i;
	i=Front;
	Front=(Front+1)%MaxV;
	return Queue[i]; 
}

