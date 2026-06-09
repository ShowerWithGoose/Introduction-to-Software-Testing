#include<stdio.h>
struct node
{
    int data;
    struct node* left,* right;
};
typedef struct node BTNnode,*BTNnodeptr;
BTNnodeptr insert(BTNnodeptr root,int item);
int isleave(BTNnodeptr root);
void leaves_height(BTNnodeptr root,int h);
int main()
{
    int i,n,item;
    BTNnodeptr root=NULL;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&item);
        root=insert(root,item);
    }
    leaves_height(root,0); @@ [The initial height passed is 0, but the root's height should be 1. This causes leaf heights to be off by one.]
    return 0;
}
BTNnodeptr insert(BTNnodeptr root,int item)
//new root after inserting item into root
{
    if(root==NULL)
    {
        root=(BTNnodeptr)malloc(sizeof(BTNnode)); @@ [Missing #include <stdlib.h> for malloc, causing compilation error.]
        root->data=item;
        root->left=NULL;
        root->right=NULL;
    }
    else if(item>=(root->data))
    {
        root->right=insert(root->right,item);
    }
    else if(item<(root->data))
    {
        root->left=insert(root->left,item);
    }
    return root;
}
void leaves_height(BTNnodeptr root,int h)
{
    if(root!=NULL&&isleave(root))
    {
        printf("%d %d\n",root->data,h+1);
    }
    else
    {
        leaves_height(root->left,h+1); @@ [When root is NULL, this will cause a segmentation fault because isleave is not checked before recursing. Also, the logic does not skip non-leaf nodes correctly.]
        leaves_height(root->right,h+1); @@ [Same issue as above: recursion occurs even when root is NULL or not a leaf, leading to undefined behavior.]
    }
}
int isleave(BTNnodeptr root)
{
    if(root->left==NULL&&root->right==NULL)return 1;
    return 0;
}