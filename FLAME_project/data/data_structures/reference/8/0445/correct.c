#include <stdio.h>
int graph[102][102]; 
int state[102];
int n, Edge, remov;
int FistNbr(int i) {
	for (int j = 0; j < n; j++) {
		if (graph[i][j] == 1) return j;
	}
	return -1;
}
int NextNbr(int i, int j) {
	for (int k = j + 1; k < n; k++) {
		if (graph[i][k] == 1) return k;
	}
	return -1;
}
void visit(int i) {
	printf("%d ", i);
	return;
}
void DFS(int i) {
	state[i] = 1;
	visit(i);
	for (int u = FistNbr(i); -1 < u; u = NextNbr(i, u)) {
		if(state[u] == 0) DFS(u);
	}
	return;
}
void BFS(int i) {
	int Queue[102];
	for (int j = 0; j < n; j++) Queue[j] = 0;
	int start = 0, end = 1;
	Queue[0] = i;
	state[i] = 1;
	while(start < end) {
		int s = Queue[start];
		visit(s);
		start++;
		for (int u = FistNbr(s); -1 < u; u = NextNbr(s, u)) {
			if (state[u] == 0) {
				Queue[end++] = u;
				state[u] = 1;
			}
		}
	}
	return;
}
void Creatgraph() {
	for (int i = 0; i < Edge; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	} 
	return;
}
void removNote() {
	for (int u = FistNbr(remov); -1 < u; u = NextNbr(remov, u)) {
		graph[remov][u] = graph[u][remov] = 0;
	}
	return;
}
void initalstate() {
	for (int i = 0; i < n; i++) {
		state[i] = 0;
	}
	return;
}
int main() {
	scanf("%d%d", &n, &Edge);
	Creatgraph();
	scanf("%d", &remov);
	DFS(0);
	printf("\n");
	initalstate();
	BFS(0);
	printf("\n");
	initalstate();
	removNote();
	DFS(0);
	printf("\n");
	initalstate();
	BFS(0);
	printf("\n");
	return 0; 
}

