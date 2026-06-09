#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
    int num;
    struct node *left;
    struct node *right;
}tree;
tree* insert(tree* root,int data);
void printleaf(tree* root,int h);
int main()
{
    int n;
    scanf("%d",&n);
    tree *root=NULL;
    int tmp;
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        root=insert(root,tmp);
    }
    printleaf(root,1);
    return 0;
}
tree* insert(tree* root,int data)
{
    if(root==NULL)
    {
        root=(tree*)malloc(sizeof(tree));
        root->num=data;
        root->left=root->right=NULL;
        return root;
    }
    else
    {
        if(data>root->num) // @@ The problem states right child is >= root, but this condition only puts strictly greater values to the right. Values equal to root go left, which contradicts the standard BST definition implied by "right child is greater than or equal". However, the bigger issue is usually consistency with the reference. The reference uses `n < p->num` for left, else right. This code uses `data > root->num` for right, else left. This means equal elements go to the LEFT. The reference puts equal elements to the RIGHT. This changes the tree structure and potentially the leaf nodes.
        {
            root->right=insert(root->right,data);
        }
        else 
        {
            root->left=insert(root->left,data);
        }
        return root;
    }
}
void printleaf(tree*root,int h)
{
    if(root==NULL) return; // @@ Missing null check for root causes Runtime Error when accessing root->left or root->right on a NULL pointer (e.g., if initial root is NULL or during recursion).
    if(root->left==NULL&&root->right==NULL)//Ò¶½Úµã 
    {
        printf("%d %d\n",root->num,h);
        return;
    }
    if(root->left!=NULL)
        {
            printleaf(root->left,h+1);
        }
    if(root->left!=NULL) // @@ Logic error: This condition checks root->left again instead of root->right. Consequently, the right subtree is never traversed if root->left is NULL, or traversed incorrectly. It should be `if(root->right!=NULL)`.
    {
        printleaf(root->right,h+1); 
    }
}