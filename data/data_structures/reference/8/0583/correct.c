#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 1010
int graph[max][max];
int visit[max];
int n,m;
int s,t;
void add(int s,int t);
void dfs(int s);
void bfs(int s);
int queue[max];
int f,r,c;
void inq(int tmp){
	visit[tmp] = 1;
	r = (r+1)%max;
	queue[r] = tmp;
	c++;
}
int outq(){
	int tmp;
	tmp = queue[f];
	c--;
	f = (f+1)%max;
	return tmp;
}
int main(){
	scanf("%d %d",&n,&m);
	memset(graph,0,sizeof(graph));
	memset(visit,0,sizeof(visit));
	int i = 0;
	while(i < m){
		scanf("%d%d",&s,&t);
		add(s,t);
		i++;
	}
	int del;
	scanf("%d",&del);
	dfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	bfs(0);
	printf("\n");
	i = 0;
	while(i < n){
		graph[del][i] = 0;
		graph[i][del] = 0;
		i++;
	}
	memset(visit,0,sizeof(visit));
	dfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	bfs(0);
	printf("\n");
	return 0;
}
void add(int s,int t){
	graph[s][t] = 1;
	graph[t][s] = 1;
}
void dfs(int s){
	printf("%d ",s);
	visit[s] = 1;
	int i = 0;
	for(i=0;i < n;i++){
		if(visit[i]==0&&graph[s][i]==1){
			dfs(i);
		}
	}
}
void bfs(int s){
	for(int i=0;i<max;i++){
        queue[i]=-1;
    }
    f=0;
    r=max-1;
    c=0;
    inq(s);
    while(c!=0){
    	int tmp = outq();
    	printf("%d ",tmp);
    	for(int i=0;i<n;i++){
    		if(visit[i]==0&&graph[i][tmp]==1){
    			inq(i);
			}
		}
	}
}

