#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 105

int Visited[MAX];
int weights[MAX][MAX];
void DFS(int v);
void BFS(int v);
int emptyQ();
void enQueue(int v);
int deQueue();
int q[MAX];
int num_v,num_e;
int rear=-1,front=0;
int main()
{
	int i,k,m,n;
	scanf("%d%d",&num_v,&num_e);
	for(i=0;i<num_e;i++){
		scanf("%d%d",&m,&n);
		weights[m][n]=1;
		weights[n][m]=1;
	}
	
	DFS(0);
	printf("\n");
	
	memset(Visited,0,sizeof(Visited));
	BFS(0);
	printf("\n");
	
	scanf("%d",&k);
	memset(Visited,0,sizeof(Visited));
	for(i=0;i<num_v;i++){
		weights[k][i]=0;
		weights[i][k]=0;
	}
	DFS(0);
	printf("\n");
	
	memset(Visited,0,sizeof(Visited));
	for(i=0;i<num_v;i++){
		weights[k][i]=0;
		weights[i][k]=0;
	}
	memset(q,0,sizeof(q));
	BFS(0);
	printf("\n");
	return 0;
}

void DFS(int v)
{
	int i;
	printf("%d ",v);
	Visited[v]=1;
	for(i=0;i<num_v;i++)
		if(weights[v][i]&&!Visited[i])
			DFS(i);
}
void BFS(int v)
{
	int i,t;
	enQueue(v);
	while(!emptyQ()){
		t=deQueue();
		if(Visited[t])	continue;
		else{
			printf("%d ",t);
			Visited[t]=1;
			for(i=0;i<num_v;i++)
				if(weights[t][i]&&!Visited[i])
					enQueue(i);
		}
	}
}
int emptyQ()
{
	return front>rear;
}
void enQueue(int v)
{
	q[++rear]=v;
}
int deQueue()
{
	return q[front++];
}

