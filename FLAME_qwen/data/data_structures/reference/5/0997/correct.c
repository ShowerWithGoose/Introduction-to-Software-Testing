#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct pan{
int xs;
int zs;
}a[10005],b[10005],c[1000005],d[1000005];
int cmp(const void *p1,const void *p2)
{
	struct pan *m=(struct pan*)p1;
	struct pan *n=(struct pan*)p2;
	if(m->zs<n->zs)
	return 1;
	else
	return -1;
}
int main()
{
	char ch,s[1000005];
	int an=0,bn=0,k=0,n=0,i,j;
	do
	{
		scanf("%d%d%c",&a[an].xs,&a[an].zs,&ch);
		an++;
	}
	while(ch!='\n');
	do
	{
		scanf("%d %d%c",&b[bn].xs,&b[bn].zs,&ch);
		bn++;
	}
	while(ch!='\n');
	for(i=0;i<an;i++)
	{
		for(j=0;j<bn;j++)
		{
			c[k].xs=a[i].xs*b[j].xs;
			c[k].zs=a[i].zs+b[j].zs;
			k++;
		}
	}
	qsort(c,k,sizeof(c[0]),cmp);
	for(i=0;i<k;i++)
	{
		if((i!=k-1)&&(c[i].zs==c[i+1].zs))
		c[i+1].xs+=c[i].xs;
		else
		{
			d[n].xs=c[i].xs;
			d[n].zs=c[i].zs;
			n++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(d[i].xs)
		printf("%d %d ",d[i].xs,d[i].zs);
	}
	
	
}

