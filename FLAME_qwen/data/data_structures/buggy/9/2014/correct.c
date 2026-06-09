#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef long long ll;
struct Line{
	int sx,sy,tx,ty;
	struct Line *nxt;
}*a[110];
struct Ans{
	int l,x,y;
}ans;
int n;
void connect(struct Line *p,struct Line *q)
{
	p->nxt=q;
}
int trace(struct Line *m)
{
	int cnt=1;
	struct Line *p=m;
	while(p->nxt!=NULL)
	{
		cnt++;
		p=p->nxt;
	}
	return cnt;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a[i]=(struct Line *)malloc(sizeof(struct Line));
		scanf("%d%d%d%d",&a[i]->sx,&a[i]->sy,&a[i]->tx,&a[i]->ty);
	}
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			if(a[i]->tx==a[j]->sx&&a[i]->ty==a[j]->sy)
				connect(a[i],a[j]);
			if(a[i]->sx==a[j]->tx&&a[i]->sy==a[j]->ty)
				connect(a[j],a[i]);
		}
	for(int i=1;i<=n;i++)
	{
		int len=trace(a[i]);
		if(len>ans.l)
		{
			ans.l=len;
			ans.x=a[i]->sx;
			ans.y=a[i]->sy;
		}
	}
	printf("%d %d %d",ans.l,ans.x,ans.y);
 	return 0;
}
