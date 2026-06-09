#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int book[101], sum, n, e[101][101];
FILE *in; //定义一个指针变量
char infile[] = {"in.txt"};
int del;
int queue[10001],head,tail;
int cur;
void reading(){
//	if ((in = fopen(infile, "r")) == NULL) {
//		printf("无法打开此文件\n");
//		exit(0);
//	}
	//先初始化二维矩阵
	int m;//n个顶点，m条边
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)e[i][j] = 0;
			else e[i][j] = 99999999;
		}
	}
	//读入顶点之间的边
	int a, b; //为两个顶点的编号
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1; //无向图，对称矩阵
	}
	scanf("%d", &del);
}

void dfs(int cur) //cur是当前顶点所在的编号
{
	int i;
	printf("%d ", cur);
	sum++;//每访问过一个顶点，sum+1
	if (sum == n)return; //此时所有顶点都已经访问过了，则直接推出
	for (int i = 0; i < n; i++) {
		if (e[cur][i] == 1 && book[i] == 0) { //说明两点之间存在通路，把优先碰到的顶点标记，并dfs那个顶点
			book[i] = 1;
			dfs(i);
		}
	}
	return;
}

void print(){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(e[i][j]==99999999)printf("  ");
			else printf("%d ", e[i][j]);
		}
		printf("\n");
	}
}

void task1(){
	//从0号顶点出发
	book[0] = 1; //标记已经访问过0号顶点了
	//	print();
	dfs(0);//从0号顶点开始遍历，之后会输出深度遍历依次经过的顶点。
	printf("\n");
}

void task2(){
	for(int i=0;i<n;i++){
		book[i]=0;
	}
	head=1;tail=1;
	//从0号顶点出发，将0号顶点加入队列
	queue[tail]=0;
	tail++;
	book[0]=1;//标记已经入队
	while(head<tail&&tail<=n){
		cur=queue[head];
		for(int i=0;i<n;i++){
			if(e[cur][i]==1&&book[i]==0){
				queue[tail]=i;
				tail++;
				book[i]=1;
			}
			if(tail>n) break;
		}
		//当一个顶点考虑完之后给它出队
		head++;
	}
	for(int i=1;i<tail;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}
void task3(){
	for (int i = 0; i < n; i++) {
			if (i != del) {
				e[del][i] = 99999999;
				e[i][del] = 99999999;
			}
		}
	//	printf("\n");
	//	print();
		for(int i=1;i<n;i++){
			book[i]=0;
		}
		dfs(0);
		printf("\n");
}
void task4(){
	for(int i=0;i<n;i++){
		book[i]=0;
	}
	head=1;tail=1;
	//从0号顶点出发，将0号顶点加入队列
	queue[tail]=0;
	tail++;
	book[0]=1;//标记已经入队
	while(head<tail&&tail<=n){
		cur=queue[head];
		for(int i=0;i<n;i++){
			if(e[cur][i]==1&&book[i]==0){
				queue[tail]=i;
				tail++;
				book[i]=1;
			}
			if(tail>n) break;
		}
		//当一个顶点考虑完之后给它出队
		head++;
	}
	for(int i=1;i<tail;i++){
		printf("%d ",queue[i]);
	}
}
int main()
{
	reading();
	task1();
	task2();
	task3();
	task4();
	return 0;
}

