#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct point{
	int qx;
	int qy;
	int zx;
	int zy;
}point[103],temp;
int arr[103];
int main()
{
	int n,i,j,k,len,max=0,x,y,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&point[i].qx,&point[i].qy,&point[i].zx,&point[i].zy);
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=i+1;j<n;j++)
		{
			if(point[j].qx<point[i].qx)
			{
				temp=point[j];
				point[j]=point[i];
				point[i]=temp;
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		len=1;
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(point[j].qx==point[k].zx&&point[j].qy==point[k].zy)
			{
				len++;
				k=j;
			}
		}
		if(len>max)
		{
			max=len;
			x=point[i].qx;
			y=point[i].qy;
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
}

