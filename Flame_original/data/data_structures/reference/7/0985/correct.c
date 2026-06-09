#include<stdio.h>

struct node
{
	int l,r;
	int dep,val;
}p[500005];
int n,x,tot=1;
void insert(int u,int x)
{
	if(x<p[u].val)
	{
		if(!p[u].l)
		{
			tot++;
			p[tot].val=x;
			p[tot].dep=p[u].dep+1;
			p[u].l=tot;
			return ;
		}
		else
		{
			insert(p[u].l,x);
		}
	}
	else
	{
		if(!p[u].r)
		{
			tot++;
			p[tot].val=x;
			p[tot].dep=p[u].dep+1;
			p[u].r=tot;
			return ;
		}
		else
		{
			insert(p[u].r,x);
		}
	}
}
void find(int u)
{
	if(!p[u].l&&!p[u].r)
	{
		printf("%d %d\n",p[u].val,p[u].dep);
		return ;
	}
	if(p[u].l)
		find(p[u].l);
	if(p[u].r)
		find(p[u].r);
}
int main()
{	
	scanf("%d",&n);
	scanf("%d",&x);
	p[1].val=x;
	p[1].dep=1;

	for(int i=1;i<n;i++)
	{
		scanf("%d",&x);
		insert(1,x);
	}
	find(1);
	return 0;
}

