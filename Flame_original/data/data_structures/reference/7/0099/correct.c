#include<stdio.h>
#include<ctype.h>
#define ls id*2
#define rs id*2+1
int tr[400000],vis[400000],n;
void insert(int val,int id)
{
	if(!vis[id]){tr[id]=val;vis[id]=1;return;}
	if(val<tr[id])insert(val,ls);
	else insert(val,rs);
}
void dfs(int id,int dep)
{
	if(!vis[ls]&&!vis[rs]){printf("%d %d\n",tr[id],dep);return;}
	if(vis[ls])dfs(ls,dep+1);
	if(vis[rs])dfs(rs,dep+1);
}
int main()
{
	scanf("%d",&n);
	int i,a;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		insert(a,1);
	}
	dfs(1,1);
//	for(i=1;i<=n;i++)
}

