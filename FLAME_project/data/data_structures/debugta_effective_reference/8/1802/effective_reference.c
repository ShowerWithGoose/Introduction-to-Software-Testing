#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define L(type) memset((type*)malloc(sizeof(type)),0,sizeof(type))
int main(){
	int graph[100][100]={{0}};
	int visit[100]={};
	int stc[100]={};
	int graph_del[100]={};
	int point=0;
	int vet,line;
	scanf("%d %d",&vet,&line);
	int i,j,k;
	for(i=0;i<line;i++){
		scanf("%d %d",&j,&k);
		graph[j][k]=1;
		graph[k][j]=1;
	}
	int type;
	scanf("%d",&type);
	int finger;
	for(i=0,finger=0;finger<vet;){
		if(visit[i]!=1){
			visit[i]=1;
			printf("%d ",i);
			finger++;
		}
		for(j=0;;j++){
			if(j==vet){
				point--;
				i=stc[point];
				break;
			}
			if(graph[i][j]==1&&visit[j]==0){
				stc[point]=i;
				point++;
				i=j;
				break;
			}
		}
	}
	printf("\n");
	memset(visit,0,sizeof(int)*100);
	int head,tail1,tail2;
	head=0;
	tail1=1;
	tail2=1;
	visit[0]=1;
	for(graph_del[0]=0,finger=0;finger<vet;){
		while(head!=tail1){
			printf("%d ",graph_del[head]);
			finger++;
			for(i=graph_del[head],j=0;j<vet;j++){
				if(graph[i][j]==1&&visit[j]==0){
					graph_del[tail2]=j;
					visit[j]=1;
					tail2++;
				}
			}
			head++;
		}
		tail1=tail2;
	}
	printf("\n");
	for(i=0;i<vet;i++){
		graph[type][i]=0;
		graph[i][type]=0;
	}
	memset(visit,0,sizeof(int)*100);
	for(i=0,finger=0;finger<vet-1;){
		if(visit[i]!=1){
			visit[i]=1;
			printf("%d ",i);
			finger++;
		}
		for(j=0;;j++){
			if(j==vet){
				point--;
				i=stc[point];
				break;
			}
			if(graph[i][j]==1&&visit[j]==0){
				stc[point]=i;
				point++;
				i=j;
				break;
			}
		}
	}
	printf("\n");
	memset(visit,0,sizeof(int)*100);
	head=0;
	tail1=1;
	tail2=1;
	visit[0]=1;
	for(graph_del[0]=0,finger=0;finger<vet-1;){
		while(head!=tail1){
			printf("%d ",graph_del[head]);
			finger++;
			for(i=graph_del[head],j=0;j<vet;j++){
				if(graph[i][j]==1&&visit[j]==0){
					graph_del[tail2]=j;
					visit[j]=1;
					tail2++;
				}
			}
			head++;
		}
		tail1=tail2;
	}
	printf("\n");
}

