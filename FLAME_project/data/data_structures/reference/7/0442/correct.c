#include <stdio.h>
#include <string.h>
#define MAXLEN 1000001
int tree[MAXLEN];
int treeh[MAXLEN];
int vis[MAXLEN];
void insert(int p,int x)
{
	if(vis[p] == 0)
	{
		vis[p] = 1;
		tree[p] = x;
		treeh[p] = treeh[p/2] + 1;
		return ;
	}
	else if(tree[p] <= x)
	{
		insert(p*2+1,x);
	}
	else {
		insert(p*2,x);
	}
}

void dfs(int p)
{
	if(vis[2*p] == 0&& vis[2*p+1]==0)
	{
		printf("%d %d\n",tree[p],treeh[p]);
		return ;
	}
	if(vis[2*p] != 0)
	dfs(p*2);
	if(vis[2*p+1] != 0)
	dfs(p*2 + 1);
	//printf("%d %d\n",tree[p],treeh[p]);
}

int main ()
{
	int n;
	scanf("%d",&n);
	for(int i = 1 ;i <= n ; i++ )
	{
		int d;
		scanf("%d",&d);
		insert(1,d);
	}
	dfs(1);
	return 0;
}

