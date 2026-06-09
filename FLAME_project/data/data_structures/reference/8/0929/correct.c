#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[110][110],temp[110],que[110];
void DFS(int x,int n)
{
	printf("%d ",x);
	temp[x]=1;
	int i;
	for(i=0;i<=n-1;i++){
		if(a[x][i])
		{
			if(temp[i]==0)
				DFS(i,n);
		}
	}
}
void BFS(int t,int n)
{
	que[1]=t;
	int front=1,end=1,i;
	while(front<=end)
	{
		int x=que[front];
		front++;
		if(temp[x])
			continue;
		printf("%d ",x);
		temp[x]=1;
		for(i=0;i<=n-1;i++){
			if(a[x][i])
			{
				if(temp[i]==0)
					que[++end]=i;
			}
		}
	}	
}
int main()
{
	int n,m,i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	DFS(0,n);
	printf("\n");
	memset(temp,0,sizeof(temp));
	BFS(0,n);
	printf("\n");
	memset(temp,0,sizeof(temp));
	int z;
	scanf("%d",&z);
	for(i=0;i<=n-1;i++){
		a[i][z]=0;
		a[z][i]=0;
	}
	DFS(0,n);
	printf("\n");
	memset(temp,0,sizeof(temp));
	BFS(0,n);
	printf("\n");	
	return 0;
} 



