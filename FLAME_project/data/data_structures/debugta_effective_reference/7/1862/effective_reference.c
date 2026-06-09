#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
struct tree
{
    int val;
    struct tree *left;
    struct tree *right;
    int depth;
};
struct tree *bst(struct tree *t,int value,int depth)
{
    if(t==NULL)
	{
		t=(struct tree *)malloc(sizeof(struct tree));
		t->left=NULL;
		t->right=NULL;
		t->val=value;
		t->depth=depth;
	}
	else if(value<t->val)
	{
		t->left=bst(t->left,value,depth+1);
	}
	else
	{
		t->right=bst(t->right,value,depth+1);
	}
	return t;
}
void scbst(struct tree *t)
{
    if(t!=NULL)
    {
        scbst(t->left);
        if(t->left==NULL&&t->right==NULL)
            printf("%d %d\n",t->val,t->depth);
        scbst(t->right);
    }
}
int main()
{   int n,i,j,k,m;
    scanf("%d",&n);
    struct tree *root=NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        root=bst(root,m,1);
    }
    scbst(root);
    return 0;
}

