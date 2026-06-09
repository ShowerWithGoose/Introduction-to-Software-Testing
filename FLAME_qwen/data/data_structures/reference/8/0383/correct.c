#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int vertax[200];
int flag[200];
int edge[200][200];
int bq[200];
int real=-1;
int head=0;
/*typedef struct node{
	int no;
	struct node *nxt;
}node;
struct{
	int no;
	node *head;
}vertax[200];*/
void bfs(int vertax){
	bq[++real]=vertax;
	flag[vertax]=1;
	while(head<=real){
		int v=bq[head++];
		for(int i=0;i<200;i++)
			if(edge[v][i]&&!flag[i])
				{bq[++real]=i;flag[i]=1;}
	}
	for(int i=0;i<=real;i++){
		printf("%d ",bq[i]);
	}
}
void visit(int vertax){
	printf("%d ",vertax);
}
void dfs(int vertax){
	if(flag[vertax])return;
	visit(vertax);
	flag[vertax]=1;
	for(int i=0;i<200;i++)
		if(edge[vertax][i])
			dfs(i);
}
int main(){
	int a,b;
	while(1){
		scanf("%d",&a);
		if(~scanf("%d",&b)){
			vertax[a]=vertax[b]=1;
			edge[a][b]=edge[b][a]=1;
		}
		else	break;
	}
	
	dfs(0);
	putchar(10);
	memset(flag,0,200);
	bfs(0);
	putchar(10);
	memset(flag,0,200);
	memset(bq,0,200);
	real=-1;head=0;
	for(int i=0;i<200;i++)edge[a][i]=edge[i][a]=0;
	dfs(0);
	putchar(10);
	memset(flag,0,200);
	bfs(0);
	return 0;
}

