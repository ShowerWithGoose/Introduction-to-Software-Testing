#define eps 1e-11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
int n, m;
int matrix[110][110];
int visited[110];
int queue[110];
int start = 0,end=-1;
void dfs(int n, int level) {
	visited[level]=1;
	printf("%d ",level);
	for (int i = 0; i < n; i++) {
		if (matrix[level][i] == 1)
			if (visited[i] == 0)
				dfs(n,i);
	}
	return ;
}
void bfs(int n, int level) {
	printf("%d ",level);
	visited[level]=1;
	queue[++end]=level;
	while (start<=end) {
		level=queue[start++];
		for (int i = 0; i < n; i++) {
			if (matrix[level][i] == 1)
				if (visited[i] == 0){
					printf("%d ",i);
					visited[i]=1;
					queue[++end]=i;
				}
		}
	}
	return ;
}
int main() {
	scanf("%d%d", &n, &m);
	//int i,j=0;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		matrix[v1][v2] = 1;
		matrix[v2][v1] = 1;
	}
	memset(visited,0,sizeof(visited));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]==1){
				if(visited[i]==0){
					dfs(n,i);
					break;
				}
			}
		}
	}
	printf("\n");
	memset(visited, 0, sizeof(visited));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(matrix[i][j]==1)
				if(visited[i]==0){
				bfs(n,i);
				break;
			}
	}
	printf("\n");
	memset(visited,0,sizeof(visited));
	memset(queue,0,sizeof(queue));
	int laji;
	scanf("%d",&laji);
	for(int i=0;i<n;i++){
		matrix[i][laji]=0;
		matrix[laji][i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(matrix[i][j]==1)
				if(visited[i]==0){
			dfs(n,i);
			break;
		}
	}
	printf("\n");
	memset(visited, 0, sizeof(visited));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(matrix[i][j]==1)
				if(visited[i]==0){
			bfs(n,i);
			break;
		}
	}
	printf("\n");
	return 0;
}

