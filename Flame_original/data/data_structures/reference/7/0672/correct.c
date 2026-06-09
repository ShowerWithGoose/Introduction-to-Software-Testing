#include<stdio.h>
int ch[100100][2],tot=1,n;
int num[100100];
void insert(int x)
{
	int u=1,f=0,op;
	while(u)
	{
		f=u;
		if(x<num[u])u=ch[u][0],op=0;
		else u=ch[u][1],op=1;
	}
	u=++tot;
	num[u]=x;
	ch[f][op]=u;
}
void dfs(int u,int deep)
{
	if((!ch[u][0])&&(!ch[u][1]))printf("%d %d\n",num[u],deep);
	if(ch[u][0])dfs(ch[u][0],deep+1);
	if(ch[u][1])dfs(ch[u][1],deep+1);
}
int main()
{
	int i;
	scanf("%d%d",&n,&num[1]);
	for(i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		insert(x);
	}
	dfs(1,1);
}

