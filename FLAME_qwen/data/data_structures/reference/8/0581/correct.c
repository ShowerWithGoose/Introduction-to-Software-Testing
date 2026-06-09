#include <stdio.h>

int visited[100]={0};
int egs[100][100]={0};
int N,E;
int wait[100]={0};
int qh=0,qt=0;

void DFS(int p);
void BFS(int p);

int main()
{
	int i,j,m,n,e;
	scanf("%d%d",&N,&E);
	for(e=0;e<E;e++){
		scanf("%d%d",&i,&j);
		egs[i][j]=1;
		egs[j][i]=1;
	}
	scanf("%d",&n);
	visited[0]=1;
	DFS(0);
	printf("\n");
	for(i=1;i<N;i++){
		visited[i]=0;
	}
	BFS(0);
	printf("\n");
	for(i=1;i<N;i++){
		visited[i]=0;
	}
	visited[n]=1;
	DFS(0);
	printf("\n");
	for(i=1;i<N;i++){
		visited[i]=0;
	}
	qh=0;
	qt=0;
	visited[n]=1;
	BFS(0);
	return 0;
}

void DFS(int p)
{
	int i;
	printf("%d ",p);
	for(i=0;i<N;i++){
		if(egs[p][i]==1&&!visited[i]){
			visited[i]=1;
			DFS(i);
		}
	}
}

void BFS(int p)
{
	int i;
	printf("%d ",p);
	for(i=0;i<N;i++){
		if(egs[p][i]==1&&!visited[i]){
			visited[i]=1;
			wait[qt++]=i;
		}
	}
	if(qh<qt)
	BFS(wait[qh++]);
}

