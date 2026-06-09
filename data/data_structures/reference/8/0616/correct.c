#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int biao[100][100];
int visit[100];
int m,n,x;
void shendu(int i){
	int j;
	printf("%d ",i);
	visit[i]=1;
	for(j=0;j<m;j++){
		if(biao[i][j]==1&&visit[j]==0){
			shendu(j);
		}
	}
}
void guangdu(int i){
	int j=0,dui[100],front=0,rear=0;
	dui[0]=0;visit[0]=1;
	while(front<=rear){
		printf("%d ",dui[front++]);
		for(j=0;j<m;j++){
			if(biao[dui[front-1]][j]==1&&visit[j]==0){
				dui[++rear]=j;visit[j]=1;
			}
		}
	}
	
}
int main(){
	int i,a,b;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		biao[a][b]=1;
		biao[b][a]=1;
	}
	shendu(0);
	for(i=0;i<100;i++){
		visit[i]=0;
	}
	printf("\n");
	guangdu(0);
	printf("\n");
	scanf("%d",&x);
	for(i=0;i<100;i++){
		visit[i]=0;
	}
	for(i=0;i<n;i++){
		biao[i][x]=0;
	}
	for(i=0;i<n;i++){
		biao[x][i]=0;
	}
	shendu(0);
	for(i=0;i<100;i++){
		visit[i]=0;
	}
	printf("\n");
	guangdu(0);
	return 0;
}

	
    

