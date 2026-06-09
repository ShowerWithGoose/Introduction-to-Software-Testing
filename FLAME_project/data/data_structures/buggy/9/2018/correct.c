#include <stdio.h>
#include <stdlib.h>
struct message
{
	int sx,sy,ex,ey;
	int a;
}line[101];

int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].sx,&line[i].sy,&line[i].ex,&line[i].ey);
		line[i].a=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
			{
				continue;
			}
			if(line[i].ex==line[j].sx&&line[i].ey==line[j].sy)
			{
				line[i].a=j;
				break;
			}
		}
	}
	int number;
	int b=0;
	int numbermax,sxmax,symax,middle;
	for(i=0;i<n;i++)
	{
		middle=i;
		number=1;
		while(line[middle].a!=-1)
		{
			number++;
			middle=line[middle].a;
		}
		if(b==0)
		{
			numbermax=number;
			sxmax=line[i].sx;
			symax=line[i].sy;
			b=1;
		}
		else if(b==1)
		{
			if(number>numbermax)
			{
				numbermax=number;
				sxmax=line[i].sx;
				symax=line[i].sy;
			}
		}
	}
	printf("%d %d %d",numbermax,sxmax,symax);
	return 0;
}


