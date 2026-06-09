#include<stdio.h>
#include<string.h>
typedef struct t
{
	int a;
	int h;
	struct t *left, *right;
}tree;
tree *t0;
tree *next(tree *n, int temp, int l)
{
    l++;
    if (n==NULL)
    {
        n=(tree*)malloc(sizeof(tree));
        n->a=temp;
        n->left=n->right=NULL;
        t0=n;
        n->h=l;
    }
    else if (temp<n->a)
    {
        n->left=next(n->left,temp,l);
    }
    else if (temp>=n->a)
    {
        n->right=next(n->right,temp,l);
    }
    return n;
}
void p(tree *n)
{
	if(n>0)
	{
		if(n->left==NULL&&n->right==NULL)
		{
			printf("%d %d\n",n->a,n->h);
		}
		p(n->left);
		p(n->right);
	}
}
int main()
{
	tree *n=NULL;
	int i,m,temp,l;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&temp);
		l=0;
		n=next(n,temp,l);
	}
	p(n);
	return 0;
 } 



