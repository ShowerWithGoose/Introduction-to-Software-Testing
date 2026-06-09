#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
#include <ctype.h> 
	int graph[110][110]={0};
	int visit[110]={0};
	int queue[110];
	int begin=0;
	int end=0;
void in(int a){
	queue[end]=a;
	end++;
}
int out(void){
	begin++;
	return queue[begin-1]; 
}
void dfs(int num,int a){
	int i;
	printf("%d ",a);
	visit[a]=1;
	for(i=0;i<num;i++){
		if(graph[a][i]!=0&&visit[i]!=1){
			dfs(num,i);
		}
	}
} 
void bfs(int num,int a){
	int i,tmp;
	in(a);
	while(begin<end){
		tmp=out();
		if(visit[tmp]==1)
		continue;
		else{
			printf("%d ",tmp);
			visit[tmp]=1;
			for(i=0;i<num;i++){
				if(graph[tmp][i]!=0&&visit[i]!=1){
					in(i);
				}
			}
		}
	}
}
int main(){
    int side,n,i;
	scanf("%d%d",&n,&side);

	int a,b,del;
	for(i=0;i<side;i++){
		scanf("%d%d",&a,&b);
		graph[a][b]=1;
		graph[b][a]=1;
	}
	scanf("%d",&del);
	dfs(n,0);
	printf("\n");
	for(i=0;i<n;i++){
		visit[i]=0;
	}
	bfs(n,0);

	printf("\n");
	for(i=0;i<n;i++){
		visit[i]=0;
	}
	

	
	visit[del]=1;
	dfs(n,0);
	printf("\n");
	for(i=0;i<n;i++){
		visit[i]=0;
	}
	visit[del]=1;
	bfs(n,0);
	printf("\n");

	return 0;
} 

