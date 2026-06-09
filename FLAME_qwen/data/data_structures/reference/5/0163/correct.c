#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct poly
{
	long long num;
	long long index; 
};
struct poly poly1[100];
struct poly poly2[100];
struct poly polys[10000];
struct poly key[10000];
int compare(const void *p1,const void *p2)
{
	struct poly *a=(struct poly *)p1;
	struct poly *b=(struct poly *)p2;
	if(a->index<=b->index) return 1;
	else return -1;
}
int main()
{
	int i=0,j,k=0,n1,n2,n=0;
	char c;
	while(scanf("%lld%lld",&poly1[i].num,&poly1[i].index)!=EOF) 
	{
		i++;
		if((c=getchar())=='\n') break;
	}
	n1=i;
	i=0;
	while(scanf("%lld%lld",&poly2[i].num,&poly2[i].index)!=EOF) 
	{
		i++;
		if((c=getchar())=='\n') break;
	}
	n2=i;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++,k++)
		{
			polys[k].num=poly1[i].num*poly2[j].num;
			polys[k].index=poly1[i].index+poly2[j].index;
		}
	}
	qsort(polys,k,sizeof(polys[0]),compare);
	key[0].num=polys[0].num;
	key[0].index=polys[0].index;
	for(i=1;i<k;i++)
	{
		if(polys[i].index==key[n].index) 
		{
			key[n].num=key[n].num+polys[i].num;
		}
		else
		{
			n=n+1;
			key[n].num=polys[i].num;
			key[n].index=polys[i].index;
		}
	}
	for(i=0;i<=n;i++)
	{
		printf("%lld %lld ",key[i].num,key[i].index);
	}
	return 0;
} 


