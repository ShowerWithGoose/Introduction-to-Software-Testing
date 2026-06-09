#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
int x1[100000][2],x2[100000][2],y1[100000][2],y2[100000][2];
int main()
{
	int n, max=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1[i][0],&y1[i][0],&x2[i][0],&y2[i][0]);
	}
	for(int i=0;i<n;i++)
	{
		x1[i][1]=1;
		y1[i][1]=1;
		x2[i][1]=1;
		y2[i][1]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			else
			{
				if(x1[i][0]==x2[j][0]&&y1[i][0]==y2[j][0])
				{
					x2[j][0]=x2[i][0];
					y2[j][0]=y2[i][0];
					x1[j][1]=x1[j][1]+x1[i][1];
					x1[i][0]=-1000;
					y1[i][0]=-1000;
					x2[i][0]=-1000;
					y2[i][0]=-1000;
				}
				if(x2[i][0]==x2[j][0]&&y2[i][0]==y2[j][0])
				{
					x2[j][0]=x1[i][0];
					y2[j][0]=y1[i][0];
					x1[j][1]=x1[j][1]+x1[i][1];
					x1[i][0]=-1000;
					y1[i][0]=-1000;
					x2[i][0]=-1000;
					y2[i][0]=-1000;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(x1[i][0]!=-1000)
		{
			if(max<x1[i][1])
				max=x1[i][1];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(x1[i][1]==max)
		{
			printf("%d %d %d\n",max,x1[i][0],y1[i][0]);
			break;
		}
	}
	return 0;
}

