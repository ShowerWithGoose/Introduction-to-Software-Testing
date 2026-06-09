#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
typedef struct line
{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
}line[1000];
int cmp(const void *a,const void *b)
{
	struct line *c=(struct line *)a;
	struct line *d=(struct line *)b;
	 if(c->x1!=d->x1)
	 {
	 	return d->x1-c->x1;
	 }
	 else{
	 	return d->y1-c->y1;
	 }
}
int main()
{
	struct line line[1000];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].num=1;
	}
	qsort(line,n,sizeof(line[0]),cmp);
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(line[i].x1==line[j+1].x2&&line[i].y1==line[j+1].y2)
			{
				line[j+1].num+=line[i].num;
			}
		}
	}
	int numax=0;
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(line[i].num>numax)
		{
			numax=line[i].num;
			k=i;
		}
	}
	printf("%d %d %d\n",numax,line[k].x1,line[k].y1);
	return 0;
}

