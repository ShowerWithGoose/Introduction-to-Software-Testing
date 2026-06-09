#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int high;
    struct node *left,*right;
};
struct node *root;
struct node *insertbst(struct node *root,int data,int level)
{
    level++;
    if(root==NULL)
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data=data;
        root->high=level;
        root->left=root->right=NULL;
    }
    else if(data<root->data)
        root->left=insertbst(root->left,data,level);
    else if(data>root->data)
        root->right=insertbst(root->right,data,level);
    else
        root->right=insertbst(root->right,data,level);
    return root;
};
void preorder(struct node *tree)//前序遍历
{
    if(tree!=NULL)
    {
        if(tree->left==NULL&&tree->right==NULL)
        {
            printf("%d %d\n",tree->data,tree->high);
        }
        preorder(tree->left);
        preorder(tree->right);
    }
};
int main()
{
    int i,n,number;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&number);
        root=insertbst(root,number,0);
    }
    preorder(root);
    return 0;
}

