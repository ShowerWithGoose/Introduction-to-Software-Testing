#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>



int point[100][4];
void sort(int a[][4],int n);
int main()
{
	int n;
	int i,j,k;
	int cnt;//记录当前最长线段段数 
	int max=0;//最长线段段数 
	int x,y;//最长线段的起点坐标
	 
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&point[i][0],&point[i][1],&point[i][2],&point[i][3]);
	
	sort(point,n);
	
	for(i=0;i<n;i++)
	{
		k=i;
		cnt=1;
		for(j=i+1;j<n;j++)
		{
			if(point[k][3]==point[j][1]&&point[k][2]==point[j][0])//起点和终点重合 
			{
				cnt++;
				k=j;
			}
		}
		if(cnt>max)
		{
			max=cnt;
			x=point[i][0];
			y=point[i][1];
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
}
void sort(int a[100][4],int n)
{
	int i,j,k;
	int cache[4];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i][0]>a[j][0])
			{
				for(k=0;k<4;k++)
				{
					cache[k]=a[i][k];
					a[i][k]=a[j][k];
					a[j][k]=cache[k];
				}
				
			}
		}
	}
}

