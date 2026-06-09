#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct stu{
	int num;
	struct stu *left;
	struct stu *right;
	int floor;
};

void pr(struct stu *x)
{
	if(x->left==NULL&&x->right==NULL)
	{
		printf("%d %d\n",x->num,x->floor);
	}
	else
	{
		if(x->left!=NULL)
		{
			pr(x->left);
		}
		if(x->right!=NULL)
		{
			pr(x->right);
		}
	}
}////从左打到右，叶节点

int main()
{
	int n=0,i=0;
	struct stu tree[1000],*p;
	scanf("%d",&n);
	if(n>1000)
	{
		n=1000;
	} 
	for(i=0;i<n;i++)
	{
		scanf("%d",&tree[i].num);
		tree[i].left=NULL;
		tree[i].right=NULL;
		tree[i].floor=0;
	}
	tree[0].floor=1;
	for(i=1;i<n;i++)
	{
		p=&tree[0];
		while(1)
		{
			if(tree[i].num<p->num)
		    {
			    if(p->left==NULL)
		        {
				    p->left=&tree[i];
				    tree[i].floor=p->floor+1;
		    	    break;
			    }
			    else
			    {
			    	p=p->left;
				}
		    }
		    else
		    {
		    	if(p->right==NULL)
		        {
				    p->right=&tree[i];
				    tree[i].floor=p->floor+1;
		    	    break;
			    }
			    else
			    {
			    	p=p->right;
				}
		    }
		}
	}
	p=&tree[0];
	pr(p);
	return 0;
}


