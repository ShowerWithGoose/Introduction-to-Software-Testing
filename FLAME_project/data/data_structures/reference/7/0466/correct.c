#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int w;
	struct Node *l, *r;
} node;

node t[10000], *rt;
int cnt;

node* insert(node *cur, int val)
{
	if(cur == NULL)
	{
		cur = (node*)malloc(sizeof(node));
		cur->l = cur->r = NULL;
		cur->w = val;	
		return cur;
	}
	if(val < cur->w)
		cur->l = insert(cur->l, val);
	else
		cur->r = insert(cur->r, val);
	return cur;
}
void search(node *x,int dep)
{
	if(x == NULL)	return;
	if(x->l==NULL && x->r==NULL)
	{
		printf("%d %d\n", x->w, dep);
		return;
	}
	search(x->l, dep+1);
	search(x->r, dep+1);
}

int main()
{
	int i,j,k,n,m;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		rt = insert(rt, m);
	}
	
	search(rt, 1);
	
	
	
	
	
	
	
	return 0;
}

