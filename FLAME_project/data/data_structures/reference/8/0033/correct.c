#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int nv,ne;
int v1,v2;
int g[200][200];
int mark[200];
void DFS(int nv,int g[200][200],int v){
	printf("%d ",v);
	mark[v]=1;
	int i,j=0,sa[200]={0};
	for(i=0;i<nv;i++){
		if(g[i][v]==1){
			sa[j]=i;
			j++;
		}
	}
	for(i=0;i<j;i++){
		if(mark[sa[i]]!=1){
			DFS(nv,g,sa[i]);
		}
	}
}
void BFS(int nv,int g[200][200],int v){
	int i,j,k;
	int queue[200]={0},front=-1,rear=-1;
	rear++;
	queue[rear]=v;
	while(front!=rear){
		printf("%d ",queue[front+1]);
		mark[queue[front+1]]=1;
		for(i=0;i<nv;i++){
			if(g[i][queue[front+1]]==1&&mark[i]==0){
				rear++;
				queue[rear]=i;
				mark[i]=1;
			}
		}
		front++;
	}
}
int main()
{
	scanf("%d%d",&nv,&ne);
	int i,j,k;
	for(i=0;i<ne;i++){
		scanf("%d%d",&v1,&v2);
		g[v1][v2]=g[v2][v1]=1;
	}
	int tar;
	scanf("%d",&tar);	
	DFS(nv,g,0);
	printf("\n"); 
	for(i=0;i<200;i++) mark[i]=0; 
	BFS(nv,g,0);
	printf("\n");
	for(i=0;i<200;i++) mark[i]=0; 
	mark[tar]=1;
	DFS(nv,g,0);
	printf("\n");
	for(i=0;i<200;i++) mark[i]=0; 	
	mark[tar]=1;
	BFS(nv,g,0);
}


