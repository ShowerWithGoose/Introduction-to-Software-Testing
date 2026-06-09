#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int graph[1010][1010];
int mark[1010];
void init_mark();
void init_graph();
void edge(int s,int t);
void dfs(int start);//深度优先
void bfs(int start);//广度优先
int queue[1010];
int front,rear,count;
void init_queue();
int is_empty();
void enqueue(int temp);
int dequeue();

int n,m;//n:顶点个数 m:边数

int main() {
	scanf("%d %d",&n,&m);//输入顶点个数 边数
	int i,s,t;//s:起始点 t:终点
	init_graph();//初始化邻接矩阵
	for(i=0; i<m; i++) {
		scanf("%d%d",&s,&t);
		edge(s,t);//加边
	}
	int del;//要删除的结点
	scanf("%d",&del);
	init_mark();//初始化visit数组
	dfs(0);//从0开始进行dfs
	printf("\n");//换行
	bfs(0);//这里对visit数组的初始化包含在bfs函数中
	printf("\n");//换行
	for(i=0; i<n; i++) { //将要删除结点的临边标记为0即将边删掉
		graph[del][i]=0;
		graph[i][del]=0;
	}
	init_mark();
	dfs(0);
	printf("\n");
	bfs(0);
	return 0;
}

void init_graph() {
	memset(graph,0,sizeof(graph));
}
void edge(int s,int t) {
	graph[s][t]=1;
	graph[t][s]=1;
}
void init_mark() {
	memset(mark,0,sizeof(mark));
}
void dfs(int m) {
	printf("%d ",m);
	mark[m]=1;
	for(int i=0; i<n; i++) {
		if(graph[m][i]&&!mark[i]) {
			dfs(i);
		}
	}
}

void bfs(int m) {

	init_mark();
	init_queue();
	enqueue(m);
	while(!is_empty()) { 
		int temp=dequeue();
		printf("%d ",temp);
		for(int i=0; i<n; i++) { 
			if(!mark[i]&&graph[i][temp]==1) {
				enqueue(i);
			}
		}
	}
}

void init_queue() {
	for(int i=0; i<1010; i++) {
		queue[i]=-1;
	}
	front=0;
	rear=1009;
	count=0;
}

int is_empty() {
	return count==0;
}

void enqueue(int temp) {
	mark[temp]=1;
	rear=(rear+1)%1010;
	queue[rear]=temp;
	count++;
}

int dequeue() {
	int temp;
	temp=queue[front];
	count--;
	front=(front+1)%1010;
	return temp;
}

