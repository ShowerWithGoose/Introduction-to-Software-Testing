#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int picture[105][105]={0};
int visit[105]={0};
void dfs(int);
void bfs(int);
//void clean();
int point=0,edge=0;
int queue[105];
int m=0,n=0;
int main()
{
	int i,j,k,a,b,delet,begin=0;
	
	scanf("%d%d",&point,&edge);
	for(i=0;i<edge;i++)
	{
		scanf("%d%d",&a,&b);
		picture[a][b]=picture[b][a]=1;
	}
/*	for(i=0;i<point;i++)//打印矩阵 
	{
		for(j=0;j<point;j++)
		{
			printf("%d ",picture[i][j]);
		}
		printf("\n"); 
	}*/
	dfs(begin);
	printf("\n");
	for(i=0;i<point;i++)
	{
		visit[i]=0;
	}
	bfs(begin);
	printf("\n");
	scanf("%d",&delet);
	for(i=0;i<point;i++)//删除 
	{
		picture[i][delet]=picture[delet][i]=0;
	}
	for(i=0;i<point;i++)//清空已访问数组 
	{
		if(i==delet)
		{
			visit[i]=-1;
		}
		else
		{
			visit[i]=0;
		}
	}
	if(delet==0)
	{
		begin++;
	}
	dfs(begin);
	printf("\n");
	for(i=0;i<m;i++)
	{
		queue[i]=0;
	}
	m=n=0;
	for(i=0;i<point;i++)
	{
		visit[i]=0;
	}
	bfs(begin); 
	return 0;
}
void dfs(int t)
{
	int i=0,j=0,k=0;
	if(visit[t]==0)//未被访问过 
	{
		printf("%d ",t);
		visit[t]=1;
		for(i=0;i<point;i++)
		{
			if(picture[t][i]==1)
			{
				dfs(i);
			}
		}
		if(i==point)
		{
			return;
		}
	}
	else
	{
		return;
	}
	while(t<point)
	{
		t++;
		dfs(t);
	 } 
}
void bfs(int t)
{
	int i=0,j=0,k=0;
	if(visit[t]==0)
	{
		printf("%d ",t);
		visit[t]=1;
	}
		for(i=0;i<point;i++)
		{
			if(picture[t][i]==1&&visit[i]==0)
			{
				printf("%d ",i);
				visit[i]=1;
				queue[m]=i;
				m++;
			}
		}
		while(m!=n)
		{
			n++;
			bfs(queue[n-1]);
			
		}
		
	  
	 
}

