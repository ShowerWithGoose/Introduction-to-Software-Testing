#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct node{
	int x1,y1,x2,y2;
}line[105];
int cmp(const void *a0,const void *b0)
{
	struct node a=*((struct node*)a0);
	struct node b=*((struct node*)b0);
	if(a.x1<b.x1)
		return -1;
	else
		return 1;
}
int main()
{
	int n,i,j,k,length,max=1,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	qsort(line,n,sizeof(line[0]),cmp);
	for(i=0;i<n;i++)
	{
		length=1;
		k=i;
		for(j=i;j<n;j++)
		{
			if(line[k].x2==line[j].x1&&line[k].y2==line[j].y1)
			{
				length++;
				k=j;
			}
		}
		if(max<length)
		{
			max=length;
			x=line[i].x1;
			y=line[i].y1;
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
}

