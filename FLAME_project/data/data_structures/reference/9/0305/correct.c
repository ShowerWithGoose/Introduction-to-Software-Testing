#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define PI 3.14159265
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
struct line{
	int le_x;
	int le_y;
	int ri_x;
	int ri_y;
	int flag;
};
int cmp(const void *a,const void *b)
{
	struct line *c=(struct line*)a;
	struct line *d=(struct line*)b;
	if(c->le_x<d->le_x)
	return -1;
	return 1;
}
int comp(struct line a,struct line b)
{
	if(a.flag==0||b.flag==0)
	return -1;
	if(a.le_x==b.le_x&&a.le_y==b.le_y)	return 1;
	if(a.le_x==b.ri_x&&a.le_y==b.ri_y)	return 2;
	if(a.ri_x==b.le_x&&a.ri_y==b.le_y)	return 3;
	if(a.ri_x==b.ri_x&&a.ri_y==b.le_y)	return 4;
	return -1;
}
int main()
{
	struct line lle[1024];
	int num,i,j,max=0,max_x,max_y;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d%d%d%d",&lle[i].le_x,&lle[i].le_y,&lle[i].ri_x,&lle[i].ri_y);
		lle[i].flag=1;
	}
	qsort(lle,num,sizeof(lle[0]),cmp);
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			if(i==j)
			continue;
			else
			{
				switch(comp(lle[i],lle[j]))
				{
					case 3:{
						lle[i].ri_x=lle[j].ri_x;
						lle[i].ri_y=lle[j].ri_y;
						lle[i].flag+=lle[j].flag;
						lle[j].flag=0;
						break;
					}
				}
			}
		}
	}
	for(i=0;i<num;i++)
	{
		if(lle[i].flag>max)
		{
			max=lle[i].flag;
			max_x=lle[i].le_x;
			max_y=lle[i].le_y;
		}
	}
	printf("%d %d %d\n",max,max_x,max_y);
	return 0;
}

