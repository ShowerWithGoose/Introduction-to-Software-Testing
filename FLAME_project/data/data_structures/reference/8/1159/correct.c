#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int pnum,lnum,dnum,i,j,a[105][105],x,y,visit[105],quene[105],head,end;
void DFS(int i);
void BFS();
int main()
{
	scanf("%d %d",&pnum,&lnum); 
	for(i=0;i<lnum;i++){
		scanf("%d %d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	scanf("%d",&dnum);
	DFS(0);
	printf("\n"); 
	for(i=0;i<pnum;i++){
		visit[i]=0;
	}
	
	quene[1]=0;
	head=1;
	end=1;
	BFS();	
	printf("\n"); 
	for(i=0;i<pnum;i++){
		visit[i]=0;
		quene[i]=0;
	}
	
	visit[dnum]=1;
	DFS(0);
	printf("\n"); 
	for(i=0;i<pnum;i++){
		visit[i]=0;
	}
	
	quene[1]=0;
	head=1;
	end=1;
	visit[dnum]=1;
	BFS();
	printf("\n"); 
	for(i=0;i<pnum;i++){
		visit[i]=0;
		quene[i]=0;
	}
return 0;
}

void DFS(int i){
	printf("%d ",i);
	visit[i]=1;
	for(int j=0;j<pnum;j++){
		if(a[i][j]==1&&visit[j]==0){
			DFS(j);
		}
	}
}

void BFS() {
	int now;
	while(head<=end) {
		visit[0]=1;
		now=quene[head];
		printf("%d ",now);
		head++;
		for(int j=0; j<pnum; j++) {
			if(a[now][j]==1&&visit[j]==0) {
				visit[j]=1;
				end++;
				quene[end]=j;
			}
		}
	}
}


