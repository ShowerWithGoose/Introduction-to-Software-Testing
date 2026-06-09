#include<stdio.h>
#include<stdlib.h>
int graph[100][100];
int search[100];
int n,m,del,cnt=1;
void read(){
	scanf("%d%d",&n,&m);
	int i,u,v;
	for(i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		graph[u][v]=graph[v][u]=1; 
	}
	scanf("%d",&del);
} 
void dfs(int st){
	int j;
	for(j=1;j<n;++j){
		if(graph[st][j]==1&&search[j]==0){
			search[j]=1;
			if((++cnt)!=n) printf("%d ",j);
			else printf("%d\n",j);
			dfs(j);
		}
	}
	return ;
}
int que[1000],l=0,r=0,in[100];
void bfs(int st){
	int j;
	for(j=1;j<n;++j){
		if(graph[st][j]==1&&search[j]==0){
			if((++cnt)!=n) printf("%d ",j);
			else printf("%d\n",j);
			search[j]=1;
			if(in[j]==0){
				que[r]=j;
				r++;
				in[j]=1;
			} 	
		}
	}
	return ;
}
int main(){
	read();
	search[0]=1;
	printf("0 ");
	dfs(0);
	cnt=1;
	int i;
	for(i=1;i<n;++i) search[i]=0;
	printf("0 ");
	r++;in[0]=1;
	while(l!=r){
		bfs(que[l]);
		l++;
	}
	cnt=2;
	for(i=1;i<n;++i){
		search[i]=0;
		in[i]=0;
	} 
	l=0,r=0;
	for(i=0;i<n;++i) graph[i][del]=graph[del][i]=0;
	
	printf("0 ");
	dfs(0);
	cnt=2;
	for(i=1;i<n;++i) search[i]=0;
	printf("0 ");
	r++;in[0]=1;
	while(l!=r){
		bfs(que[l]);
		l++;
	}
    return 0;
}

