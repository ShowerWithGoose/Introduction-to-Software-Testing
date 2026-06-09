#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
#define db double
#define pr printf
#define sf scanf
#define rt return
#define gcr getchar
#define pcr putchar
#define pi 3.14159265
#define sw switch
#define brk break
#define ctn continue
#define sc(x) scanf("%d",&x)
#define ef else if
#define slf(x) scanf("%lf",&x)
#define pf(x) printf("%d\n",x)
#define sl strlen
#define PR printf("\n");
#define For(n) for(int i=0;i<n;++i)
#define New(p) p=(node*)malloc(sizeof(node))
#define NewTree p=(tree*)malloc(sizeof(tree))
#define itn int
#define fsf fscanf
#define fpr fprintf
#define DDF printf("The Deep Dark Fantasy...\n");
#define INF 0x3f3f3f
#define cls(a) memset(a,0,sizeof(a))
//DFS-Matrix
int V, E;
int vis[300];
int G[500][500];

void DFS(int i) {
	printf("%d ", i);	//输出
	vis[i] = 1;		//已访问
	for (int j = 0; j < V; ++j)
		if (G[i][j] && !vis[j])	//可到达 且 未访问过
			DFS(j);		//DFS访问
}
//调用：DFS(0);//从0开始

//BFS_mateix
int que[300];
void BFS(int i) {
	int f = 0, r = -1;
	int t;
	que[++r] = i; //in
	while (f <= r) { //队列不空
		t = que[f++]; //取队首元素
		if (vis[t])
			ctn;//若访问过，不管他；
		//do
		pr("%d ", t);
		vis[t] = 1; //设置
		for (int j = 0; j < V; ++j)
			if (G[t][j] && !vis[j]) //连通+未被访问
				que[++r] = j; //全部入队待命
	}
}

//其他
void prt(int V) { //输入顶点个数
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			pr("%d ", G[i][j]);
		}
		PR
	}
}

int main() {
	sc(V), sc(E);
	int u, v;
	int del;
	for (int i = 0; i < E; ++i) {
		sf("%d %d", &u, &v);
		G[u][v] = 1;
		G[v][u] = 1; //无向图
	}
	sc(del);
	//prt(V);
	DFS(0);
	PR
	cls(vis);
	BFS(0);
	PR
	cls(vis);
	cls(que);
	vis[del] = 1; //lazy del...
	DFS(0);
	PR
	cls(vis);
	vis[del] = 1;
	BFS(0);
}
