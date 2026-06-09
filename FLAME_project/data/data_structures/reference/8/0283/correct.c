#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 100
#include<stdio.h>
void dfs(int G[MAX][MAX], int visit, int n);//图，当前访问顶点编号，顶点最大数目
void DFS(int G[MAX][MAX], int n);
void bfs(int vn);
void BFS(int vn, int visit);
int G[MAX][MAX]={0};//采用邻接矩阵
int visited[MAX] = { 0 };
int isv[MAX] = { 0 };
int queue[MAX] = { 0 };
int front = 0, rear = -1;
int main() {
	int vn, en;//顶点和边的个数
	scanf("%d %d", &vn, &en);
	int initial, end;
	for (int i = 0; i < en; i++) {
		scanf("%d %d", &initial, &end);
		isv[initial] = isv[end] = 1;//标记是结点
		G[initial][end] = G[end][initial] = 1;
	}
	int dele;
	scanf("%d", &dele);
	DFS(G, vn);
	printf("\n");
	bfs(vn);
	printf("\n");
	for (int i = 0; i < vn; i++) {
		G[dele][i] = 0;
		G[i][dele] = 0;
	}//删除对应的行和列
	isv[dele] = 0;
	DFS(G, vn);
	printf("\n");
	bfs(vn);
	return 0;
}
void dfs(int G[MAX][MAX], int visit, int n) {//图，当前访问顶点编号，顶点最大数目
	visited[visit] = 1;//访问过则标记
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {//如果还有没访问过的结点
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		printf("%d ", visit);
	}
	else {
		printf("%d ", visit);
	}
	for (int i = 0; i < n; i++) {
		if (G[visit][i]) {//是当前访问顶点的邻接点
			if (!visited[i]) {
				dfs(G, i, n);
			}
		}
	}
}
void DFS(int G[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}//初始化
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (isv[i]) {
				dfs(G, i, n);
			}
		}//找一个未被遍历过的结点,对其开始遍历
	}
}
void bfs(int vn) {
	for (int i = 0; i < vn; i++) {
		visited[i] = 0;
	}//初始化
	for (int i = 0; i < vn; i++) {
		if (!visited[i]) {
			if (isv[i]) {
				BFS(vn, i);
			}
		}
	}
}
void BFS(int vn, int visit) {
	int head;
	queue[++rear] = visit;
	while (front <= rear) {
		head = queue[front++];//取出队头元素
		if (!visited[head]) printf("%d ", head);
		else;
		visited[head] = 1;//访问过则标记
		for (int i = 0; i < vn; i++) {
			if (G[head][i]) {
				if (!visited[i]) {
					queue[++rear] = i;
				}
			}
		}
	}
}


