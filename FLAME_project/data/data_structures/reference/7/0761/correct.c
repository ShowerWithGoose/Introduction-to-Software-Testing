#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct  node 
{
    int   data;
    int   high;
    struct  node   *left,  *right;
}tree;
tree *origin;
tree *getin(tree *root, int n, int len)
{
    len++;
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->data = n;
        root->left =NULL; root->right = NULL;
        origin = root;
        root->high = len;
    }
    else if (n < root->data)
        root->left = getin(root->left,n, len);
    else if (n >= root->data)
        root->right = getin(root->right,n, len);
    return root;
}
void printfleaves(tree *tre)
{
	if(tre!=NULL)
	{
		if(tre->left==NULL&&tre->right==NULL)
	    printf("%d %d\n",tre->data,tre->high);
	    printfleaves(tre->left);
	    printfleaves(tre->right);
	}
};
int main()
{
	int n,k,m;
	tree *tre=NULL;
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		scanf("%d",&m);
		int i=0;
		tre=getin(tre,m,i);
	}
	printfleaves(tre);
	return 0;
}




