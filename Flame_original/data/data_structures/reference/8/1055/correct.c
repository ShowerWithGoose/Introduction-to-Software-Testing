#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int g[300][300]={0};
int visited[300]={0};
int queue[200],head=0;rear=1;
int n,m;
int isempty(){
	return (head>rear);
}
void push(int x){
     queue[rear++]=x;
}
void pop(){
	isempty()?-1:queue[head++];
}
void visit(int x){
	printf("%d ",x);
}
void DFS(int v){

	int j;
	visit(v);
	visited[v]=1;
	for(j=0;j<n;j++){
		if(visited[j]==0&&g[v][j]!=0){
			DFS(j);
		} 
	}
}
void BFS(int v){
	int k;//当前顶点
	int u; 
queue[head]=v;

	while(head<=rear){
		k=queue[head++];
		if(visited[k]==1){
			continue;
		}
		else{
			visit(k);
			visited[k]=1;
			for(u=0;u<n;u++){
				if(visited[u]==0&&g[k][u]!=0){
					push(u);
				}
			}
		}
	}
}
int main()
{

int v,e;//v为顶点，e为边; 
int i;
scanf("%d %d",&n,&m);
for(i=0;i<m;i++){
	scanf("%d %d",&v,&e);
	g[v][e]=1;
	g[e][v]=1;
}
DFS(0);
printf("\n");
memset(visited,0,sizeof(visited));
BFS(0);
printf("\n");
memset(visited,0,sizeof(visited));
memset(queue,0,sizeof(queue)); 
int op;
scanf("%d",&op);
visited[op]=1;
DFS(0);
printf("\n");
memset(visited,0,sizeof(visited));
visited[op]=1;
head=0;
rear=1;
BFS(0);
printf("\n");
return 0;
}





