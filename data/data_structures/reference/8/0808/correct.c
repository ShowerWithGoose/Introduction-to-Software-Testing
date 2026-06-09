#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h> 
#define tolower(c) (c>='A'&&c<='Z'?'a'-'A'+c:c)
#define max 1024
#define place e = (Elink *)malloc(sizeof(Elink))
#define maxv 100                                      //<最大顶点个数>
#define INFINITY 32767
typedef struct edge{                                 //边结点类型 
	int adjvex;
	struct edge *next;
}Elink;
typedef struct ver{                                   //顶点结点类型 
	Elink *link;
}Vlink;

int rear = max-1, front = 0, count = 0;
int Q[max]; 
void enQueue(int item);
int deQueue();

Elink *insertEdge(Elink *head, int avex);
void travelDFS(Vlink G[], int n, int Visited[],int flag);
void DFS(Vlink G[], int v, int Visited[]);
void travelBFS(Vlink G[], int n, int Visited[],int flag);
void BFS(Vlink G[], int v, int Visited[]);

int del;

int main()
{
	int i, n, v1, v2, e;
    scanf("%d %d", &n, &e);
    Vlink G[n];
    for(i=0; i<n; i++){
    	G[i].link = NULL;
	}
	for(i=0; i<e; i++){
    	scanf("%d %d", &v1, &v2);
    	G[v1].link = insertEdge(G[v1].link , v2);
    	G[v2].link = insertEdge(G[v2].link , v1);
	}
	scanf("%d", &del);
	/*for(i=0; i<n; i++){
		Elink *head, *p;
		head = G[i].link;
		printf("%d: ",i);
    	for(p=head; p!=NULL; p=p->next)
    	    printf("%d ", p->adjvex);
    	printf("\n");
	}*/
	int Visited[n];
	travelDFS(G, n, Visited, 0);
	printf("\n");
	travelBFS(G, n, Visited, 0);
	printf("\n");
	Elink *r, *p;
	for(p=G[del].link;p!=NULL;p=p->next){
		Elink *r;
		if(G[p->adjvex].link->adjvex == del)
			G[p->adjvex].link = G[p->adjvex].link->next;
		else{
		    for(r=G[p->adjvex].link;r->next->adjvex!=del;r=r->next);
		    r->next = r->next->next;
		}
	}
	G[del].link = NULL;
	travelDFS(G, n, Visited, 1);
	printf("\n");
	travelBFS(G, n, Visited, 1);
	printf("\n");
	return 0; 
}

Elink *insertEdge(Elink *head, int avex){
	Elink *e, *p, *r;
	e = place;
	e->adjvex = avex; e->next = NULL;
	if(head == NULL){
		head = e;
		return head;
	}
	if(head->adjvex > avex){
		e->next = head;
		head = e;
		return head;
	}
	for(p=head; (p->next!=NULL) && (p->adjvex < avex); p=p->next){
	    r = p;
	}
	if(p->adjvex > avex){
	    r->next = e;
		e->next = p;
	    return head;
	}
	else{
		p->next = e;
	    return head;
	}
}

void travelDFS(Vlink G[], int n, int Visited[], int flag){
	int i;
	for(i=0; i<n; i++) Visited[i] = 0;
	if(flag == 1)
		Visited[del] = 1;
	for(i=0; i<n; i++)
	    if( !Visited[i] )
	        DFS(G, i, Visited);
}
void DFS(Vlink G[], int v, int Visited[]){
	Elink *p;
	Visited[v] = 1;
	printf("%d ",v);
	for(p=G[v].link; p!=NULL; p=p->next)
	    if(!Visited[p->adjvex])
		    DFS(G, p->adjvex, Visited); 
}

void travelBFS(Vlink G[], int n, int Visited[], int flag){
	int i;
	for(i=0; i<n; i++) Visited[i] = 0;
	if(flag == 1)
		Visited[del] = 1;
	for(i=0; i<n; i++)
	    if( !Visited[i] )
	        BFS(G, i, Visited);
}
void BFS(Vlink G[], int v, int Visited[]){
	Elink *p;
	Visited[v] = 1;
	enQueue(v);
	while(count!=0){
		v = deQueue();
		printf("%d ",v);
		for(p=G[v].link; p!=NULL; p=p->next)
	        if(!Visited[p->adjvex]){
		        Visited[p->adjvex] = 1;
			    enQueue(p->adjvex);
		    }
	}
}


void enQueue(int item){
	if(count == max)
	    printf("Full ququq!\n");
	else{
		rear = (rear+1) % max;
		Q[rear] = item;
		count++;
	}
}
int deQueue(){
	int e;
	if(count == 0)
	    printf("Empty queue!\n");
	else{
		e = Q[front];
		count--;
		front = (front+1) % max;
		return e;
	}
}

