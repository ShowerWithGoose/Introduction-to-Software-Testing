#include <stdio.h>
#include<ctype.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h> 
void pai(int a[101][4],int n,int temp[4]);
int a[101][4],n,temp[4];

int main()
{
	scanf("%d",&n);
	int i=0,p=0,num=0,fx,fy,max=0;
	int w=0;
	for(;i<n;i++)
	{
		scanf(" %d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		
	}
	pai(a,n,temp);
	for(i=0;i<n;i++)
	{
		w=i;
		num=0;
		for(p=i+1;p<n;p++)
		{
			if(a[w][2]==a[p][0]&&a[w][3]==a[p][1])
			{
				num++;
				w=p;
			}
		}
		if(num>max)
		{
			max=num;
			fx=a[i][0];
			fy=a[i][1];
			
		}
	}
	printf("%d %d %d",max+1,fx,fy);
	return 0;
}

void pai(int a[101][4],int n,int temp[4])
{
	int y=0;
	int t=0;
	int u=0;
	for(y=0;y<n;y++)
	{
		for(t=y+1;t<n;t++)
		{
			if(a[y][0]>a[t][0])
			{
				for(u=0;u<4;u++)
				{
					temp[u]=a[y][u];
				}
				for(u=0;u<4;u++)
				{
					a[y][u]=a[t][u];
				}
				for(u=0;u<4;u++)
				{
					a[t][u]=temp[u];
				}
			}
		}
	}
}

