#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define max 1000
int d_num,b_num,i,queue[max]; 
int s,t,d;
int front,rear,count;
int visited[max]={0};
int visited1[max]={0},visited2[max]={0},visited3[max]={0};
int graph[max][max]={0};
void DFS(int v[],int a){
	int j=0;
	printf("%d ",a);
	v[a]=1;
	for(j=0;j<d_num;j++){
		if(!v[j]&&graph[a][j]!=0)
		DFS(v,j);
	}
}
void _queue(){
	int j;
	for(j=0;j<max;j++){
		queue[j]=-1;
	}
	front=0;
	rear=max-1;
	count=0;
}
int empty(){
	return count==0;
}
void enqueue(int v[],int temp){
	v[temp]=1;
	rear=(rear+1)%max;
	queue[rear]=temp;
	count++;
}
int dequeue(){
	int temp;
	temp=queue[front];
	count--;
	front=(front+1)%max;
	return temp;
}
void BFS(int v[],int a){
	int j;
	_queue();
	enqueue(v,a);
	while(!empty()){
		int temp=dequeue();
		printf("%d ",temp);
		for(j=0;j<d_num;j++){
			if(!v[j]&&graph[j][temp]==1)
			enqueue(v,j);
		}
	}
}
int main()
{
	scanf("%d %d",&d_num,&b_num);
	for(i=0;i<b_num;i++){
		scanf("%d%d",&s,&t);
		graph[s][t]=1;
		graph[t][s]=1;
	}
	scanf("%d",&d);
	DFS(visited,0);
	printf("\n");
	BFS(visited1,0);
	for(i=0;i<d_num;i++){
		graph[d][i]=0;
		graph[i][d]=0;
	}
	printf("\n");
	DFS(visited2,0);
	printf("\n");
	BFS(visited3,0);
 	return 0;
}


