#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int Deep;
    struct node *left,*right;
}tree;
tree *new(tree *root,int temp,int deep);
void print(tree *root);
int main(){
    int n,i,temp;
    tree *root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        int deep=0;
        root=new(root,temp,deep);
    }
    print(root);
    return 0;
}
tree *new(tree *root,int temp,int deep)
{
    deep++;
    if(root==NULL)
    {
        root=(tree *)malloc(sizeof(tree));
        root->data=temp;
        root->Deep=deep;
        root->left=root->right=NULL;
    }
    else if(temp<root->data)
        root->left=new(root->left,temp,deep);
    else if(temp>=root->data)
        root->right=new(root->right,temp,deep);
    return root;
}
void print(tree *root)
{
    if(root)
{
        if(!(root->right)&&!(root->left))
{
            printf("%d %d\n",root->data,root->Deep);
}
    print(root->left);
    print(root->right);
}
}

