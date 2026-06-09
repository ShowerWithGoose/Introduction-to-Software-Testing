#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MV 256
typedef struct eg {
	int  aaj;
	int  wee;
	struct eg  *next;
} Ek;

typedef struct vee {
	Ek  *link;
} Vk;
Vk  G[MV];

int V, E; //顶点数v，边数e

void chGraph(Vk grh[]);

void  trDFS(Vk  G[ ], int n, int dV);
void  trBFS(Vk  G[ ], int n, int dV);

int main() {

	scanf("%d %d",&V,&E); //输入图的顶点数和边数

	chGraph(G);//建立无向图

	trDFS(G,V,-1);//不删除顶点
	trBFS(G,V,-1);

	int k;
	scanf("%d",&k);

	trDFS(G,V,k);
	trBFS(G,V,k);

	return 0;
}

Ek  *insertE(Ek *head, int ax) {
	Ek *e,*p,*q = NULL;
	e =(Ek *)malloc(sizeof(Ek));
	e->aaj= ax;
	e->wee=1;
	e->next = NULL;
	if(head == NULL)
		return e;
	for(p=head; p != NULL && ax > p->aaj;  q = p, p = p->next)
		;
	if( p == head) {
		e->next = p;
		return e;
	} else {
		q->next = e;
		e->next = p;
		return head;
	}
}

void chGraph(Vk grh[]) {
	int i=0;
	for(i=0; i<E; i++) {
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		grh[v1].link=insertE(grh[v1].link, v2);
		grh[v2].link=insertE(grh[v2].link, v1);
	}
}


int Vis[MV]= {0};


void DFS(Vk  G[ ], int v) {
	Ek  *p;
	Vis[v] = 1;
	printf("%d ", v);

	for(p = G[v].link; p !=NULL;  p=p->next)
		if( !Vis[p->aaj] )
			DFS(G, p->aaj);
}

void  trDFS(Vk  G[ ], int n, int dV) {
	int i;
	for(i=0; i<n; i++)
		Vis[i] = 0 ;
	if(dV >= 0)
		Vis[dV] = 1;
	for(i=0; i<n; i++)
		if( !Vis[i] ) DFS(G, i);
	printf("\n");
}

#define MAXSIZE     1000
int  Q[MAXSIZE];
int  Front, Rear,Count;
void  initQ(void) {
	Front = 0;
	Rear = MAXSIZE-1;
	Count = 0;
}
int  isE(void) {
	return Count == 0;
}
int  isF(void) {
	return Count == MAXSIZE;
}
void enQ(int queue[ ], int item) {
	if(isF())
		printf("Full queue!");
	else {
		Rear = (Rear+1) % MAXSIZE;
		queue[Rear]=item;
		Count++;
	}
}
int  deQ(int queue[ ]) {
	int e;
	if(isE())
		printf("Empty queue!");
	else {
		e=queue[Front];
		Count--;
		Front = (Front+1) % MAXSIZE;
		return e;
	}
	return 0;
}


void BFS(Vk  G[ ], int v) {
	Ek  *p;
	initQ();
	Vis[v] = 1;
	enQ(Q, v);
	while( !isE()) {
		v = deQ(Q);
		printf("%d ",v);

		for(p=G[v].link; p!=NULL; p=p->next )
			if( !Vis[p->aaj] ) {
				Vis[p->aaj] = 1;
				enQ(Q, p->aaj);
			}
	}
}

void  trBFS(Vk  G[ ], int n, int dV) {
	int i;
	for(i=0; i<n; i++)
		Vis[i] = 0 ;
	if(dV >= 0)
		Vis[dV] = 1;
	for(i=0; i<n; i++)
		if( !Vis[i] )
			BFS(G, i);
	printf("\n");
}

