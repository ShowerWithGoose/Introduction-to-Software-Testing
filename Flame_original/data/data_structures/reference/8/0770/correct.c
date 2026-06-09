#include <stdio.h>
#include <stdlib.h>
typedef struct edge{
	int end;
	struct edge *next;
}edge;
int vis[122]={0};
edge *V[123];		//V[i] is vertex i
void addEdge(int st, int end);
void dfs(int vnow);
void bfs();
int main(){
	memset(V, 0, sizeof(V));
	int numE, numV, st, end;
	scanf("%d%d", &numV, &numE);
	for(int i=0; i<numE; i++){
		scanf("%d%d", &st, &end);	
		addEdge(st, end);
		addEdge(end, st);
	}
	
	memset(vis, 0, sizeof(vis));	dfs(0);		printf("\n");
	bfs(0);
	
	int Edel;	scanf("%d", &Edel);
	V[Edel]->end = -1;
	
	memset(vis, 0, sizeof(vis));	dfs(0);		printf("\n");	
	bfs(0);
	return 0;
}
void bfs(){
	memset(vis, 0, sizeof(vis));	
	int vnow=0, queue[123]={0}, head=0, tail=0;
	while(head <= tail){
		vnow = queue[head++];
		vis[vnow] = 1;
		printf("%d ", vnow);

		for(edge *p=V[vnow]; p!=NULL; p=p->next){
			if(V[p->end]->end!=-1 && vis[p->end]!=1){
				queue[++tail] = p->end;
				vis[p->end] = 1;	
			}
		}
	}
	printf("\n");
}
void dfs(int vnow){
	if(1==vis[vnow] || -1==V[vnow]->end)	return;
	printf("%d ", vnow);
	vis[vnow] = 1;
	for(edge *p=V[vnow]; p!=NULL; p=p->next){
		if(V[p->end]->end != -1)	dfs(p->end);
	}
	
}
void addEdge(int st, int end){	//rising num
	edge *p=V[st], *add = (edge*)malloc(sizeof(edge));
	add->end = end;
	if(NULL==p || end<p->end){
		add->next = p;
		V[st]=add;
		return;	
	}
	while(p->next != NULL && end>p->next->end)	p=p->next;
	add->next = p->next;	p->next = add;
}

