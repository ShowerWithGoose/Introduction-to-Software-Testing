#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int val;
	int jud;
	struct node * pNext;
} * pNode;
typedef struct Queue_{
	int data[1000];
	int front;
	int rear;
} Queue ,*LQueue;

pNode a[1000];
int Visited[1000];
int d1[1000],b1[1000],topd,topb;
LQueue Q;
int w;
int x1[1000],x2[1000],x3[1000],x4[1000],top1,top2,top3,top4;

void Create(int i){
	pNode pNew=(pNode)malloc(sizeof(struct node));
	pNew->val=i;pNew->pNext =NULL;pNew->jud =0;
	a[i]=pNew;
}
void link(int t1,int t2){
	int i,j,k;
	pNode p,q;
	for(p=a[t1],q=a[t1]->pNext ;q!=NULL;p=p->pNext,q=q->pNext ){
		if(q->val >t2) break;
	}
	pNode pNew=(pNode)malloc(sizeof(struct node));
	pNew->pNext =q;pNew->val =t2;
	p->pNext =pNew;
	for(p=a[t2],q=a[t2]->pNext ;q!=NULL;p=p->pNext,q=q->pNext ){
		if(q->val >t1) break;
	}
	pNew=(pNode)malloc(sizeof(struct node));
	pNew->val =t1;pNew->pNext =q;
	p->pNext =pNew; 
}

void DFS(int v){
	pNode p;
	Visited[v]=1;
	d1[topd++]=v;
	for(p=a[v]->pNext ;p!=NULL;p=p->pNext ){
		if(p->val ==w) continue;
		if(!Visited[p->val ]) DFS(p->val );
	}
}
void travelDFS(int n){
	int i;
	for(i=0;i<n;i++) Visited[i]=0;
	for(i=0;i<n;i++){
		if(i==w) continue;
		if(Visited[i]==0)	DFS(i);
	}
}

int Is_Empty(){
	if(Q->front ==Q->rear ) return 1;
	return 0;
}
void enQueue(int i){
	Q->data [Q->rear ]=i;
	Q->rear =Q->rear +1;
}
int deQueue(){
	Q->front ++;
	return Q->data [Q->front -1];
}
void BFS(int v){
	pNode p;
	b1[topb++]=v;
	Visited[v]=1;
	enQueue(v);
	while(!Is_Empty()){
		v=deQueue();
		p=a[v]->pNext ;
		for(;p!=NULL;p=p->pNext ){
			if(p->val ==w) continue;
			if(!Visited[p->val ]){
				b1[topb++]=p->val ;
				Visited[p->val ]=1;
				enQueue(p->val );
			}
		}
	}
}
void travelBFS(int n){
	int i;
	for(i=0;i<n;i++) Visited[i]=0;
	for(i=0;i<n;i++){
		if(i==w) continue;
		if(Visited[i]==0) BFS(i);
	}
	
}

int main()
{
	int i,j,k;
	int n,m;
	int t1,t2;
	w=-1;
	scanf("%d%d ",&n,&m);
	Q=(LQueue)malloc(sizeof(Queue));Q->front =Q->rear =0;
	for(i=0;i<n;i++) Create(i);
	for(i=0;i<m;i++){
		scanf("%d %d",&t1,&t2);
		link(t1,t2);
	}
	pNode p;
	
	travelDFS(n);
	for(i=0;i<topd;i++) x1[i]=d1[i];top1=topd;
	topd=0;memset(d1,0,sizeof(d1));
	
	travelBFS(n);
	for(i=0;i<topb;i++) x2[i]=b1[i];top2=topb;
	topb=0;memset(b1,0,sizeof(b1));Q->front =Q->rear =0;
	
	scanf("%d",&w);
	travelDFS(n);
	for(i=0;i<topd;i++) x3[i]=d1[i];top3=topd;
	
	travelBFS(n);
	for(i=0;i<topb;i++) x4[i]=b1[i];top4=topb;
	
	for(i=0;i<top1;i++) printf("%d ",x1[i]);printf("\n");
	for(i=0;i<top2;i++) printf("%d ",x2[i]);printf("\n");
	for(i=0;i<top3;i++) printf("%d ",x3[i]);printf("\n");
	for(i=0;i<top4;i++) printf("%d ",x4[i]);printf("\n");
	return 0;
 } 

