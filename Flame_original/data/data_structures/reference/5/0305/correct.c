#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define PI 3.14159265
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
struct shu{
	ll a;
	ll x;
	int flag;
};
int cmp(const void *a,const void *b)
{
	struct shu *c=(struct shu*)a;
	struct shu *d=(struct shu*)b;
	if(c->x<d->x)
	return 1;
	return -1;
}
int main()
{
	ll i,j,k=0,m1,m2;
	char c;
	struct shu a1[10024];
	struct shu a2[10024];
	struct shu xx[10024];
	for(i=0;;i++)
	{
		scanf("%lld",&a1[i].a);
		scanf("%lld",&a1[i].x);
		scanf("%c",&c);
		if(c=='\n') 
		break;
	}
	m1=i;
	for(j=0;;j++)
	{
		scanf("%lld",&a2[j].a);
		scanf("%lld",&a2[j].x);
		scanf("%c",&c);
		if(c=='\n') 
		break;
	}
	m2=j;
	for(i=0;i<=m1;i++)
	{
		for(j=0;j<=m2;j++,k++)
		{
			xx[k].a=a1[i].a*a2[j].a;
			xx[k].x=a1[i].x+a2[j].x;
		}
	}
	qsort(xx,k,sizeof(xx[0]),cmp);
	for(i=0;i<k;i++)
	{
		j=1;
		while(xx[i].x==xx[i+j].x)
		{
			xx[i].a+=xx[i+j].a;
			xx[i+j].flag=1;
			j++;
		}
	}
	for(i=0;i<k;i++)
	{
		if(xx[i].flag==0&&xx[i].a!=0)
		printf("%lld %lld ",xx[i].a,xx[i].x);
	}
	return 0;
}

