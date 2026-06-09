#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,m,map[101][101],x,y,did[101],tmp[101];

void dfs(int now){
	for(int i=1;i<n;++i){
		if(!did[i]&&map[now][i])
		{
			printf("%d ",i);
			did[i]=1;
			dfs(i);
		}
	}
}

void bfs(int num){
	int T[101],k=0;
	memcpy(T,tmp,sizeof(T));
	for(int i=0;i<num;++i)
	{
		for(int j=1;j<n;++j){
			if(!did[j]&&map[T[i]][j]){
				tmp[k++]=j;
				did[j]=1;
				printf("%d ",j);
			}
		}
	}
	if(k)
	bfs(k);
	memcpy(tmp,T,sizeof(T));
}

int main(){
	scanf("%d %d",&n,&m);
	++m;
	while(--m){
		scanf("%d %d",&x,&y);
		map[x][y]=map[y][x]=1;
	}
	did[0]=1;
	printf("0 ");
	dfs(0);
	memset(did,0,sizeof(did));
	printf("\n0 ");
	bfs(1);
	scanf("%d",&x);
	memset(did,0,sizeof(did));
	did[x]=1;
	printf("\n0 ");
	dfs(0);
	memset(did,0,sizeof(did));
	did[x]=1;
	printf("\n0 ");
	bfs(1);
	return 0;
}
