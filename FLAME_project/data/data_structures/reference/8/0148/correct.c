#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

/*void swap(int *p,int *q)
{
	int mid;
	mid=*p;
	*p=*q;
	*q=mid;
}*/

int m,n,a[1005][1005]={0},flag=0,b[1005]={0},c[1005]={0};

void dfs(int x)
{
	int i;
	if(flag==0)
	{
		printf("%d",x);
		flag=1;
	}//输出第一个 
	else
	{
		printf(" %d",x);
	}
	b[x]=-1;
	for(i=1;i<=m;i++)
	{
		if(a[x][i]==1&&b[i]==0)//x,i之间有边，i没有被遍历过 
		{
			dfs(i);
		}
	}
}

void bfs(int y) 
{
	int i,j,k,l;
	c[1]=y;
	j=-1;k=0;
	while(j<k)
	{
		i=c[++j];
		if(b[i]==1)
		{
			continue;
		}
		if(flag==0)
		{
			printf("%d",i);
			flag=1;
		}
		else
		{
			printf(" %d",i);
		}
		b[i]=1;
		for(l=0;l<m;l++)
		{
			if(a[i][l]==1&&b[l]==0)
			{
				c[++k]=l;
				//bfs(l);
			}
		}
	}
}

int main()
{
	int i,p,q;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&p,&q);
		a[p][q]=1;
		a[q][p]=1;//标记 
	}
	dfs(0);
	printf("\n"); 
	for(i=0;i<m;i++)
	{
		b[i]=0;
	}
	flag=0;
	bfs(0);
	printf("\n"); 
	for(i=0;i<m;i++)
	{
		b[i]=0;
	}
	flag=0;
	scanf("%d",&p);
	b[p]=1;
	dfs(0);
	printf("\n"); 
	for(i=0;i<m;i++)
	{
		b[i]=0;
	}
	flag=0;
	b[p]=1;
	bfs(0);
	printf("\n"); 
	for(i=0;i<m;i++)
	{
		b[i]=0;
	}
	
	return 0;
}

