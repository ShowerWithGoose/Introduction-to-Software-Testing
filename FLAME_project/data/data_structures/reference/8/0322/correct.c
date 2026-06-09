#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int linjie[200][200];//图的邻接矩阵
int visited[200]={0};//访问数组
int que[200]={0};//BFS用的访问队列 
void goDFS(int v);
void goBFS(int v);
void delpoint();
int n,m,del;	//顶点数 边数 要删的点
int main(){	
	int u,v,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&u,&v); //录入矩阵 
		linjie[u][v]=1;
		linjie[v][u]=1;
	}
	goDFS(0); puts("");
	memset(visited,0,sizeof(visited));
	goBFS(0); puts("");
	delpoint();
    goDFS(0); puts("");
	memset(visited,0,sizeof(visited));
    visited[del]=1;		//	要删除的元素设置为已访问 
    memset(que,0,sizeof(que));
	goBFS(0); puts("");
	return 0;
}
void goDFS(int v){
	int i;
	printf("%d ",v);	//输出 
	visited[v]=1;		//已访问 
	for(i=0; i<n; i++){
		if (linjie[v][i]==1 && visited[i]==0)//如果矩阵元素为 1 且未访问过 
			goDFS(i);		//DFS访问 
	}
}
void goBFS(int v){
	int i,head=0,tail=1,tmp;	//队头，队尾，出列的元素 
	que[head]=v;	//入队 
	while(head<=tail){ //队列访问完毕 
		tmp=que[head];	//出队 
		head++;			//出队
		if(visited[tmp]!=0)	
            continue;	//如果访问过 
		else{
			printf("%d ",tmp);		//打印出队元素 
			visited[tmp]=1;			//已访问 
			for(i=0;i<n;i++){
				if (linjie[tmp][i]==1 && visited[i]==0)	//如果矩阵元素为 1 且未访问过 
					que[tail++]=i;		//入队 
            }
		}
	}
}
void delpoint(){
    scanf("%d",&del);
	memset(visited,0,sizeof(visited));
	visited[del]=1;		//	要删除的元素设置为已访问 
}


