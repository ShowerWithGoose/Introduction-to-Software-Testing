#include<stdio.h>
#include<stdlib.h>
int visit[105];
int  G[105][105];
struct line{
	int index;
	struct line *next;
}*begin,*end;
int n;
void dfs(int i){
	int j;
	if(visit[i]!=1){
		printf("%d ",i);
		visit[i]=1;
		for(j=0;j<n;j++){
			if(G[i][j]==1&&visit[j]!=1)
				dfs(j);
		}
	}
	return;
}
void bfs(int i){
	struct line *p,*q;
	int j;	
	begin=(struct line*)malloc(sizeof(struct line));
	begin->index=0;
	begin->next=NULL;
	end=begin;
	for(p=begin;p!=NULL;p=p->next){
		i=p->index;
		if(visit[i]!=1){
			printf("%d ",i);
			visit[i]=1;
			for(j=0;j<n;j++){
				if(G[i][j]==1){
					q=(struct line*)malloc(sizeof(struct line));
					q->index=j;
					q->next=NULL;
					end->next=q;
					end=q;
				}
			}
		}
	}
	return;
}
int main(){
	int num,i,j,k,t;
	scanf("%d%d",&n,&num);
	for(k=0;k<num;k++){
		scanf("%d%d",&i,&j);
		G[i][j]=1;
		G[j][i]=1;
	}
	scanf("%d",&t);
	dfs(0);
	printf("\n");
	for(i=0;i<n;i++)
		visit[i]=0;
	bfs(0);
	printf("\n");
	for(i=0;i<n;i++){
		visit[i]=0;
		G[t][i]=0;
		G[i][t]=0;
	}
	dfs(0);
	printf("\n");
	for(i=0;i<n;i++)
		visit[i]=0;
	bfs(0);
	return 0;
}

