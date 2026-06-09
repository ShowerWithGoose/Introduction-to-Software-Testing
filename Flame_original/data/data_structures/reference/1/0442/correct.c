#include <stdio.h>
#include <string.h>
#define ll long long
#define ull unsigned long long
int vis[11]; 
int n;
void dfs(int a[],int top)
{
	
	if (top == n) 
	{
		for(int i=1;i<=n ;i++)
		printf("%d ",a[i]);
		printf("\n");
		return ;	
	}
	for(int i = 1 ; i <= n ;i++)
	{
		if (!vis[i])
		{
		vis[i] = 1;
	//	printf("%d ",i);
		a[++top] = i;
		dfs(a,top);
		a[top--] = 0;
		vis[i] = 0 ;
		}
	}
}
int rd()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main ()
{
	n=rd();
	int aa[11];
	dfs(aa,0);
}

