#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int xi;
	int zhi;
}a[100005],b[100005],d[100005];
int n1=0,n2=0,n=0;
int cmp(const void*s,const void*t)
{
	struct node*pt=(struct node*)(s),*ps=(struct node*)(t);
	return ((struct node*)pt)->zhi>((struct node*)ps)->zhi? -1:1;
}
int main()
{
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));
	memset(d,0,sizeof(d));
    char c;
	while(1)
	{
		n1++;
		scanf("%d%d",&a[n1].xi,&a[n1].zhi);
		c=getchar();
		if(c==' ')continue;
		else break;
	}
	while(1)
	{
		n2++;
		scanf("%d%d",&b[n2].xi,&b[n2].zhi);
		c=getchar();
		if(c==' ')continue;
		else break;
	}
	int i,j;
	for(i=1;i<=n1;i++)for(j=1;j<=n2;j++)
	{
		n++;d[n].zhi=a[i].zhi+b[j].zhi;d[n].xi=a[i].xi*b[j].xi;
	}
	qsort(d+1,n,sizeof(d[1]),cmp);
	for(i=1;i<=n;i++)
	{
		if(d[i].xi)
		{
			j=i+1;int ans=d[i].xi;
			while(j<=n&&d[j].zhi==d[i].zhi)
			{
				ans+=d[j].xi;d[j].xi=0;j++;
			}
			printf("%d %d ",ans,d[i].zhi);
		}
		else continue;
	}
	return 0;
} 

