#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,line;
int map[110][110],visited[110];

void DFS(int i);
void BFS(int i);
void getGraph(int line);

int main()
{
	int i,k;
	int number;
	
	scanf("%d%d",&n,&line);
	getGraph(line);
	scanf("%d",&number);
	
	DFS(0);
	putchar('\n');
	
	memset(visited,0,sizeof(visited));
	BFS(0);
	
	memset(visited,0,sizeof(visited));
	visited[number]=1;
	DFS(0);
	putchar('\n');
	
	memset(visited,0,sizeof(visited));
	visited[number]=1;
	BFS(0);
	
	
	return 0;
}
void getGraph(int line){
	int i,x,y;
	for(i=0;i<line;i++){
		scanf("%d%d",&x,&y);
		map[x][y]=map[y][x]=1;
	}
}

void DFS(int i){
	printf("%d ",i);
	visited[i]=1;
	int k;
	for(k=0;k<n;k++){
		if(map[i][k] && !visited[k])
			DFS(k);	
	}	
}

void BFS(int i){
	int quene[110]={0};
	int head=0, tail=-1, tem;
	quene[++tail]=i;
	while(head<=tail){
		tem = quene[head++];
		if(!visited[tem]){
			printf("%d ",tem);
			visited[tem]=1;
			int i;
			for(i=0;i<n;i++){
				if(map[tem][i] && !visited[i])
					quene[++tail]=i;
			}	
		}	
	}
	putchar('\n');
}

