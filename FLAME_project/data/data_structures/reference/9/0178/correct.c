#include<stdio.h>
typedef struct L
{
	int x1,y1,x2,y2;
}line;
int cmp(const void* a,const void* b) 
{
	line *c=(line*)a,*d=(line*)b;
	if(c->x1>d->x1)	return 1;
	if(c->x2<d->x2)	return -1;
	return 0;
}
line l[100];
int n,ans=-1,ansi=0,b=0,c[100],d[100],i,j;
int main()
{
	memset(l,0,sizeof(l));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	qsort(l,n,sizeof(line),cmp);
	for(i=0;i<n;i++)
	{
		if(!c[i])
		{
			c[i]=++b;
			d[c[i]]++;
		}
		for(j=i+1;j<n;j++)
		{
			if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1)
			{
				c[j]=c[i];
				d[c[j]]++;
			}
		}
	}
	for(i=1;i<=b;i++)
		if(d[i]>ans)
		{
			ans=d[i];
			ansi=i;
		}
	printf("%d ",ans);
	for(i=0;i<n;i++)
	{
		if(c[i]==ansi)
		{
			printf("%d %d",l[i].x1,l[i].y1);
			break;
		}
	}
	return 0;
}

