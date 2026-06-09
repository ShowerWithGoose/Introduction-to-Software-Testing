#include<stdio.h>
#include<string.h> 
int mp[105][105], v, edge;
int vis[105];
void dfs(int point){
	int i;
	for(i = 0; i < v; i ++){
		if(mp[point][i] && vis[i] == 0){
			vis[i] = 1;
			printf("%d ",i);
			dfs(i);
		}
	}
}

void bfs(){
	int q[205],start=0,end = 0,i,point;
	q[end++] = 0;
	vis[0] = 1;
	while(start != end){
		point = q[start++];
		printf("%d ",point);
		for(i = 0;i < v; i ++){
			if(mp[point][i] && vis[i] == 0){
				vis[i] = 1;
				q[end++] = i;
			}
		}
	}
}

int main(void){
	int i,from,to,del_point;
	while(scanf("%d%d",&v,&edge) != EOF){
		for(i = 0; i <edge; i ++){
			scanf("%d%d",&from,&to);
			mp[from][to] = 1;
			mp[to][from] = 1;
		}
		printf("0 ");
		vis[0] = 1;
		dfs(0);
		printf("\n");
		memset(vis,0,sizeof(vis));
		bfs();
		printf("\n");
		scanf("%d",&del_point);
		for(i = 0; i < v; i ++){
			mp[del_point][i] = 0;
			mp[i][del_point] = 0;
		}
		memset(vis,0,sizeof(vis));
		printf("0 ");
		vis[0] = 1;
		dfs(0);
		printf("\n");
		memset(vis,0,sizeof(vis));
		bfs();
	}
	return 0;
}

