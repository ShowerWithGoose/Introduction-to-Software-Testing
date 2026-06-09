#include<stdio.h>
typedef struct Tree{
	int k,lch,rch,size;
}tree;
tree t[100005];int tot;
int n,tmp;
void add(int k,int v)
{
	if(v<t[k].k)
	{
		if(!t[k].lch)
		{
			t[k].lch=++tot;
			t[tot].k=v;
			t[k].size++;
			return;
		}
		add(t[k].lch,v);
	}
	else
	{
		if(!t[k].rch)
		{
			t[k].rch=++tot;
			t[tot].k=v;
			t[k].size++;
			return;
		}
		add(t[k].rch,v);
	}
}
void dfs(int k,int d)
{
	if(!t[k].size)
	{
		printf("%d %d\n",t[k].k,d);
		return;
	}
	if(t[k].lch)	dfs(t[k].lch,d+1);
	if(t[k].rch)	dfs(t[k].rch,d+1);
}
signed main()
{
	scanf("%d%d",&n,&tmp);
	t[++tot].k=tmp;
	for(int q=1;q<n;q++)
	{
		scanf("%d",&tmp);
		add(1,tmp);
	}
	dfs(1,1);
}

