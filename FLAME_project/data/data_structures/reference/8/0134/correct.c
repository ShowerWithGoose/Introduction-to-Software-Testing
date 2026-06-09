#include<stdio.h>
#include<string.h>
int n,cnt,head,tail,a[100+10][100+10],vis[100+10],ans[100+10],q[100+10];
void dfs(int x);
void bfs(int x);
void output(); 
int main()
{
	int m,x,y;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d", &x, &y);
		a[x][y]=a[y][x]=1; 
	}//建图
	dfs(0);
	output();
	bfs(0);
	output();
	scanf("%d", &x);
	for(int i=0;i<n;i++)
	{
		a[x][i]=a[i][x]=0;
	}//删点
	dfs(0);
	output(); 
	bfs(0);
	output(); 
	return 0;
}
void dfs(int x)
{ 
	if(x==0)
	{
		vis[0]=1;
		ans[0]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(a[x][i]==1 && !vis[i])
		{
			vis[i]=1;
			ans[++cnt]=i;
			dfs(i);
			//vis[x]=0;
		}
	}
	return;
}
void bfs(int x)
{
	if(x==0)
	{
		vis[0]=1;
		ans[0]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(a[x][i]==1 && !vis[i])
		{
			q[++tail]=i;
			vis[i]=1;
			ans[++cnt]=i;
		}
	}
	while(head<=tail)
	{
		bfs(q[head++]);
	}
	return;
}
void output()
{
	for(int i=0;i<=cnt;i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	cnt=head=0;
	tail=-1; 
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));//初始化
	return;
}


