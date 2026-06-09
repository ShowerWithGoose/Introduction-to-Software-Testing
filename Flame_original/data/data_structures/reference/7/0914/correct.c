#include <stdio.h>
#include <string.h>
int lvl=0;
struct node{
	int v;
	int l;
	int r;
};
struct node tree[10000];
int cmp(int m,int t)
{
	if(tree[m].v<tree[t].v)
	{
		if(tree[t].l!=-1)
		{
			cmp(m,tree[t].l);
		}
		else
		{
			tree[t].l=m;
			return 0;
		}
	}
	else
	{
		if(tree[t].r!=-1)
		{
			cmp(m,tree[t].r);
		}
		else
		{
			tree[t].r=m;
			return 0;
		}
	}
}
void leftsearch(int x)
{
	if(x==-1)
	{
		return;
	}
	lvl++;
	if(tree[x].l==-1&&tree[x].r==-1)
	{
		printf("%d %d\n",tree[x].v,lvl);
	}
	else
	{
		leftsearch(tree[x].l);
		leftsearch(tree[x].r);
	}
	lvl--;
		return;
}
int main()
{
	int n,m,a,c;
	scanf("%d",&n);
	m=0;
	scanf("%d",&c);
	tree[m].v=c;
	tree[m].l=-1;
	tree[m].r=-1;
	m++;
	while(m<n)
	{
		scanf("%d",&c);
		tree[m].v=c;
	    tree[m].l=-1;
    	tree[m].r=-1;
    	cmp(m,0);
    	m++;
	}
	leftsearch(0);
	return 0;
} 

