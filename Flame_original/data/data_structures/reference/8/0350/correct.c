#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct edge {
	int adjvex;
	struct edge *next;
} ELink;
typedef struct ver {
	int vertex;
	struct edge *link;
} VLink;
VLink G[100];
ELink  *insertEdge(ELink *head, int avex) {
	ELink *e,*p;
	e =(ELink *)malloc(sizeof(ELink));
	e->adjvex= avex;
	e->next = NULL;
	if(head == NULL)  {
		head=e;
		return head;
	}
	for(p=head; p->next != NULL; p=p->next)
		;
	p->next = e;
	return head;
}
void DFS(VLink  G[ ], int v) {
	ELink  *p;
	G[v].vertex=0; //标识某顶点被访问过
	printf("%d ",v); //访问某顶点
	for(p = G[v].link; p !=NULL;  p=p->next)
		if( G[p->adjvex].vertex!=0 )
			DFS(G, p->adjvex);
}
void  travelDFS(VLink  G[ ], int n) {
	int i;
	for(i=0; i<n; i++) G[i].vertex= 200 ;
//	for(i=0; i<n; i++)
//		if( !Visited[i] ) DFS(G, i);
}
struct dian {
	int d1;
	int d2;
} D[100];
int cmp_1(const void* e1, const void* e2) {
	struct dian *c=(struct dian *)e1;
	struct dian *d=(struct dian *)e2;
	if(c->d1==d->d1)
		return((c->d2)-(d->d2));
	else
		return((c->d1)-(d->d1));
}
int Visited[200],Q[100],head,tail;
void BFS(VLink  G[ ], int v) {
	ELink  *p;
	Visited[v] = 1; //标识某顶点已入队
	Q[tail++]=v;
	while(tail!=head) {
		v = Q[head++];  //取出队头元素
		printf("%d ",v); //访问当前顶点
		for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
			if( !Visited[p->adjvex] ) {
				Visited[p->adjvex] = 1; //标识某顶点入队
				Q[tail++]=p->adjvex;
			}
	}
}
void travelBFS(VLink G[],int n){
	int i;
	for(i=0;i<n;i++){
		Visited[i]=0;
	}
}
int main() {
	int i,j,k,x,y,z,n,m1,m2;
	int dian_cnt,bian_cnt;
	scanf("%d %d",&dian_cnt,&bian_cnt);
	for(i=0; i<bian_cnt; i++) {
		scanf("%d %d",&m1,&m2);
		if(m1<m2) {
			D[i].d1=m1;
			D[i].d2=m2;
		} else {
			D[i].d1=m2;
			D[i].d2=m1;
		}
	}
	qsort(D,i,sizeof(D[0]),cmp_1);

	for(j=0; j<i; j++) {
//		printf("%d%d\n",D[j].d1,D[j].d2);
		G[D[j].d1].vertex=200;
		G[D[j].d1].link=insertEdge(G[D[j].d1].link,D[j].d2);
		G[D[j].d2].vertex=200;
		G[D[j].d2].link=insertEdge(G[D[j].d2].link,D[j].d1);
	}
	int del;
	scanf("%d",&del);
	DFS(G,0);
	printf("\n");
	travelDFS(G,dian_cnt);
	BFS(G,0);
	printf("\n");
	travelBFS(G,dian_cnt);

	G[del].vertex=0;
	Visited[del]=1; 
	DFS(G,0);
	printf("\n");
	travelDFS(G,dian_cnt);
	BFS(G,0);
	printf("\n");
	travelBFS(G,dian_cnt);







	return 0;
}


