#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int arr[500][500];
int n,m;
int arrflag[500]={0};
int queue[500];
 
void dfs(int x){
	printf("%d ",x);
	arrflag[x]=1;
	int i;
	for(i=0;i<n;i++){
		if(arr[x][i]==1&&arrflag[i]==0){
			dfs(i);
		}
	}

}
void bfs(int x){
	int head=0,tail=1,i;
	queue[0]=x;
	while(head<tail){
		int a;
		a=queue[head++];
{
			printf("%d ",a);
			arrflag[a]=1;
			for(i=0;i<n;i++){
				if(arr[a][i]&&arrflag[i]==0){
					queue[tail++]=i;
					arrflag[i]=1;
				}
			}
		}
	}
	
}
int main(){int a,b;
	int i;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		arr[a][b]=1;
		arr[b][a]=1;
	}
	dfs(0);	printf("\n");
	for(i=0;i<500;i++){
		arrflag[i]=0;
	}
	bfs(0);	printf("\n");
	for(i=0;i<500;i++){
		arrflag[i]=0;
	}
	int temp;
	scanf("%d",&temp);
	arrflag[temp]=1;
	dfs(0);	printf("\n");
	for(i=0;i<500;i++){
		arrflag[i]=0;
	}	
	arrflag[temp]=1;
	bfs(0);	printf("\n");
	
	return 0;
}

