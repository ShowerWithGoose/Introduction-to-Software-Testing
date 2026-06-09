#include<stdio.h>
#include<math.h>
#include<string.h>
struct xian {
	int a;
	int b;
	int c;
	int d;
};
struct xian e[101];
struct xian f;
int main()
{
	int n,m,x,y,k[101];
	scanf("%d",&n);
	for(x=0;x<n;x++)
	{
	scanf("%d %d %d %d",&e[x].a,&e[x].b,&e[x].c,&e[x].d);
	k[x]=1;
}
	for(x=0;x<n-1;x++)
	for(y=x+1;y<n;y++)
	{
		if(e[y].a<e[x].a)
		{
			f=e[y];
			e[y]=e[x];
			e[x]=f;
		}
	}
	for(x=0;x<n-1;x++)
	for(y=x+1;y<n;y++)
	{
		if(e[x].c==e[y].a&&e[x].d==e[y].b)
		{
			k[x]++;
			e[x].c=e[y].c;
			e[x].d=e[y].d;
		}
	}
	for(x=1;x<n;x++)
	if(k[x]>k[0])
	{
	k[0]=k[x];
	e[0]=e[x];
}
	printf("%d %d %d",k[0],e[0].a,e[0].b);
	return 0;
}



