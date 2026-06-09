#include <stdio.h>
#include <string.h>
int edge[120][120]= {};
int visit[120]= {};
void DFS(int numl,int n) {
	visit[n]=1;
	printf("%d ",n);
	for(int i=0; i<numl; i++) {
		if(visit[i]!=1&&edge[i][n]==1) {
			DFS(numl,i);
		}
	}
}
void BFS(int numl,int n) {
	visit[n]=1;
	int queue[1000]= {};
	int end=0,beg=0;
	queue[end++]=n;
	while(end!=beg) {
		int p=queue[beg];
		for(int i=0; i<numl; i++) {
			if(visit[i]!=1&&edge[i][p]==1) {
				queue[end++]=i;
				visit[i]=1;
			}
		}
		printf("%d ",queue[beg++]);
	}
}
int main() {
	int point[120];
	int numl,nume,del;
	scanf("%d%d",&numl,&nume);
	for(int i=0; i<nume; i++) {
		int a1,a2;
		scanf("%d%d",&a1,&a2);
		edge[a1][a2]=1;
		edge[a2][a1]=1;
	}
	scanf("%d",&del);
	memset(visit,0,sizeof(visit));
	for(int i=0; i<numl; i++)
		if(visit[i]==0) DFS(numl,i);
	memset(visit,0,sizeof(visit));
	printf("\n");
	for(int i=0; i<numl; i++)
		if(visit[i]==0) BFS(numl,i);
	memset(visit,0,sizeof(visit));
	printf("\n");
	for(int i=0; i<numl; i++) {
		edge[i][del]=0;
		edge[del][i]=0;
	}
	memset(visit,0,sizeof(visit));
	for(int i=0; i<numl; i++)
		if(visit[i]==0&&i!=del) DFS(numl,i);
	memset(visit,0,sizeof(visit));
	printf("\n");
	for(int i=0; i<numl; i++)
		if(visit[i]==0&&i!=del) BFS(numl,i);
}

