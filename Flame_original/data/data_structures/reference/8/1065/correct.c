#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int weight[100][100];
int visited[100]={0};
int team[100];//广度遍历队列
int n,m;
int x,y;

void DFS(int q){
	int i;
	printf("%d ",q);//输出顶点
	visited[q]=1;//顶点q已经访问
	for(i=0;i<n;i++){//遍历所有顶点
		if(weight[q][i]!=0&&visited[i]!=1){//点i与点q相连，且该点没有被访问过
			DFS(i);
		}
	}
}

void BFS(int q){
	int top=0,back=1;//队头与队尾
	int i;
	int cnt;
	team[top]=q;
	while(top<=back){
		cnt=team[top++];//出队列
		if(visited[cnt]==0){//如果没有被访问过
			printf("%d ",cnt);
			visited[cnt]=1;
			for(i=0;i<n;i++){
				if(weight[cnt][i]==1&&visited[i]==0){//与cnt相连，且没有访问过
					team[back++]=i;
				}
			}
		}
	}
}
int main(){
	int dele;//删除的结点
	int i;
	
	scanf("%d %d",&n,&m);//顶点个数，边数
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);//输入边，录入矩阵
		weight[x][y]=1;
		weight[y][x]=1;
	}
	scanf("%d",&dele);
	//先进行深度优先遍历输出，dfs
	DFS(0);
	printf("\n");
	
	//再进行广度优先遍历输出，bfs
	for(i=0;i<n;i++)
		visited[i]=0;
	BFS(0);
	printf("\n");
	
	//删除结点，深度遍历
	for(i=0;i<n;i++)
		visited[i]=0;
	visited[dele]=1;
	DFS(0);
	printf("\n");
	
	//删除结点，广度遍历
	for(i=0;i<n;i++)
		visited[i]=0;
	visited[dele]=1;
	BFS(0);
	printf("\n");
	
	return 0;
}

