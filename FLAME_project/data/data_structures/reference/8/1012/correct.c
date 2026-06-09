#include <stdio.h>
#include <stdlib.h>

int v, e, i, ver1, ver2, dele;
int visited[100], Visited[100], Q[100], rear=0, top=0;
typedef struct edge{
	int adjvex;
	struct edge *next;
}Elink;
typedef struct ver{
	Elink *link;
}Vlink;
Vlink G[100];
Elink *insertEdge(Elink *head, int avex){
	Elink *e = (Elink *)malloc(sizeof(Elink));
	e->adjvex = avex; e->next = NULL; 
	Elink *previous = NULL; 
	Elink *current = head;
	while (current != NULL && current->adjvex < e->adjvex) {
		previous = current;
		current = current->next;
	}
	e->next = current;
	if (previous == NULL) {
		head = e;
	} else {
		previous->next = e;
	}
	return head;
}
Elink *deleteVer(Elink *head, int dele){
	Elink *p, *q;
	p = head; q = NULL;
	while(p!=NULL){
		if(p->adjvex==dele){
			if(p==head){
				head = p->next;
				p = head;
			}
			else{
				q->next = p->next;
				p = q->next;
			}
		}
		else{
			q = p;
			p=p->next;
		}
	}
	return head;
}

void DFS(Vlink G[], int v){
	Elink *p;
	visited[v] = 1;
	printf("%d ", v);
	for(p=G[v].link;p!=NULL;p=p->next)
		if(!visited[p->adjvex])
			DFS(G, p->adjvex);
}
void BFS(Vlink G[], int v){
	Elink *p;
	printf("%d ", v);
	Visited[v] = 1;
	Q[rear++] = v;
	while(top!=rear){
		v = Q[top++];
		p = G[v].link;
		for(;p!=NULL;p = p->next){
			if(!Visited[p->adjvex]){
				printf("%d ", p->adjvex);
				Visited[p->adjvex] = 1;
				Q[rear++] = p->adjvex;
			}
		}
	}
}

int main(){
	scanf("%d %d", &v, &e);
	for(i=0;i<e;i++){
		scanf("%d %d", &ver1, &ver2);
		G[ver1].link = insertEdge(G[ver1].link, ver2);
		G[ver2].link = insertEdge(G[ver2].link, ver1);
	}
	DFS(G, 0);
	printf("\n");
	BFS(G, 0);
	printf("\n");
	scanf("%d", &dele);
	for(i=0;i<v;i++){
		G[i].link = deleteVer(G[i].link, dele);
	}
	for(i=0;i<v;i++){
		visited[i] = 0; Visited[i] = 0;
	}
	DFS(G, 0);
	printf("\n");
	BFS(G, 0);
	printf("\n");
	return 0;
} 







