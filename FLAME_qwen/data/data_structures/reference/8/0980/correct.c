#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

//typedef struct edge{
//	int adjvex;
//	int weight;
//	struct edge *next;
//}Elink;
//
//typedef struct ver{
//	int vertex;
//	Elink *link;
//}Vlink;
//Vlink G[1000];

int G[100][100]={};
int queue[1000]={};
int head=0,rear=-1,count=0;
//int V,E;
int visited[100]={};

void push(int num){
	queue[++rear]=num;
	count++;
}

int pop(){
	count--;
	return queue[head++];
}

void DFS(int node){
	printf("%d ",node);
	visited[node]=1;
	for(int i=0;i<100;i++){
		if(visited[i]==0&&G[node][i]!=0){
			DFS(i);
		}
	}
}

void BFS(int node){
	push(node);
	printf("%d ",node);
	visited[node]=1;
	while(count!=0){
		node=pop();
		for(int i=0;i<100;i++){
			if(visited[i]==0&&G[node][i]!=0){
				push(i);
				printf("%d ",i);
				visited[i]=1;
			}
		}
	}
}

int main()
{
	int n,e_num;
	scanf("%d%d",&n,&e_num);
	int u,v;
	for(int i=0;i<e_num;i++){
		scanf("%d%d",&u,&v);
		G[u][v]=G[v][u]=1;
	}
	int del_num;
	scanf("%d",&del_num);
	
	DFS(0);
	for(int i=0;i<100;i++){
		visited[i]=0;
	}
	printf("\n");
	BFS(0);
	for(int i=0;i<100;i++){
		visited[i]=0;
	}
	printf("\n");	
	for(int i=0;i<100;i++){
		G[del_num][i]=G[i][del_num]=0;
	}
	for(int i=0;i<100;i++){
		visited[i]=0;
	}	
	DFS(0);
	for(int i=0;i<100;i++){
		visited[i]=0;
	}
	printf("\n");
	BFS(0);	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

