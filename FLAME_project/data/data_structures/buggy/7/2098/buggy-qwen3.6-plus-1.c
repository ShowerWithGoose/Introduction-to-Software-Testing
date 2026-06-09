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
        if(data>root->num) // @@ The problem states right child is >= root, but this condition only puts strictly greater values to the right. Values equal to root go left, which contradicts the standard BST definition given (left < root, right >= root). However, looking at the reference code, `else` handles `>=`. Here `data > root->num` goes right, `else` (<=) goes left. This reverses the logic for equality compared to the reference, but more importantly, let's look at the crash.
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
    if(root->left==NULL&&root->right==NULL)//Ò¶½Úµã 
    {
        printf("%d %d\n",root->num,h);
        return;
    }
    if(root->left!=NULL)
        {
            printleaf(root->left,h+1);
        }
    if(root->left!=NULL) // @@ This condition checks root->left again instead of root->right. If root->left is NULL but root->right is NOT NULL, this block is skipped, and the function returns without processing the right subtree. More critically, if root->left is NOT NULL but root->right IS NULL, it tries to recurse on root->right? No, it recurses on root->right inside the block. Wait. The bug is that it checks `root->left` twice. The second check should be `root->right != NULL`. Because it checks `root->left`, if `root->left` is not null, it enters the block and calls `printleaf(root->right, h+1)`. If `root->right` is NULL, this call will crash because `printleaf` does not handle NULL root at the beginning (it accesses `root->left` immediately).
    {
        printleaf(root->right,h+1); 
    }
}