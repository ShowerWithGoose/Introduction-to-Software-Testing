#include<stdio.h>

#define INFINITY 32767

int matrix[100][100],visited[100];
int vex=-1,edge=-1,devex=-1;
int Queue[500],front=0,rear=-1;

void DFS();
void eDFS(int v);
void enQueue(int v);
int deQueue();
void BFS();
void eBFS(int v);


int main(){
	int i,j,vex1=-1,vex2=-1;
	
	scanf("%d%d",&vex,&edge);
	for(i=0;i<vex;i++){
		for(j=0;j<vex;j++){
			matrix[i][j]=INFINITY;
		}
	}
	for(i=0;i<edge;i++){
		scanf("%d%d",&vex1,&vex2);
		matrix[vex1][vex2]=matrix[vex2][vex1]=1;
	}
	
	DFS();
	BFS();
	
	scanf("%d",&devex);
	for(i=0;i<vex;i++){
		matrix[devex][i]=matrix[i][devex]=INFINITY;
	}
	
	DFS();
	BFS();
	
	return 1;
}

void DFS(){
	int i;
	
	visited[0]=1;
	printf("0 ");
	for(i=0;i<vex;i++){
		if(!visited[i] && i!=devex && matrix[0][i]==1){
			eDFS(i);
		}
	}
	for(i=0;i<vex;i++){
		visited[i]=0;
	}
	printf("\n");
}
void eDFS(int v){
	int i;
	
	visited[v]=1;
	printf("%d ",v);
	
	for(i=0;i<vex;i++){
		if(!visited[i] && matrix[v][i]==1){
			eDFS(i);
		}
	}
}
void enQueue(int v){
	Queue[++rear]=v;
}
int deQueue(){
	return Queue[front++];	
}
void BFS(){
	int i;
	
	printf("0 ");
	for(i=0;i<vex;i++){
		if(!visited[i] && i!=devex){
			visited[0]=1;
			eBFS(i);
		}
	}
	for(i=0;i<vex;i++){
		visited[i]=0;
	}
	printf("\n");
}
void eBFS(int v){
	int i,j;
	int v1;
	
	for(i=0;i<100;i++){
		Queue[i]=0;
	}
	enQueue(v);
	while(front<=rear){
		v1=deQueue();
		for(i=0;i<vex;i++){
			if(!visited[i] && matrix[v1][i]==1){
				enQueue(i);
				visited[i]=1;
				printf("%d ",i);
			}
		}
	}
}




