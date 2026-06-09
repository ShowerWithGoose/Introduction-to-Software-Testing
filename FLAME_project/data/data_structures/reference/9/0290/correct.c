#include<stdio.h>
#include<stdlib.h>
int n;
struct line
{
	int v1x;
	int v1y;
	int v2x;
	int v2y;
};
int maxof(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
struct line l[110];
int f(int k)
{
	for(int i=k; i<n; i++)
	{
		for(int j=1; j+i<n; j++)
		{
			if((l[i].v2x==l[i+j].v1x&&l[i].v2y==l[i+j].v1y)&&(l[i].v2x!=l[i+j+1].v1x||l[i].v2y!=l[i+j+1].v1y))
				return f(i+j)+1;
			else if(l[i].v2x==l[i+j].v1x&&l[i].v2y==l[i+j].v1y&&l[i].v2x==l[i+j+1].v1x&&l[i].v2y==l[i+j+1].v1y)
				return maxof(f(i+j)+1,f(i+j+1)+1);
		}
		return 0;
	}
}
int cmp(const void *a,const void *b)
{
	struct line *aa=(struct line *)a;
	struct line *bb=(struct line *)b;
	if( (*aa).v1x > (*bb).v1x )
		return 1;
	return -1;
}
int main()
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d%d%d%d",&l[i].v1x,&l[i].v1y,&l[i].v2x,&l[i].v2y);
	qsort(l,n,sizeof(l[1]),cmp);
	int maxlen=-1,max=0;
	for(int i=0; i<n; i++)
	{
		if(maxlen<f(i))
		{
			maxlen=f(i);
			max=i;
		}
	}
	printf("%d %d %d",++maxlen,l[max].v1x,l[max].v1y);
	return 0;
}

