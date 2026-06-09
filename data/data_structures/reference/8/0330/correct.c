#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int arr[105][105]={};
int i,j,k;
int visit[105];
int queue[1000];
int head=-1;
int rear=-1;
int first(int arr[105][105],int dot,int dnum)
{
	int flag=0;
	int j;
	for(j=0;j<dnum;j++)
		{
			if(arr[dot][j]==1)
			{
				flag=1;
				dot=j;
				break;
			}
		}
	if(flag==1)
	return dot;
	else
	return -1;
}
int next(int arr[105][105],int fdot,int ndot,int dnum)
{
	int flag=0;
	int j;
	int re;
	for(j=ndot+1;j<dnum;j++)
	{
		if(arr[fdot][j]==1)
		{
			flag=1;
			re=j;
			break;
		}
	}
	if(flag==1)
	return re;
	else
	return -1;
	
}
void dfs(int arr[105][105],int dot,int dnum)
{
	int re;
	printf("%d ",dot);
	visit[dot]=1;
	re=first(arr,dot,dnum);
	while(re!=-1)
	{
		if(visit[re]==0)
			dfs(arr,re,dnum);
		re=next(arr,dot,re,dnum);
	}
}
void push(int dot)
{
	queue[++rear]=dot;
}
int empty()
{
	if(head==rear)
	return 1;
	else
	return 0;
}
int pop()
{
	return queue[++head];
}
void bfs(int arr[105][105],int dot,int dnum)
{
	int temdot;
	int w;
	printf("%d ",dot);
	visit[dot]=1;
	push(dot);
	while(empty()!=1)
	{
		temdot=pop();
		w=first(arr,temdot,dnum);
		while(w!=-1)
		{
			if(visit[w]==0)
			{
				printf("%d ",w);
				push(w);
				visit[w]=1;
			}
			w=next(arr,temdot,w,dnum);
		}	
	}
}
int main()
{
	
	int dnum,lnum;
	int d1,d2;
	scanf("%d%d",&dnum,&lnum);
	for(i=0;i<lnum;i++)
	{
		scanf("%d%d",&d1,&d2);
		arr[d1][d2]=1;
		arr[d2][d1]=1;
	}
	scanf("%d",&d1);
	dfs(arr,0,dnum);
	for(j=0;j<dnum;j++)
	visit[j]=0;
	printf("\n");
	bfs(arr,0,dnum);
		for(j=0;j<dnum;j++)
		visit[j]=0;
		printf("\n");
	for(j=0;j<dnum;j++)
	{
		arr[d1][j]=0;
	}
	for(j=0;j<dnum;j++)
	{
		arr[j][d1]=0;
	}
		dfs(arr,0,dnum);
			for(j=0;j<dnum;j++)
			visit[j]=0;
			printf("\n");
		bfs(arr,0,dnum);
	
	
	
}

