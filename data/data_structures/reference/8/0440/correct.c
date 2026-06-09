#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int graph[101][101];

void insert(int spot1,int spot2){
	graph[spot1][spot2]=1;
	graph[spot2][spot1]=1;
	return ;
}
void read(int linenum){
	int i=0,j,k;
	for(i=0;i<linenum;++i){
		scanf("%d %d",&j,&k);
		insert(j,k);
	}
	return ;
}
void delete(int spot,int spotnum){
	int i=0;
	for(i=0;i<spotnum;++i){
		graph[spot][i]=0;
		graph[i][spot]=0;
	}
	return ;
}

//广度优先遍历
void BFS(int spotnum){
	int i,j,num=0;
	int queue[spotnum+1],visited[spotnum+1];
	memset(queue,0,sizeof(queue));
	memset(visited,0,sizeof(visited));
	queue[0]=0;
	visited[0]=1;
	for(i=0;i<spotnum;i++){
		if(queue[i]>0||i==0) printf("%d ",queue[i]); 
		for(j=0;j<spotnum;j++){
			if(graph[queue[i]][j]!=0&&visited[j]==0){
				queue[++num]=j;
				visited[j]=1;
			}
		}
	} 
	printf("\n");
}

//深度优先遍历
int did[101];
void DFS(int n,int spotnum){
	//表示在graph中从节点n开始进行深度优先排序; 
	int i;
	did[n]=1; 
	printf("%d ",n);
	for(i=0;i<spotnum;i++){
		if(graph[n][i]&&did[i]==0){
			DFS(i,spotnum);
		}
	}
	return ;
}

int main(){
	int spotnum,linenum,deletespot;
	scanf("%d %d",&spotnum,&linenum);
	read(linenum);
	scanf("%d",&deletespot);
	
	DFS(0,spotnum);
	printf("\n");
	BFS(spotnum);
	memset(did,0,sizeof(did));
	delete(deletespot,spotnum);
	DFS(0,spotnum);
	printf("\n");
	BFS(spotnum);
	memset(did,0,sizeof(did));
	return 0;
}

