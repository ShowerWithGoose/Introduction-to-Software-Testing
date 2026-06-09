#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>

typedef struct list
{
    int num;
    int hi;
    struct list *left,*right;
}Tree;

void tree(Tree *root,int nu)
{
    struct list *leaf;
    if(nu<root->num)
    {
        if(root->left==NULL)
        {
            leaf = (Tree *)malloc(sizeof(Tree));
            leaf->num=nu;
            leaf->hi=root->hi+1;
            root->left=leaf;
            leaf->left=NULL;
            leaf->right=NULL;
            //printf("%d %d\n",leaf->num,leaf->hi);
        }
        else tree(root->left,nu);
    }
    else if(nu>=root->num)
    {
        if(root->right==NULL)
        {
            leaf = (Tree *)malloc(sizeof(Tree));
            leaf->num=nu;
            leaf->hi=root->hi+1;
            root->right=leaf;
            leaf->left=NULL;
            leaf->right=NULL;
            //printf("%d %d\n",leaf->num,leaf->hi);
        }
        else tree(root->right,nu);
    }
}

void print(Tree *root)
{
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL)
        printf("%d %d\n",root->num,root->hi);
    print(root->left);
    print(root->right);
    return NULL;
}

int main()
{
    int n;
    scanf("%d",&n);
    struct list *first=NULL,*root;
    for(int i=1;i<=n;i++)
    {
        int k;scanf("%d",&k);
        if(first == NULL)
        {
            root = (Tree *)malloc(sizeof(Tree));
            root->num=k;
            root->hi=1;
            root->left=NULL;
            root->right=NULL;
            first=root;
        }
        else tree(first,k);
    }
    print(first);
    return 0;
}

