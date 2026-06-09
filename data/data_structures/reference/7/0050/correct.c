#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node 
{
    struct node *left,*right;
    int num;
    int high;
}Tree;
Tree *one;
Tree *a(Tree *root,int num,int high);
int main()
{
	Tree *root=NULL;
	int n,i,st;
	int deep=0;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
		scanf("%d",&st);
		root=a(root, st, deep);
	}
	print(root);
	return 0;
}
Tree *a(Tree *root,int st,int deep)
{
	deep++;
	if(root==NULL)
	{
		root=(Tree*)malloc(sizeof(Tree));
		root->num=st;
		root->left=root->right=NULL;
		one=root;
		root->high=deep;
	}
	else if(st<root->num)
	   root->left=a(root->left, st, deep);
	else if(st>=root->num)
	   root->right=a(root->right, st, deep);
	   return root;
}
void print(Tree *root)
{
	if (root)
    {
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->num, root->high);
        }
        print(root->left);
        print(root->right);
    }
}





