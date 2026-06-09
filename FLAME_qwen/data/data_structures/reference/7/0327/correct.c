#include<stdio.h>
#include<stdlib.h>
typedef struct leafa
{
    int data;
    int high;
    struct leafa *left;
    struct leafa *right;
} leaf;
leaf *tree(int n)
{
    leaf *root;
    root=(leaf*)malloc(sizeof(leaf));
    root->high=1;
    root->data=n;
    root->left=NULL;
    root->right=NULL;
    return root;
}
void insert(leaf *root,int d)
{
    leaf *node;
    if(d>=root->data)
    {
        if(root->right==NULL)
        {
            node=(leaf*)malloc(sizeof(leaf));
            root->right=node;
            node->data=d;
            node->high=root->high+1;
            node->left=NULL;
            node->right=NULL;
        }
        else
        {
            node=root->right;
            insert(node,d);
        }
    }
    else
    {
        if(root->left==NULL)
        {
            node=(leaf*)malloc(sizeof(leaf));
            root->left=node;
            node->high=root->high+1;
            node->data=d;
            node->left=NULL;
            node->right=NULL;
        }
        else
        {
            node=root->left;
            insert(node,d);
        }
    }
}
void univer(leaf *root)
{
    leaf *x=root;
    if(root->left==NULL&&root->right==NULL)
    {
        printf("%d %d\n",root->data,root->high);
    }
    if(root->left!=NULL)
    {
        x=root->left;
        univer(x);
    }
    if(root->right!=NULL)
    {
        x=root->right;
        univer(x);
    }
}

int main()
{
    int num,d;
    leaf *l;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        if(i==0)
        {
            scanf("%d",&d);
            l=tree(d);
        }
        else
        {
            scanf("%d",&d);
            insert(l,d);
        }
    }
    univer(l);
    return 0;
}
