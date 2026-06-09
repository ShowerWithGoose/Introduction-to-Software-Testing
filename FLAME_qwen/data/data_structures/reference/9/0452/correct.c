#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}loc[105];
int main()
{
	int n,i,j,k,t,temp1,temp2,temp3,temp4;
	scanf("%d",&n);
	int sx=0,sy=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&loc[i].x1,&loc[i].y1,&loc[i].x2,&loc[i].y2);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(loc[i].x1>loc[j].x1)
			{
				temp1=loc[i].x1;
				loc[i].x1=loc[j].x1;
				loc[j].x1=temp1;
				temp2=loc[i].y1;
				loc[i].y1=loc[j].y1;
				loc[j].y1=temp2;
				temp3=loc[i].x2;
				loc[i].x2=loc[j].x2;
				loc[j].x2=temp3;
				temp4=loc[i].y2;
				loc[i].y2=loc[j].y2;
				loc[j].y2=temp4;
			}
		}
	}
	i=0;k=0;j=0;
	int max=0; 
	for(i=0;i<n;i++)
{ t=1;
	   k=i;
	for(j=i+1;j<n;j++)
	{   
	    if(loc[k].x2==loc[j].x1)
	    {
			if(loc[k].y2==loc[j].y1)
			{
				t++;
				k=j;
			}
		}
	}
	if(t>max)
	{
		max=t;
		sx=loc[i].x1;
		sy=loc[i].y1;
	}
	}
	printf("%d %d %d",max,sx,sy);
	return 0;
}

