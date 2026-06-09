#include<stdio.h>
int v[101];
int visit[101];
int biao[101][101];
int queue[101];
int inqueue[101];
int top;
int m,n;
void bianli1(int id);
void bianli2();
void bianli3();
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	v[i]=i;
	for(int i=0;i<n;i++)
	{
		int j,k;
		scanf("%d%d",&j,&k);
		biao[j][k]=1;
		biao[k][j]=1;
	}
	bianli1(0);
	printf("\n");
	for(int i=0;i<m;i++)
	visit[i]=0;
	bianli2();
	printf("\n");
	for(int i=0;i<m;i++)
	visit[i]=0;
	
	
	int del;
	scanf("%d",&del);
	for(int i=0;i<m;i++)
	{
		biao[i][del]=0;
		biao[del][i]=0;
	}
	bianli1(0);
	printf("\n");
	for(int i=0;i<top;i++)
	queue[i]=0;
	for(int i=0;i<top;i++)
	inqueue[i]=0;
	top=0;
	
	for(int i=0;i<m;i++)
	visit[i]=0;
	bianli3();
	printf("\n");
	return 0;
}
void bianli1(int id)
{
	printf("%d ",id);
	visit[id]=1;
	for(int i=0;i<m;i++)
	{
		if(biao[id][i]==1&&visit[i]==0)
		bianli1(i);
	}
}
void bianli2()
{
	queue[0]=0; top++;
	
	int i=0;
	while(i<m)
	{
		visit[queue[i]]=1;
		printf("%d ",queue[i]);
		
		for(int j=0;j<m;j++)
		{
			if(biao[queue[i]][j]==1&&visit[j]==0&&inqueue[j]==0)
			{
				queue[top++]=j;
				inqueue[j]=1;
			}
		}
		i++;
	}
}
void bianli3()
{
	queue[0]=0; top++;
	
	int i=0;
	while(i<m-1)
	{
		visit[queue[i]]=1;
		printf("%d ",queue[i]);
		
		for(int j=0;j<m;j++)
		{
			if(biao[queue[i]][j]==1&&visit[j]==0&&inqueue[j]==0)
			{
				queue[top++]=j;
				inqueue[j]=1;
			}
		}
		i++;
	}
}

