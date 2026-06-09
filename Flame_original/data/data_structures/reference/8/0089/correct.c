#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
struct edge{
	int adjvex;
	struct edge *next;
};
typedef struct edge *Nodeptr;
typedef struct edge Node;
Nodeptr Graph[MAX];
int Visit[MAX]={0};
int front=0,rear=0;
int Que[100];
void enQue(int a)
{
	Que[rear++]=a;
}
int deQue()
{
	return Que[front++];
}
int isEmpty()
{
	if(front==rear) return 1;
	else return 0;
}
Nodeptr insert(Nodeptr head,int a)
{
	Nodeptr p,q,r;
	r=(Nodeptr)malloc(sizeof(Node));
	p=(Nodeptr)malloc(sizeof(Node));
	p->adjvex=a;
	p->next=NULL;
	if(head->next==NULL){
		head->next=p;
		return head;
	}
	for(q=head->next;q!=NULL&&q->adjvex<a;r=q,q=q->next);
	if(q==head->next){
		head->next=p;
		p->next=q;
	}
	else{
		r->next=p;
		p->next=q; 
	}
	return head;
}
void DFS(Nodeptr G[],int v)
{
	Nodeptr p;
	Visit[v]=1;
	printf("%d ",v);
	for(p=G[v]->next;p!=NULL;p=p->next)
	if(!Visit[p->adjvex])
	DFS(G,p->adjvex);
	
}
void BFS(Nodeptr G[],int v)
{
	Nodeptr p;
	Visit[v]=1;
	printf("%d ",v);
	enQue(v);
	while(!isEmpty()){
		v=deQue();
		p=G[v];
		for(p=p->next;p!=NULL;p=p->next){
			if(!Visit[p->adjvex]){
				printf("%d ",p->adjvex);
				Visit[p->adjvex]=1;
				enQue(p->adjvex);
			}
		}
	}
	
}
void delete(Nodeptr G[],int num,int n)
{
	int i;
	Nodeptr q,p;
	q=(Nodeptr)malloc(sizeof(Node));
	for(i=0;i<n;i++){
		if(i==num) free(G[i]);
		else{
			for(p=G[i];p!=NULL&&p->adjvex!=num;q=p,p=p->next);
			if(p!=NULL){
				q->next=p->next;
			    free(p);
			}
		}
	}
}
int main()
{
	int n,l,a1,a2,i;
	scanf("%d %d",&n,&l);
	for(i=0;i<n;i++){
		Graph[i]=(Nodeptr)malloc(sizeof(Node));
		Graph[i]->next=NULL;
	}
	for(i=0;i<l;i++){
		if((scanf("%d %d",&a1,&a2))==EOF) break;
		Graph[a1]=insert(Graph[a1],a2);
		Graph[a2]=insert(Graph[a2],a1); 
	}
	scanf("%d",&a1);
	DFS(Graph,0);
	memset(Visit,0,sizeof(Visit));
	printf("\n");
	BFS(Graph,0);
	delete(Graph,a1,n);
	memset(Visit,0,sizeof(Visit));
	printf("\n");
	DFS(Graph,0);
	memset(Visit,0,sizeof(Visit));
	printf("\n");
	BFS(Graph,0);
 } 

