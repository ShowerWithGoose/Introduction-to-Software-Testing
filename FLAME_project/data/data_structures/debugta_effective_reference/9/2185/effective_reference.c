#include<stdio.h>
#include<math.h>
#include<string.h>
struct xian {
	int a;
	int b;
	int c;
	int d;
};
struct xian a[101];
struct xian f;
int main()
{
	int n,m,j,i,e[101];
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
	scanf("%d %d %d %d",&a[j].a,&a[j].b,&a[j].c,&a[j].d);
	e[j]=1;
}
	for(j=0;j<n-1;j++)
	for(i=j+1;i<n;i++)
	{
		if(a[i].a<a[j].a)
		{
			f=a[i];
			a[i]=a[j];
			a[j]=f;
		}
	}
	for(j=0;j<n-1;j++)
	for(i=j+1;i<n;i++)
	{
		if(a[j].c==a[i].a&&a[j].d==a[i].b)
		{
			e[j]++;
			a[j].c=a[i].c;
			a[j].d=a[i].d;
		}
	}
	for(j=1;j<n;j++)
	if(e[j]>e[0])
	{
	e[0]=e[j];
	a[0]=a[j];
}
	printf("%d %d %d",e[0],a[0].a,a[0].b);
	return 0;
}



