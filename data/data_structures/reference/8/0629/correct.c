#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct  edge {
	int  adjvex;
	struct edge *next;
} Elink;
typedef struct ver {
	int  vertex;
	Elink  *link;
} Vlink;
Vlink  G[105];
int  Visited[105]= {0}; //标识顶点是否被访问过，N为顶点数
int Q[105]= {0};
int head=0,end=0;
Elink *create(int n) {
	Elink *p=NULL;
	p=(Elink*)malloc(sizeof(Elink));
	p->adjvex=n;
	p->next=NULL;
	return p;
}
void insert(int a,int n) {
	Elink *p=G[n].link;
	Elink *t=NULL;
	Elink *q=NULL;
	t=p;
	while(p!=NULL&&p->adjvex<a) {
		t=p;
		p=p->next;
	}
	if(p==NULL) {
		q=(Elink*)malloc(sizeof(Elink));
		q->adjvex=a;
		q->next=NULL;
		t->next=q;
	} else if(t==p) {
			q=(Elink*)malloc(sizeof(Elink));
		q->adjvex=a;
		q->next=t;
		G[n].link=q;
	} else {
		q=(Elink*)malloc(sizeof(Elink));
		q->adjvex=a;
		q->next=t->next;
		t->next=q;
	}
}
void DFS(Vlink  G[ ], int v) {
	Elink  *p;
	Visited[v] = 1; //标识某顶点被访问过
	if(G[v].vertex!=-1)
		printf("%d ",G[v].vertex); //访问某顶点
	for(p = G[v].link; p !=NULL;  p=p->next)
		if( !Visited[p->adjvex] )
			DFS(G, p->adjvex);
}
void  travelDFS(Vlink  G[ ], int n) {
	int i;
	for(i=0; i<n; i++) Visited[i] = 0 ;
	for(i=0; i<n; i++)
		if( !Visited[i] ) DFS(G, i);
}
void enQueue(int v) {
	Q[end++]=v;
}
int deQueue() {
	return 	Q[head++];
}
int emptyQ() {
	return head>=end?1:0;
}
void BFS(Vlink  G[ ], int v) {
	Elink  *p;
	Visited[v] = 1; //标识某顶点已入队
	enQueue(v);
	while( !emptyQ()) {
		v = deQueue();
		if(G[v].vertex!=-1)//取出队头元素
			printf("%d ",G[v].vertex); //访问当前顶点
		for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
			if( !Visited[p->adjvex] ) {
				Visited[p->adjvex] = 1; //标识某顶点入队
				enQueue(p->adjvex);
			}
	}
}
void  travelBFS(Vlink  G[ ], int n) {
	int i;
	for(i=0; i<n; i++) Visited[i] = 0 ;
	for(i=0; i<n; i++)
		if( !Visited[i] ) BFS(G, i);
}
int main() {
	int v,e;
	scanf("%d%d",&v,&e);
	for(int i=0; i<v; i++)
		G[i].link=NULL;
	for(int i=0; i<e; i++) {
		int pre,lat;
		scanf("%d%d",&pre,&lat);
		if(G[pre].link==NULL) {
			G[pre].vertex=pre;
			G[pre].link=create(lat);
		} else {
			insert(lat,pre);
		}
		if(G[lat].link==NULL) {
			G[lat].vertex=lat;
			G[lat].link=create(pre);
		} else {
			insert(pre,lat);
		}
	}
	int a;
	scanf("%d",&a);
	travelDFS(G,v);
	printf("\n");
	travelBFS(G,v);
	printf("\n");
	G[a].link=NULL;
	G[a].vertex=-1;
	travelDFS(G,v);
	printf("\n");
	travelBFS(G,v);
	return 0;
}

