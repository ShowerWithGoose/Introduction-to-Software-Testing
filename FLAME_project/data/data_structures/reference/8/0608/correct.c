#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[105][105],visited[105],queue[105];
void DFS (int v);
void BFS (int v);
int m,n;
int main()
{

int i,tp1,tp2;
scanf("%d%d",&m,&n);//m为顶点数,n为边数 
for (i=0;i<n;i++){
	scanf("%d%d",&tp1,&tp2);
	a[tp1][tp2]=1;
	a[tp2][tp1]=1;
}
DFS(0),printf("\n");
memset(visited,0,sizeof(visited));
BFS(0),printf("\n");
memset(visited,0,sizeof(visited));
scanf("%d",&tp1);
visited[tp1]=1;
DFS(0),printf("\n");
memset(visited,0,sizeof(visited));
visited[tp1]=1;
BFS(0),printf("\n");
memset(visited,0,sizeof(visited));
return 0;
}

void DFS (int v){
	int i;
	printf("%d ",v);
	visited[v]=1;
	for (i=0;i<m;i++){
		if (a[v][i]==1&&visited[i]==0)
		DFS(i);
	}
}

void BFS(int v){
    queue[0]=v;//先入个队
	int front=0,rear=0,count=1,i,tp;
	while (count>0){
	tp=queue[front++];
	count--;
	if (visited[tp]==0){
		printf("%d ",tp);
		visited[tp]=1;
	for (i=0;i<m;i++){
		if (a[tp][i]==1&&visited[i]==0){
			queue[++rear]=i;
			count++;
		}
	}
	}
}
}









