#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int side[1000][1000];
int used[1000];
int tou,wei=1,j;
int dui[1000];
int point,sides,i,i1,x,y;
void bfs() {
	tou=0;
	wei=1;
	dui[tou]=0;
	used[0]=1;
	while(tou!=wei) {
		for(j=0; j<point; j++) {
			if(side[dui[tou]][j]==1&&used[j]==0) {
				dui[wei]=j;
				wei++;
				used[j]=1;
			}
		}
		printf("%d ",dui[tou]);
		tou++;
	}
	memset(used,0,sizeof(used));
	memset(dui,0,sizeof(dui));
	printf("\n");
	return;
}
void dfs(int x) {
	int j1;//这里不能用全局变量j，要用新定义的变量j1； 
	used[0]=1;
	printf("%d ",x);
	used[x]=1;
	for(j1=0; j1<point; j1++) {
		if(side[x][j1]==1&&used[j1]==0) {


			dfs(j1);

		}
	}
	return;
}

int main() {
	int x1;

	scanf("%d %d",&point,&sides);
	for(i=0; i<sides; i++) {
		scanf("%d %d",&x,&y);
		side[x][y]=side[y][x]=1;

	}
	scanf("%d",&x1);

	dfs(0);
	printf("\n");
	memset(used,0,sizeof(used));
	bfs();
	used[x1]=1;

	dfs(0);
	printf("\n");
	memset(used,0,sizeof(used));
	used[x1]=1;
	bfs();

	/*	for(i=0;i<=point;i++)
		{for(i1=0;i1<=point;i1++)
		printf("%d",side[i][i1]);
		printf("\n");
		}*/
	return 0;
}


