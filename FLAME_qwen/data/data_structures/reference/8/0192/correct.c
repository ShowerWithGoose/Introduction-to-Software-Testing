#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL  long long
#define ULL  unsigned long long

typedef struct edge{
    int end;
    int weight;
    struct edge *next;
}Elink;
typedef struct ver{
    int i;
    Elink *link;
}Vlink;

int visited[150]={0};
int del=-2;
void createGraph(Vlink graph[],int m);
Elink *insertEdge(Elink *head,int end);
void DFS(Vlink G[],int v);
void BFS(Vlink G[],int v);

int main(void){
	int n,m;
	scanf("%d %d",&n,&m);
	Vlink G[n+1];
	for(int i=0;i<n;i++){
		G[i].link=NULL;
		G[i].i=i;
	}
	createGraph(G,m);
	DFS(G,0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(G,0);
	printf("\n");
	memset(visited,0,sizeof(visited));

	scanf("%d",&del);
	DFS(G,0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(G,0);
	return 0;
}

void createGraph(Vlink graph[],int m){
    int v1,v2;
    for(int i=0;i<m;i++){
        scanf("%d %d",&v1,&v2);
		graph[v1].link=insertEdge(graph[v1].link,v2);
		graph[v2].link=insertEdge(graph[v2].link,v1);
    }
}
Elink *insertEdge(Elink *head,int end){
    Elink *p,*q;
    q=(Elink*)malloc(sizeof(Elink));
    q->end=end;
    q->next=NULL;
    if(head==NULL||head->end>end){
        q->next=head;
		head=q;
        return head;
    }
	p=head;
	while(p->next&&p->next->end<end)p=p->next;
    q->next=p->next;
	p->next=q;
    return head;
}
void DFS(Vlink G[],int v){
    Elink *p;
    if(G[v].i!=del)printf("%d ",G[v].i);
	else return;
    visited[v]=1;
    for(p=G[v].link;p!=NULL;p=p->next){
        if(!visited[p->end]&&p->end!=del){
            DFS(G,p->end);
        }
    }
}
void BFS(Vlink G[],int v){
    Vlink queue[150]={0};
    int front=0,rear=0;
    Elink *p;
    if(G[v].i!=del)printf("%d ",G[v].i);
	else return;
    visited[v]=1;
    queue[front++]=G[v];
    while(front>rear){
        v=queue[rear++].i;
        p=G[v].link;
        for(;p!=NULL;p=p->next){
            if(!visited[p->end]&&p->end!=del){
                printf("%d ",G[p->end].i);
                visited[p->end]=1;
                queue[front++]=G[p->end];
            }
        }
    }
}
// 9 10
// 0 1
// 0 2
// 1 4
// 1 3
// 1 8
// 8 6
// 3 6
// 7 2
// 7 5
// 5 2
// 3
