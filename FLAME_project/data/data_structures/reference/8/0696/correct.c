#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>
#include<stdlib.h>

int table[105][105],visit[105],queue[205];
int n,line;

void dfs(int);
void bfs(void);

int main(){
	int i,a,b;
	scanf("%d%d",&n,&line);
	for(i=0;i<line;i++){
		scanf("%d",&a);
		visit[a]=0;
		scanf("%d",&b);
		table[a][b]=1;
		table[b][a]=1;
	}
	scanf("%d",&a);
	dfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	bfs();
	printf("\n");
	memset(visit,0,sizeof(visit));
	visit[a]=1;
	dfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	visit[a]=1;
	bfs();
	return 0;
}

void bfs(void){
	int front=0,rear=1,i;
	queue[front]=0;
	visit[front]=1;
	while(front<rear){
		for(i=0;i<n;i++){
			if(table[queue[front]][i]&&!visit[i]){
				queue[rear]=i;
				visit[i]=1;
				rear++;
			}
		}
		printf("%d ",queue[front]);
		front++;
	}
}

void dfs(int x){
	int i;
	visit[x]=1;
	printf("%d ",x);
	for(i=0;i<n;i++){
		if(!visit[i]&&table[x][i]){
			dfs(i);
		}
	}
	
}

