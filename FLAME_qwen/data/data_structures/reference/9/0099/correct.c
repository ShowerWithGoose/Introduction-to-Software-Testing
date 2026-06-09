#include<stdio.h>
#include<stdlib.h>
int head[110],num;
struct node{int nxt,to;}edge[10010];
struct nod{int x1,x2,y1,y2;}a[110];
int n,i,j,ru[110];
void add(int st,int ed)
{
//	if(st==1||ed==1)printf("0");
	edge[++num].nxt=head[st];
	edge[num].to=ed;
	head[st]=num;
}int anss,ans;
int X1,X2,Y1,Y2;
void dfs(int x)
{
	ans++;int k;
	for(k=head[x];k;k=edge[k].nxt)
	{
		//printf("%d\n",edge[i].nxt);
		dfs(edge[k].to);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		for(j=1;j<i;j++)
		{
			if(a[j].x1==a[i].x1&&a[j].y1==a[i].y1&&a[i].x1==a[j].x1&&a[i].y2==a[j].y2)continue;
			if(a[j].x1==a[i].x2&&a[j].y1==a[i].y2)
				add(i,j),ru[j]++;
			if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2) 
				add(j,i),ru[i]++;
		}
	}//printf("%d\n",head[1]);
	for(i=1;i<=n;i++)
	{
		ans=0;
		if(ru[i]==0)dfs(i);
		if(ans>anss)anss=ans,X1=a[i].x1,Y1=a[i].y1;
	}printf("%d %d %d\n",anss,X1,Y1);
}

