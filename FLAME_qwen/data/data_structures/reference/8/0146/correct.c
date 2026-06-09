#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int m,n;
int count=0;
int a[200][200];
int b[200];
int c[200];
void bfs(int k) //广度 
{
	int i,g,j;
	int flag=0;
	for(i=0;i<m;i++) {
		if(a[k][i]==1&&b[i]==1) 
		{
			c[count]=i;
			b[i]=0;
			
			for(j=0;j<m;j++) 
			{
				if(b[j]==1) 
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				{
					printf("%d ",i);
				}
			else 
			{
				printf("%d\n",i);

			}
			count++;
			flag=0;
		}
	}
	g=c[0];
	for(j=0;j<count;j++) 
	{
		c[j]=c[j+1];
	}
	flag=0;
	count--;
	//for(i=0;i<count;i++)
	//{
	//	printf("%d\n",c[i]);
	//}
	for(j=0;j<m;j++) 
	{
		if(b[j]==1) 
		{
			flag=1;
			break;
		}
	}
	if(flag==0) 
	{
		return;
	}
	bfs(g);
}

void dfs(int k) //深度 
{
	int i,j,flag=0;
	for(i=0;i<m;i++) {
		if(a[k][i]==1&&b[i]==1) 
		{
			flag=0;
			b[i]=0;
			for(j=0;j<m;j++) 
			{
				if(b[j]==1)flag=1;
			}
			if(flag==1)
			{
				printf("%d ",i);
			}
			else 
			{
				printf("%d\n",i);
			}
			dfs(i);
		}
	}
	return;
}

int main() 
{
	int i,j,k,x,y;
	scanf("%d %d\n",&m,&n);
	for(i=0;i<n;i++) 
	{
		scanf("%d %d\n",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	for(i=1;i<m;i++) 
	{
		b[i]=1;
	}

	scanf("%d",&k);
	printf("0 ");
	dfs(0);
	for(i=1;i<m;i++) 
	{
		b[i]=1;
	}
	printf("0 ");
	bfs(0);


	for(i=0;i<m;i++) 
	{
		a[i][k]=0;
		a[k][i]=0;
	}
	for(i=1;i<m;i++) 
	{
		b[i]=1;
	}
	b[k]=0;
	printf("0 ");
	dfs(0);
	for(i=1;i<m;i++) 
	{
		b[i]=1;
	}
	b[k]=0;
	printf("0 ");
	for(i=0;i<m;i++)
	{
		c[i]=0;
	}
	count=0;
	bfs(0);
	return 0;
}

