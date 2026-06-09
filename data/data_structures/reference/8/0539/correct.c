#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct queue{
	int v;
	struct queue* link;
}queue,*pqueue;

pqueue head,end;
int A[105][105]={};
int visit[105]={0};

void DFS(int,int);
void insertqueue(int);
void BFS(int ,int);
void delqueue();

int main(){
	int vernum,bnum;
	int j,k;
	scanf("%d%d",&vernum,&bnum);
	for(int i=0;i<bnum;i++){
		scanf("%d%d",&j,&k);
		A[j][k]=1;
		A[k][j]=1;
	}
	DFS(vernum,0);
	printf("\n");
	for(int i=0;i<105;i++){
		visit[i]=0;
	}
	BFS(vernum,0);
	printf("\n");
	for(int i=0;i<105;i++){
		visit[i]=0;
	}
	int op;
	scanf("%d",&op);
	for(int i=0;i<vernum;i++){
		if(A[op][i]==1){
			A[op][i]=0;
			A[i][op]=0;
		}
	}
	DFS(vernum,0);
	printf("\n");
	for(int i=0;i<105;i++){
		visit[i]=0;
	}
	BFS(vernum,0);	
	return 0;
} 


//深度优先遍历
void DFS (int vernum,int ver){
	visit[ver]=1;
	printf("%d ",ver);
	for(int i=0;i<vernum;i++){
		if(A[ver][i]==1&&visit[i]==0){
			DFS(vernum,i);
		}
	}
}

//广度优先遍历
void BFS(int vernum,int ver){
	printf("%d ",ver);
	visit[ver]=1;
	end=(pqueue)malloc(sizeof(queue));
	head=NULL;
	insertqueue(ver);
	int u;
	while(head!=NULL){
		u=head->v;
		delqueue();
		for(int i=0;i<vernum;i++){
			if(A[u][i]==1&&visit[i]==0){
				printf("%d ",i);
				visit[i]=1;
				insertqueue(i);
			}
		}
	}
} 


void insertqueue(int v){
	pqueue p;
	p=(pqueue)malloc(sizeof(queue));
	p->v=v;
	p->link=NULL;
	end->link=p;
	end=p;
	if(head==NULL){
		head=end;
	}
}

void delqueue(){
	head=head->link;
}	

