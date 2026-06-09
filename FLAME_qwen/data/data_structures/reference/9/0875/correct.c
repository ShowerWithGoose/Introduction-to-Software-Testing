#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct lines 
{
	int x1;
	int y1;
	int x2;
	int y2;
	int count;
	int flag;
} line[105];
int cmp( const void *a , const void *b ) 
{ 
struct lines *c = (struct lines *)a; 
struct lines *d = (struct lines *)b; 
 return c->x1 - d->x1; 
} 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].count=1;
		line[i].flag=1;
	}
	qsort(&line[1],n,sizeof(line[1]),cmp);
	for(int i=1;i<=n;i++)
	{
		if(line[i].flag==0)continue;
		for(int j=i+1;j<=n;j++)
		{
			if(line[j].flag==0)continue;
			if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1)
			{
				line[i].x2=line[j].x2;
				line[i].y2=line[j].y2;
				line[j].flag=0;
				line[i].count++;
			}
		}
	}
	int z=1,max=1;
	for(z=1;z<=n;z++)
	{
		if(line[z].count>=line[max].count)max=z;
	}
	printf("%d %d %d",line[max].count,line[max].x1,line[max].y1);
	return 0;
}

