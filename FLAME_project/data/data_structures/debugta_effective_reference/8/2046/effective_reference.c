#include<stdio.h>
#include<string.h>
int adjoin[200][200],visited[105]={0},quene[200];
int m,n;
void DFS(int k){
	int i;
	printf("%d ",k);
	visited[k]=1;
	for(i=0;i<m;i++)
		if (adjoin[k][i] && !visited[i])
			DFS(i);
}
void BFS(int k){
	int i,head=0,tail=1,d;
	quene[head]=k;
	while(head<=tail){
		d=quene[head];
		head++;
		if(visited[d]!=0)
            continue;
		else{
			printf("%d ",d);
			visited[d]=1;
			for(i=0;i<m;i++)
				if(adjoin[d][i] && !visited[i])
					quene[tail++]=i;
		}
	}
}
int main(){
	int j,k,i,d;
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&j,&k); //Â¼Èë¾ØÕó
		adjoin[j][k]=1;
		adjoin[k][j]=1;
	}
	DFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(0);
	printf("\n");
	scanf("%d",&d);
	memset(visited,0,sizeof(visited));
	visited[d]=1;
	memset(quene,0,sizeof(quene));


	DFS(0);
    printf("\n");
	memset(visited,0,sizeof(visited));
	visited[d]=1;
	BFS(0);
	printf("\n");
	return 0;
}

