#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX_N 105

typedef struct ELINK{
	int to_Val;
	struct ELINK *next;
}elink;

typedef struct VLINK{
	int Val_id;
	elink *next;
}vlink;

elink *insert(elink *,int );
void initVal();
void DFS(vlink g[],int );
void BFS(vlink g[],int );
void Delete(vlink g[],int ,int );

vlink G[MAX_N];
int visited[MAX_N];

int main(){
	
	initVal();
	int Val_Num,Edge_Num;
	scanf("%d%d",&Val_Num,&Edge_Num);
	
	int v1,v2,del;
	for(int i=0;i<Edge_Num;i++){
		scanf("%d%d",&v1,&v2);
		G[v1].next=insert(G[v1].next,v2);
		G[v2].next=insert(G[v2].next,v1);
	}
	scanf("%d",&del);
		
	DFS(G,0);
	putchar('\n');
	memset(visited,0,sizeof(visited));
	
	BFS(G,0);
	putchar('\n');
	memset(visited,0,sizeof(visited));
	
	Delete(G,del,Val_Num);
	
	DFS(G,0);
	putchar('\n');
	memset(visited,0,sizeof(visited));
	
	BFS(G,0);
	putchar('\n');
	memset(visited,0,sizeof(visited));	
	
	return 0;
}

void initVal(){
	for(int i=0;i<MAX_N;i++){
		G[i].next=NULL;
		G[i].Val_id=i;
		visited[i]=0;
	}
}

elink *insert(elink *head,int val){
	elink *pt;
	pt=(elink *)malloc(sizeof(elink));
	pt->to_Val=val;
	pt->next=NULL;
	if(head==NULL)	head=pt;
	else {
		elink *q=NULL,*t=head;
		for(;t!=NULL&&t->to_Val<val;q=t,t=t->next)
			;
		if(t==NULL)	q->next=pt;
		else if(q==NULL){
			pt->next=t;
			head=pt;
		}else {
			pt->next=t;
			q->next=pt;
		}
	}
	return head;
}

void Delete(vlink g[],int val,int num){
	for(int i=0;i<num;i++){
		if(i!=val){
			elink *pt=g[i].next,*q=NULL;
			if(pt->to_Val==val){
				g[i].next=pt->next;
				free(pt);
				continue;
			}
			for(;pt!=NULL&&pt->to_Val!=val;q=pt,pt=pt->next)
				;
			if(pt!=NULL) {
				if(q==NULL)	g[i].next=NULL;		
				else 	q->next=pt->next;
				free(pt);
			}
		}else{
			elink *p=g[i].next,*q;
			while(p!=NULL){
				q=p;
				p=p->next;
				free(q);
			}
		} 	
	}
}

void DFS(vlink g[],int val){
	printf("%d ",val);
	visited[val]=1;
	elink *pt=g[val].next;
	while(pt!=NULL){
		if(!visited[pt->to_Val])
			DFS(g,pt->to_Val);
		pt=pt->next;
	}
}

void BFS(vlink g[],int val){
	int queue[205];
	int front=0,rear=0,cnt=1;
	queue[0]=val;
	visited[val]=1;
	while(cnt!=0){
		printf("%d ",queue[front]);
		elink *pt=g[queue[front++]].next;
		cnt--;
		while(pt!=NULL){
			if(!visited[pt->to_Val]){
				visited[pt->to_Val]=1;
				queue[++rear]=pt->to_Val;
				cnt++;			
			}
			pt=pt->next;
		}
	}
}

