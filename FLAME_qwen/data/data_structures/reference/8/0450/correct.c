#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,m;
int map[110][110],book[110];

void DFS(int t);
void BFS(int t);
void getGraph(int m);

int main()
{
	int i,j;
	int delt;
	
	scanf("%d%d",&n,&m);
	getGraph(m);
	scanf("%d",&delt);
	
	DFS(0);
	putchar('\n');
	
	memset(book,0,sizeof(book));
	BFS(0);
	
	memset(book,0,sizeof(book));
	book[delt]=1;
	DFS(0);
	putchar('\n');
	
	memset(book,0,sizeof(book));
	book[delt]=1;
	BFS(0);
	
	
	return 0;
}
void getGraph(int m){
	int i,x,y;
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		map[x][y]=map[y][x]=1;
	}
}

void DFS(int t){
	printf("%d ",t);
	book[t]=1;
	int j;
	for(j=0;j<n;j++){
		if(map[t][j] && !book[j])
			DFS(j);	
	}	
}

void BFS(int t){
	int quene[110]={0};
	int head=0, tail=-1, tem;
	quene[++tail]=t;
	while(head<=tail){
		tem = quene[head++];
		if(!book[tem]){
			printf("%d ",tem);
			book[tem]=1;
			int i;
			for(i=0;i<n;i++){
				if(map[tem][i] && !book[i])
					quene[++tail]=i;
			}	
		}	
	}
	putchar('\n');
}

