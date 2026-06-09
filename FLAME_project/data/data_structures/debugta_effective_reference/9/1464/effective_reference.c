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
	int n,i,j,position,length,max=0,nx,ny,flag=0;
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
		length=1;
		position=i;
		for(j=i+1;j<n;j++)
		{
			if(point[j].qx==point[position].zx&&point[j].qy==point[position].zy)
			{
				length++;
				position=j;
			}
		}
		if(length>max)
		{
			max=length;
			nx=point[i].qx;
			ny=point[i].qy;
		}
	}
	printf("%d %d %d",max,nx,ny);
	return 0;
}

