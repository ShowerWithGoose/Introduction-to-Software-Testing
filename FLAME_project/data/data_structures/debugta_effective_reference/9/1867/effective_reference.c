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
struct line s[110];
int f(int i)
{
	for(int i=i; i<n; i++)
	{
		for(int j=1; j+i<n; j++)
		{
			if((s[i].v2x==s[i+j].v1x&&s[i].v2y==s[i+j].v1y)&&(s[i].v2x!=s[i+j+1].v1x||s[i].v2y!=s[i+j+1].v1y))
				return f(i+j)+1;
			else if(s[i].v2x==s[i+j].v1x&&s[i].v2y==s[i+j].v1y&&s[i].v2x==s[i+j+1].v1x&&s[i].v2y==s[i+j+1].v1y)
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
		scanf("%d%d%d%d",&s[i].v1x,&s[i].v1y,&s[i].v2x,&s[i].v2y);
	qsort(s,n,sizeof(s[1]),cmp);
	int maxlen=-1,max=0;
	for(int i=0; i<n; i++)
	{
		if(maxlen<f(i))
		{
			maxlen=f(i);
			max=i;
		}
	}
	printf("%d %d %d",++maxlen,s[max].v1x,s[max].v1y);
	return 0;
}

