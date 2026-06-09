#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
    int adj;
    int wei;
    struct edge *next;
}ELink;
typedef struct ver{
	int vertax;
    ELink *next;
}VLink;
VLink G[100];
int visited[100];
int VerTodelete;
int queue[100],head=0,tail=-1;
ELink *insertedge(ELink *head,int avex){
    ELink *e,*p,*q=NULL;
    e=(ELink*)malloc(sizeof(ELink));
    e->adj=avex;
    e->wei=1;
    e->next=NULL;
    if(head==NULL){
        head=e;
    }
    else{
    	for(p=head;p!=NULL&&p->adj<avex;q=p,p=p->next);
    	if(p==head){
    		e->next=p;
    		head=e;
		}
		else{
			q->next=e;
			e->next=p;
		}
    }
    return head;
}
void visit(VLink G[],int v){
    printf("%d ",v);
}
void DFS(VLink G[],int v){
    ELink *p;
    visited[v]=1;
    visit(G,v);
    for(p=G[v].next;p!=NULL;p=p->next){
        if(!visited[p->adj]){
            DFS(G,p->adj);
        }
    }
}
void DFStravel(VLink G[],int n,int flag){
    int i;
    for(i=0;i<n;i++){
    	if(i!=flag)visited[i]=0;
    	else visited[i]=1;
	}
    for(i=0;i<n;i++){
        if(!visited[i])DFS(G,i);
    }
}
void BFS(VLink G[],int v){
	ELink *p;
	visited[v]=1;
	queue[++tail]=v;
	while(head<=tail){
		v=queue[head++];
		visit(G,v);
		for(p=G[v].next;p!=NULL;p=p->next){
			if(!visited[p->adj]){
				visited[p->adj]=1;
				queue[++tail]=p->adj;
			}
		}
	}
}
void BFStravel(VLink G[],int n,int flag){
	int i;
    for(i=0;i<n;i++){
    	if(i!=flag)visited[i]=0;
    	else visited[i]=1;
	}
	for(i=0;i<n;i++){
		if(!visited[i])BFS(G,i);
	}
}
int main(){
	int m,n,v1,v2,i;
	scanf("%d %d",&m,&n);
	while(n--){
		scanf("%d%d",&v1,&v2);
		G[v1].next=insertedge(G[v1].next,v2);
		G[v2].next=insertedge(G[v2].next,v1);
	}
	scanf("%d",&VerTodelete);
	DFStravel(G,m,-1);
	putchar('\n');
	BFStravel(G,m,-1);
	putchar('\n');
	for(i=0;i<100;i++)queue[i]=0;
	head=0;
	tail=-1;
	DFStravel(G,m,VerTodelete);
	putchar('\n');
	BFStravel(G,m,VerTodelete);
    return 0;
}

