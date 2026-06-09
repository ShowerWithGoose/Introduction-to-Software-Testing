#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int e[105][105];
int close[105];
int n,m,del;
int flag=0;
void dfs(int num,int sum)
{
	int i;
	if(sum==n-1&&flag==0)
		return ;
	else if(sum==n-2&&flag)
		return ;
	for(i=0;i<n;i++)
	{
		if(i==del&&flag)
		{
			continue;
		}
		if(close[i]==0&&e[num][i]==1)
		{
			close[i]=1;
			printf("%d ",i);
			dfs(i,++sum);
		}
	}
	return ;
}
void bfs()
{
	int que[105];
	int head=0,last=0;
	que[last++]=0;
	close[0]=1;
	int i;
	while(head<last&&last<n)
	{
		int tem=que[head];
		for(i=0;i<n;i++)
		{
			if(i==del&&flag)
				continue;
			if(close[i]==0&&e[tem][i]==1)
			{
				que[last++]=i;
				close[i]=1;
			}
		}
		head++;
	}
	if(flag)
		for(i=0;i<n-1;i++)
			printf("%d ",que[i]);
	else
		for(i=0;i<n;i++)
			printf("%d ",que[i]);
	printf("\n");
	return ;
	
}

int main()
{
	scanf("%d%d",&n,&m);
	int i,j,k;
	for(k=0;k<m;k++)
	{
		scanf("%d%d",&i,&j);
		e[i][j]=1;
		e[j][i]=1;
	}
	scanf("%d",&del);
	close[0]=1;
	printf("0 ");
	dfs(0,0); 
	printf("\n");
	for(k=0;k<n;k++)
		close[k]=0;
	bfs();
	
	flag=1;
	for(k=0;k<n;k++)
		close[k]=0;
	close[0]=1;
	printf("0 ");
	dfs(0,0); 
	printf("\n");
	for(k=0;k<n;k++)
		close[k]=0;
	bfs();
	
	
	return 0;
}


