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
        if(data>root->num)
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
    if(root->left!=NULL) // @@ [Error: Should check root->right != NULL instead of root->left != NULL. This causes the right subtree to never be traversed, and the left subtree may be traversed twice, leading to incorrect leaf output.]
    {
        printleaf(root->right,h+1); 
    }
}