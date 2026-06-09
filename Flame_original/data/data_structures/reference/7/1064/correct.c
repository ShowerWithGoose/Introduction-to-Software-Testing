#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef int DataType;
typedef struct node{
    DataType data;
    int depth;
    struct node *left,*right;
}Tree;
Tree *begin;
Tree *create(Tree *root,int x,int floor)
{
    floor++;
    if(root==NULL){
        root=(Tree *)malloc(sizeof(Tree));
        root->data=x;
        root->left=NULL;
        root->right=NULL;
        begin=root;
        root->depth=floor;
    }
    else if(x<root->data)root->left=create(root->left,x,floor);
    else root->right=create(root->right,x,floor);
    return root;
}
void yelevel(Tree *root)
{
    if(root){
        if(root->left==NULL&&root->right==NULL)printf("%d %d\n",root->data,root->depth);
        yelevel(root->left);
        yelevel(root->right);
    }
}
int main()
{
    Tree *root=NULL;
    int n,a[10000],i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        int level=0;
        root=create(root,a[i],level);
    }
    yelevel(root);
    return 0;
}

