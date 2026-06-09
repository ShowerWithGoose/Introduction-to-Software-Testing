#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dxs
{
    int zs,xs;
} a[105],b[105],c[105];

int cmp(const void *p1, const void *p2){
	return *(int *)p2-*(int *)p1; 
}

int main()
{
    char q;
    int na=1,nb=1,i=0,j=0,m=0;
    for(i=0;;i++)
    {
    	scanf("%d%d%c",&a[i].xs,&a[i].zs,&q);
		na++;
		if(q=='\n')
			break;	
	} 
	for(i=0;;i++)
	{
		scanf("%d%d%c",&b[i].xs,&b[i].zs,&q);
		nb++;
		if(q=='\n')
			break;
	}
	qsort(a,na,sizeof(a[0]),cmp);
	qsort(b,nb,sizeof(b[0]),cmp);
	for(i=0;i<=na;i++)
	{
		for(j=0;j<=nb;j++)
		{
			c[m].xs=a[i].xs*b[j].xs;
			c[m].zs=a[i].zs+b[j].zs;
			m++;
		}
	}
	qsort(c,m,sizeof(c[0]),cmp);
	for(i=0;i<=m;i++)
	{
		if(c[i].zs==c[i+1].zs && c[i].zs!=0)
		{
			c[i+1].xs+=c[i].xs;
			c[i].xs=0;
		}
	}
	qsort(c,m,sizeof(c[0]),cmp);
	for(i=0;i<=m;i++)
	{
		if(c[i].xs==0)
			continue;
		else
		{
			printf("%d %d ",c[i].xs,c[i].zs);
		}
	}
    return 0;
}





