#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//#include <stdlib.h>
//int edge[110][110];
//int visited[110];
//int queen[1000];
//int head = -1, rear = -1;
//int nodenum, edgenum, i, j, x, y, node_to_be_delete;
//void DFS(int v){
//	int j;
//	visited[v] = 1;
//	printf("%d ", v);
//	j = 0;
//	while (j < nodenum){
//		while (edge[v][j] == 0) j++;
//		if ((!visited[j]) && j < nodenum)  DFS(j);
//		j++;
//	}
//}
//void deleteDFS(int v){
//	int j;
//	visited[v] = 1;
//	printf("%d ", v);
//	j = 0;
//	while (j < nodenum){
//		while (edge[v][j] == 0 || j == node_to_be_delete) j++;
//		if ((!visited[j]) && j < nodenum)  deleteDFS(j);
//		j++;
//	}
//}
//void travelDFS(int n){
//	int i;
//	for (i = 0; i < n; i++)  visited[i] = 0;
//	for (i = 0; i < n; i++){
//		if (!visited[i])  DFS(i);
//	}
//}
//void travelDeleteDFS(int n){
//	int i;
//	for (i = 0; i < n; i++)  visited[i] = 0;//初始化
//	for (i = 0; i < n; i++){
//		if (i == node_to_be_delete) i++;//排除
//		if (!visited[i])  deleteDFS(i);
//	}
//}
//void BFS(int v){
//	int j;
//	visited[v] = 1;
//	printf("%d ", v);
//	j = 0; 
//	
//}
//void travelBFS(int n){
//	int i;
//	for (i = 0; i < n; i++)  visited[i] = 0;
//	for (i = 0; i < n; i++){
//		if (!visited[i])  BFS(i);
//	}
//}
//int main(){
//	scanf("%d%d", &nodenum, &edgenum);
//	for (i = 0; i < edgenum; i++){
//		scanf("%d%d", &x, &y);
//		edge[x][y] = 1; edge[y][x] = 1;
//	}
//	scanf("%d", &node_to_be_delete);
//	for (i = 0; i < nodenum; i++){
//		for (j = 0; j < nodenum; j++){
//			printf("%d ", edge[i][j]);
//		}
//		printf("\n");
//	}
//
//	travelDFS(nodenum);
//	printf("\n");
//	travelDeleteDFS(nodenum);
//	printf("\n");
//	return 0;
//}
#include<stdio.h>
#include<string.h>
int weights[200][200], visited[200] = { 0 }, que[200];
// weights图的邻接矩阵， visited访问数组， que BFS用的访问队列 
int n, m;	//顶点数和边数 
void travelDFS(int v)
{
	int i;
	printf("%d ", v);	//输出 
	visited[v] = 1;		//已访问 
	for (i = 0; i < n; i++)
	if (weights[v][i] && !visited[i])	//如果矩阵元素为 1 且未访问过 
	{
		travelDFS(i);		//DFS访问 
	}
}
void travelBFS(int v)
{
	int i, head = 0, tail = 1, tmp;	//队头，队尾，出列的元素 
	que[head] = v;	//入队 
	while (head <= tail)	//队列访问完毕 
	{
		tmp = que[head];	//出队 
		head++;			//出队
		if (visited[tmp])	continue;	//如果访问过 
		else
		{
			printf("%d ", tmp);		//打印出队元素 
			visited[tmp] = 1;			//已访问 
			for (i = 0; i<n; i++)
			if (weights[tmp][i] && !visited[i])	//如果矩阵元素为 1 且未访问过 
				que[tail++] = i;		//入队 
		}
	}
}
int main()
{
	int u, v, i, del;
	scanf("%d %d", &n, &m);
	for (i = 0; i<m; i++)
	{
		scanf("%d %d", &u, &v); //录入矩阵 
		weights[u][v] = 1;
		weights[v][u] = 1;
	}
	travelDFS(0); puts("");	//DFS

	memset(visited, 0, sizeof(visited));	//初始化不要忘了 
	travelBFS(0); puts("");	//BFS

	scanf("%d", &del);
	memset(visited, 0, sizeof(visited));	//初始化不要忘了
	visited[del] = 1;		//	要删除的元素设置为已访问 
	travelDFS(0); puts("");	//DFS

	memset(visited, 0, sizeof(visited)); memset(que, 0, sizeof(que));//********注意：队列初始化不要忘了
	visited[del] = 1;		//	要删除的元素设置为已访问 
	travelBFS(0); puts("");	//BFS
	return 0;
}

