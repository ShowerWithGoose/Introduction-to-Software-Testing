#include<stdio.h>

int n;
int ecnt[110];
struct line{
	int x1,x2,y1,y2;
}e[110];

int sou(int x)
{
	if(ecnt[x])return ecnt[x];
	int i;
	for(i=1;i<=n;i++)//搜x的下一个点 
		if(e[x].x2==e[i].x1&&e[x].y2==e[i].y1)
			return ecnt[x]=sou(i)+1;
	return 0;
}

int main()
{
	int i,ans=0,ansx,ansy;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d",&e[i].x1,&e[i].y1,&e[i].x2,&e[i].y2);
	for(i=1;i<=n;i++)
		ecnt[i]=sou(i);
	for(i=1;i<=n;i++)
	{
		if(ecnt[i]>ans)
		{
			ans=ecnt[i];
			ansx=e[i].x1;
			ansy=e[i].y1;
		}
	}
	printf("%d %d %d",ans+1,ansx,ansy);
	return 0;
}

