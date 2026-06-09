#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct
{
	int x1,y1,x2,y2;
}node;
node a[110000];
int fa[110000];
int findfa(int x)
{
	if(fa[x]!=x) fa[x]=findfa(fa[x]);
	return fa[x];
}
int v[110000];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2),fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1||a[i].x1==a[j].x2&&a[i].y1==a[j].y2||a[i].x1==a[j].x1&&a[i].y1==a[j].y1||a[i].x2==a[j].x2&&a[i].y2==a[j].y2)
			{
				int fx=findfa(i),fy=findfa(j);
				if(fx!=fy) fa[fx]=fy;
			}
		}
	}
	memset(v,0,sizeof(v));
	int mmax=0,t;
	for(int i=1;i<=n;i++)
	{
		fa[i]=findfa(i);
		v[fa[i]]++;
		if(v[fa[i]]>mmax) mmax=v[fa[i]],t=fa[i];
	}
	int minx=-1;
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==t)
		{
			if(minx==-1||a[minx].x1>a[i].x1) minx=i;
		}
	}
	printf("%d %d %d\n",mmax,a[minx].x1,a[minx].y1);
	return 0;
}

