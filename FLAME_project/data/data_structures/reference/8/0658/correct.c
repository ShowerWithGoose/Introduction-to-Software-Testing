#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 2560
typedef struct  edge{ 
   int  adjvex;
   struct edge *next;
}ELink;
typedef struct ver{
	ELink *link;
}VLink;
VLink g[MAX];
int visit[MAX];
int ans[MAX];
int queue[MAX];
int rear=0,front=0,cnt=0;
ELink *insert(ELink *head,int node){
	ELink *current=head,*insertnode=(ELink*)malloc(sizeof(ELink));
	ELink *pre=NULL;
	insertnode->adjvex=node;
	insertnode->next=NULL;
	if(head==NULL) return insertnode;
	if(head->adjvex>node){
		insertnode->next=current;
		head=insertnode;
		return head;
	}
	while(current->adjvex<node&&current->next!=NULL){
		pre=current;
		current=current->next;
	}
	if(current->next==NULL){
		if(current->adjvex<node) current->next=insertnode;
		else{
			insertnode->next=current;
			pre->next=insertnode;
		}
	}
	else{
		insertnode->next=current;
		pre->next=insertnode;
	}
	return head;
}
void DFS(VLink g[],int i){
	ELink *current;
	visit[i]=1;
	ans[cnt++]=i;
	for(current=g[i].link;current!=NULL;current=current->next) 
		if(!visit[current->adjvex]) DFS(g,current->adjvex);
}
void BFS(VLink g[],int i){
	ELink *p;
	ans[cnt++]=i;
	visit[i]=1;
	queue[rear++]=i;
	while(rear!=front){
		i=queue[front++];
		for(p=g[i].link;p!=NULL;p=p->next){
			if(!visit[p->adjvex]){
				ans[cnt++]=p->adjvex;
				visit[p->adjvex]=1;
				queue[rear++]=p->adjvex;
			}
		}
	}
}
int main(){
	int edgenum,n,v1,v2;
	scanf("%d%d",&n,&edgenum);
	for(int i=0;i<edgenum;i++){
		scanf("%d%d",&v1,&v2);
		g[v1].link=insert(g[v1].link,v2);
		g[v2].link=insert(g[v2].link,v1);
	}
	int deldata;
	scanf("%d",&deldata);
	for(int i=0;i<n;i++) if(!visit[i]) DFS(g,i);
	for(int i=0;i<n;i++) visit[i]=0;
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
	cnt=front=rear=0;
	puts("");
	for(int i=0;i<n;i++) if(!visit[i]) BFS(g,i);
	for(int i=0;i<n;i++) visit[i]=0;
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
	cnt=front=rear=0;
	puts("");
	visit[deldata]=1;
	for(int i=0;i<n;i++) if(!visit[i]) DFS(g,i);
	for(int i=0;i<n;i++) visit[i]=0;
	for(int i=0;i<n-1;i++) printf("%d ",ans[i]);
	cnt=front=rear=0;
	puts("");
	visit[deldata]=1;
	for(int i=0;i<n;i++) if(!visit[i]) BFS(g,i);
	for(int i=0;i<n-1;i++) printf("%d ",ans[i]);
//	puts("");
//	printf("%d %d %d %d",g[1].link->adjvex,g[1].link->next->adjvex,g[1].link->next->next->adjvex,g[1].link->next->next->next->adjvex);
}

