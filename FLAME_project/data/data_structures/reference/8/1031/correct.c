#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100+10
typedef struct node {
	int num;
	struct node *Link;
} Map;
Map *G[MAX];
int Visited[MAX],Quene[MAX],buttom,top;
Map *Ins(Map *toinsert,Map *s) {
	if(s==NULL) {
		s=toinsert;
		return s;
	} else {
		Map *p=toinsert;
		if(p->num<s->num) {
			p->Link=s;
			return p;
		} else {
			Map *q0=s;
			Map *q=s;
			q=q->Link;
			while(q!=NULL&&p->num>q->num) {
				q=q->Link;
				q0=q0->Link;
			}
			q0->Link=p;
			p->Link=q;
		}
		return s;
	}
}
void insert(int begin,int end) {
	Map *p1=(Map *)malloc(sizeof(Map));
	Map *p2=(Map *)malloc(sizeof(Map));
	p1->Link=p2->Link=NULL;
	p1->num=begin;
	p2->num=end;
	G[end]=Ins(p1,G[end]);
	G[begin]=Ins(p2,G[begin]);
}
void DFS(Map *G[],int i) {
	if(G[i]!=NULL) {
		Visited[i]=1;
		printf("%d ",i);
		Map *p=G[i];
		for(; p!=NULL; p=p->Link) {
			if(!Visited[p->num])
				DFS(G,p->num);
		}
	}
}
void DFStravel(Map *G[],int n) {
	int i;
	for(i=0; i<n; i++) {
		Visited[i]=0;
	}
	for(i=0; i<n; i++) {
		if(!Visited[i]) {
			DFS(G,i);
		}
	}
}
//void BFS(VLink  G[ ], int v)
//{
//    ELink  *p;
//    Visited[v] = 1; //标识某顶点已入队
//    enQueue(Q, v);
//    while( !emptyQ(Q)){
//         v = deQueue(Q);  //取出队头元素
//         VISIT(G, v); //访问当前顶点
//         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
//             if( !Visited[p->adjvex] ) {
//                    Visited[p->adjvex] = 1; //标识某顶点入队
//                    enQueue(G, p->adjvex);
//           }
//     }
//}
void enQuene(int i) {
	Quene[top++]=i;
}
int deQuene() {
	buttom++;
	return Quene[buttom-1];
}
int emptyQ() {
	if(buttom==top)
		return 1;
	else
		return 0;
}
void BFS(Map *G[],int i) {
	if(G[i]!=NULL) {
		Visited[i]=1;
		enQuene(i);
		while(!emptyQ()) {
			i=deQuene();
			printf("%d ",i);
			Map *p=G[i];
			for(; p!=NULL; p=p->Link) {
				if(!Visited[p->num]) {
					Visited[p->num]=1;
					enQuene(p->num);
				}
			}
		}
	}
}
void BFStravel(Map *G[],int n) {
	int i;
	for(i=0; i<n; i++) {
		Visited[i]=0;
	}
	for(i=0; i<n; i++) {
		if(!Visited[i]) {
			BFS(G,i);
		}
	}
}
int main() {
	int begin[2000],end[2000];
	int num_point,num_arc;
	scanf("%d%d",&num_point,&num_arc);
	int i;
	for(i=0; i<num_arc; i++) {
		scanf("%d%d",&begin[i],&end[i]);
		insert(begin[i],end[i]);
	}
	int todelete;
	scanf("%d",&todelete);
//	for(i=0;i<num_point;i++){
//		Map *p=G[i];
//		while(p!=NULL){
//			printf("%d -> %d ",i,p->num);
//			p=p->Link;
//		}
//		printf("\n");
//	}
	DFStravel(G,num_point);
	printf("\n");
	BFStravel(G,num_point);
	printf("\n");
	for(i=0; i<num_point; i++) {
		G[i]=NULL;
	}
	for(i=0; i<num_arc; i++) {
		if(begin[i]!=todelete&&end[i]!=todelete){
			insert(begin[i],end[i]);
		} 
	}DFStravel(G,num_point);
	printf("\n");
	BFStravel(G,num_point);
	printf("\n");
	return 0;
}

