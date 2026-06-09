#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct node {
	long long zs;
	long long xs; 
}a[10000],b[10000],c[10000]; 
int cmp(const void *m,const void *n)
{
	struct node *p,*q;
	p=(struct node *)m;
	q=(struct node *)n;
	if (p->zs<q->zs) return 1;
	else return -1;
}
int main()
{
	int i,j;
	i=1;
	a[0].zs=2000000000;
	while (scanf("%lld%lld",&a[i].xs,&a[i].zs)!=EOF)
	{
		i++;
	}
	int bj=0;
	for (j=1;j<i;j++)
	{
		if (a[j].zs>=a[j-1].zs)
		{
			bj=j;
			break;
		}
	}
	int k=0;
	for (j=bj;j<i;j++)
	{
	 b[++k].xs=a[j].xs;
	 b[k].zs=a[j].zs;
	 a[j].zs=0;
	 a[j].xs=0;	
	}
	int s1=0,s2=0;
	s1=bj-1;
	s2=i-bj;
	k=0;
	for (i=1;i<=s1;i++)
      {
      	for (j=1;j<=s2;j++)
      	{
      		k++;
      		c[k].zs=a[i].zs+b[j].zs;
      		c[k].xs=a[i].xs*b[j].xs;
		  }
	  }
	 qsort(&c[1],k,sizeof(c[0]),cmp);
	 c[k+1].zs=-1;
	 for (i=1;i<=k;i++)
	 {
	 	if (c[i].zs!=c[i+1].zs)
	 	printf("%lld %lld ",c[i].xs,c[i].zs);
	 	else {
	 		c[i+1].xs+=c[i].xs;
		 }
	 }
	return 0;
}


