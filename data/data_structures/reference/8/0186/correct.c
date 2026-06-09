#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int right;
	struct node *next; 
}edge;
typedef struct nodeptr{
	edge *link;
}ver;
ver G[101];
int flag[101]={0};
edge *insertEdge(edge *head,int avex){
	edge *e,*p;
	e=(edge*)malloc(sizeof(edge));
	e->right=avex;
	e->next=NULL;
	if(head==NULL||head->right>e->right){
		e->next=head;
		head=e;
		return head;
	}
	for(p=head;p->next!=NULL&&p->next->right<e->right;p=p->next);
	e->next=p->next;
	p->next=e;
	return head;
}
void Creatgraph(int x,int y){
	G[x].link=insertEdge(G[x].link,y);
	G[y].link=insertEdge(G[y].link,x);
}
int yansi=0;
void DFStravel(int n,int x){
	int i;
	for(i=0;i<n;i++) flag[i]=0;
	if(x!=-1) flag[x]=1;
	yansi=0;
	for(i=0;i<n;i++)
	    if(!flag[i]) DFS(i);
	printf("\n");
}
void DFS(int v){
	edge *p;
	flag[v]=1;
	if(yansi==1) printf(" ");
	printf("%d",v);
	yansi=1;
	for(p=G[v].link;p!=NULL;p=p->next)
	    if(!flag[p->right]) DFS(p->right);
}
void BFStravel(int n,int x){
	int i;
	for(i=0;i<n;i++) flag[i]=0;
	if(x!=-1) flag[x]=1;
	yansi=0;
	for(i=0;i<n;i++)
	    if(!flag[i]) BFS(i);
	printf("\n");
}
void BFS(int v){
	edge *p;
	flag[v]=1;
	int Q[21]={0},head=0,end=-1;
	if(yansi==1) printf(" ");
	printf("%d",v);
	yansi=1;
	Q[++end]=v;
	while(head<=end){
		v=Q[head++];
		for(p=G[v].link;p!=NULL;p=p->next)
		    if(!flag[p->right]){
		    	printf(" %d",p->right);
		    	flag[p->right]=1;
		    	Q[++end]=p->right;
			}
	}
}

int main(){
	int a,b,c,i,x,y;
	scanf("%d%d",&a,&b);
	for(i=0;i<b;i++){
		scanf("%d%d",&x,&y);
		Creatgraph(x,y);
	}
	scanf("%d",&c);
	DFStravel(a,-1);
	BFStravel(a,-1);
	DFStravel(a,c);
	BFStravel(a,c);
	return 0;
}



