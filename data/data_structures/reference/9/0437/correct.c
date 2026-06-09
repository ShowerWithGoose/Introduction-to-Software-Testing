#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int n,i,m[100],j,max,num,z,x,k;
struct stu{
	int x1;
	int y1;
	int x2;
	int y2;
};
struct stu a[100];


int cha(int k)
{
	for(j=0;j<n;j++)
	{
		if(j==k)
		{
			continue;
		}
		else if(a[k].x2==a[j].x1&&a[k].y2==a[j].y1)
		{
			return j;
		}
	}
	return -1;
}

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	for(i=0;i<n;i++)
	{
		z=i;
		while(k==0)
		{
			x=cha(z);
			if(x!=-1)
			{
				m[i]++;
				z=x;
			}
			else
			{
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(max<=m[i])
		{
			max=m[i];
			num=i;
		}
	}
	printf("%d %d %d",max+1,a[num].x1,a[num].y1);
}

