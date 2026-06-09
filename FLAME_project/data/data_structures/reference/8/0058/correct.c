#include<stdio.h>
#include<string.h>

#define MAX 999

int v,e;
int link[MAX][MAX];

void DFS(int index, int* visit){
	visit[index]=1;
	printf("%d ",index);
	for(int i=0;i<v;i++){
		if(link[index][i]&&!visit[i]) DFS(i,visit);
	}
}

void BFS(int index, int* visit){
	int* queue = (int*)malloc(sizeof(int)*(2*v+2));
	int qtail = 0;
	int qhead = 0;
	queue[qtail++] = index;
	visit[index]=1;
	
	while(qtail-qhead>0){
		index = queue[qhead++];
		printf("%d ",index);
		for(int i=0;i<v;i++){
			if(link[index][i]&&!visit[i]) {
				queue[qtail++] = i;
				visit[i] = 1;
			}
		}
	}
}

int main(){
	scanf("%d %d",&v,&e);
	for(int i=0;i<e;i++){
		int v1, v2;
		scanf("%d %d",&v1,&v2);
		link[v1][v2]=link[v2][v1]=1;
	}
	int* visit = (int*)malloc(sizeof(int)*v);
	memset(visit,0,sizeof(int)*v);
	DFS(0,visit); printf("\n");
	memset(visit,0,sizeof(int)*v);
	BFS(0,visit); printf("\n");
	int rm;
	scanf("%d", &rm);
	for(int i=0;i<v;i++){
		link[rm][i] = link[i][rm] = 0;
	}
	memset(visit,0,sizeof(int)*v);
	DFS(rm?0:1,visit); printf("\n");
	memset(visit,0,sizeof(int)*v);
	BFS(rm?0:1,visit); printf("\n");
}


