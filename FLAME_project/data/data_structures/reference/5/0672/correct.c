#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int n,p;
}node;
node a[1001001],b[1001001],c[1001001];
int n,m,q;
int cmp(const void *a,const void *b)
{
	node *c=(node *)a;
	node *d=(node *)b;
	return (c->p)<(d->p)?1:-1;
}
int main()
{
	int i,j;
	for(n=1;;n++)
	{
		scanf("%d%d",&a[n].n,&a[n].p);
		if(getchar()=='\n')break;
	}
	while(~scanf("%d",&b[++m].n))scanf("%d",&b[m].p);
	while(b[m].n==0)m--;
//	for(i=1;i<=n;i++)printf("%d %d\n",a[i].n,a[i].p);
//	for(i=1;i<=m;i++)printf("%d %d\n",b[i].n,b[i].p);puts("");
//	printf("%d %d\n\n",n,m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			c[++q].n=a[i].n*b[j].n;
			c[q].p=a[i].p+b[j].p;
		}
	qsort(c+1,q,sizeof c[0],cmp);
//	for(i=1;i<=n*m;i++)printf("%d %d\n",c[i].n,c[i].p);
	c[q+1].p=-1;
	for(i=1;i<=q;i++)
	{
		if(c[i].p!=c[i+1].p)printf("%d %d ",c[i].n,c[i].p);
		else c[i+1].n+=c[i].n;
	}
}

