#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int matrix[120][120], visited[120], queue[120];
//ÁÚ½Ó¾ØÕó 
void DFS(int v, int t);
void BFS(int v, int t);
void beforeD(int v);
void beforeB(int v);
int main(void)
{
	int x,y,m,n,d;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		scanf("%d %d", &x, &y);
		matrix[x][y] = matrix[y][x] = 1;
	}//´¢´æÍ¼ 
	beforeD(n);
	memset(visited, 0, sizeof(visited));//£¡£¡ 
	beforeB(n);
	scanf("%d", &d);
	for (int i = 0; i <n; i++)
	{
		matrix[i][d] = matrix[d][i] = 0;
	}//Í¨¹ýÁÚ½Ó¾ØÕóÉ¾³ýµã 
	memset(visited, 0, sizeof(visited));//£¡£¡ 
	beforeD(n);
	memset(queue, -1, sizeof(queue));//
	memset(visited, 0, sizeof(visited));
	beforeB(n);
	return 0; 
}
void DFS(int v, int t){
	visited[t] = -1;
	printf("%d ", t);
	int i;
	for (i = 0; i < v; i++){
		if (matrix[t][i] == 1){
			if (visited[i] != -1){
				DFS(v, i);
			}
		}
	}
}
void beforeD(int v){
	int i, j;
	for (i = 0; i < v; i++)
		for (j = 0; j < v; j++)
			if (matrix[i][j] == 1)
				if (visited[i] != -1){
					DFS(v, i);
					break;
				}
	printf("\n");
	return;
}
void BFS(int v, int t){
	int i, start = 0, end = -1;
	printf("%d ", t);
	visited[t] = -1;
	queue[++end] = t;
	while (start <= end){
		t = queue[start++];
		for (i = 0; i < v; i++)
		{
			if (matrix[t][i])
				if (visited[i] != -1){
					printf("%d ", i);
					visited[i] = -1;
					queue[++end] = i;
				}
		}
	}
	return;
}
void beforeB(int v){
	int i, j;
	for (i = 0; i < v; i++){
		for (j = 0; j < v; j++)
			if (matrix[i][j] == 1)
				if (visited[i] != -1){
					BFS(v, i);
					break;
				}
	}
	printf("\n");
	return;
}




