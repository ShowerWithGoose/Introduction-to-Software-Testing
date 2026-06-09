#include<stdio.h>
#include<string.h>
void dfs(int a);
void bfs(int a);
int n,m;
int Matrixz[200][200],visited[200]={0},que[200]={0};
int main()
{	
	int i;
	int zero;
	int x,y;
	scanf("%d %d",&n,&m);
	for(i = 1;i <= m;i++){
      scanf("%d %d",&x,&y);
	  Matrixz[x][y] = 1;
	  Matrixz[y][x] = 1;
	}
	
dfs(0);
printf("\n");
for(i = 0;i <= m;i++)visited[i] = 0;
bfs(0);
printf("\n");
for(i = 0;i <= m;i++)visited[i] = 0;
scanf("%d",&zero);
visited[zero] = 1;
dfs(0),printf("\n");
for(i = 0;i <= m;i++)visited[i] = 0;
visited[zero] = 1;
memset(que,0,sizeof(que));
bfs(0);
	return 0;
}
void dfs(int a){
int i;
printf("%d ",a);
visited[a] = 1;
for(i = 0;i < n;i++ ){
if(Matrixz[a][i] == 1&&visited[i] == 0){
	dfs(i);
    }
  }
}
void bfs(int a){
int front = 0,rear = 1;
int i = 0,j,temp;
int out[200] = {0};
que[front] = a;
while(front <= rear){
temp = que[front];
front++;
if(visited[temp] == 1){
	continue;
}else{
	out[i++] = temp;
	visited[temp] = 1;
	for(j = 0;j < n;j++){
		if(Matrixz[temp][j] && !visited[j]){
			que[rear++] = j;
		}
	}
}
}


for(j = 0;j < i;j++){
	printf("%d ",out[j]);
}
}
/*
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3
*/


