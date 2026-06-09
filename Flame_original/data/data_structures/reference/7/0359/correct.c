#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node{
    struct node *left,*right;
    int data;
    int depth;
};
typedef struct node Tree;
Tree *insert(Tree *root,int num,int l)
{
    l++;
    if(root==NULL)
    {
        root=(Tree *)malloc(sizeof(Tree));
        root->data=num;
        root->depth=l;
        root->left=root->right=NULL;
    }
    else if(num<root->data)
        root->left=insert(root->left,num,l);
    else if(num>=root->data)
        root->right=insert(root->right,num,l);
    return root;
}
void print(Tree *root)
{
    if(root)
    {
        if(!(root->left) && !(root->right))
        {
            printf("%d %d\n",root->data,root->depth);
        }
    print(root->left);
    print(root->right);
	}
}
int main()
{
	int n,num,l;
    Tree *root=NULL;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
        l=0;
        root=insert(root,num,l);
    }
    print(root);
    return 0;
}

