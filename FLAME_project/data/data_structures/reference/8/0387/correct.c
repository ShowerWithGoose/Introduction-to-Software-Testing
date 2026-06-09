#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
#define LL long long
#define MaxVertexNum 100/* 最大顶点数设为100 */

typedef int Vertex;/* 用顶点下标表示顶点,为整型 */
typedef int WeightType;/* 边的权值设为整型 */
typedef char DataType;/* 顶点存储的数据类型设为字符型 */
int G[111][111];
int Nv,Ne;
int visited[1111]= {0};
void  DFS(int v,int n) {
	int i;
	printf("%d ",v);	//输出
	visited[v]=1;		//已访问
	for(i = 0; i < n; i++)
		if (G[v][i] && !visited[i]) {	//如果矩阵元素为 1 且未访问过
			DFS(i,n);		//DFS访问
		}
}
int que[222];
void  BFS(int v,int n) {
	int i,head=0,tail=1,tmp;	//队头，队尾，出列的元素
	que[head]=v;	//入队
	while(head<=tail) {	//队列访问完毕
		tmp=que[head];	//出队
		head++;			//出队
		if(visited[tmp])	continue;	//如果访问过
		else {
			printf("%d ",tmp);		//打印出队元素
			visited[tmp]=1;			//已访问
			for(i=0; i<n; i++)
				if (G[tmp][i] && !visited[i])	//如果矩阵元素为 1 且未访问过
					que[tail++]=i;		//入队
		}
	}
}
int main() {
	int i=0,n=0,j;
	int V1,V2;
	scanf("%d %d",&Nv,&Ne);
	for(i=0; i<Nv; i++) {
		for(j=0; j<Nv; j++) {
			G[i][j]=0;
		}
	}
	for(i=0; i<Ne; i++) {
		scanf("%d %d",&V1,&V2);
		G[V1][V2]=1;
		G[V2][V1]=1;
	}
	scanf("%d",&n);
//	for(i=0; i<Nv; i++) {
//		for(j=0; j<Nv; j++) {
//			printf("%d ",G[i][j]);
//		}
//	}
	DFS(0,Ne);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(0,Ne);
	puts("");
	memset(visited,0,sizeof(visited));
	memset(que,0,sizeof(que));
	visited[n]=1;
	DFS(0,Ne);
	puts("");
	memset(visited,0,sizeof(visited));
	visited[n]=1;
	BFS(0,Ne);
	return 0;
}


