#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*lchild;
    struct node*rchild;
}; 
typedef struct node node;
typedef struct node* bst;

bst in(bst root,int indata){
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=indata;
        root->lchild=NULL;
        root->rchild=NULL;
        return root;
    }
    else
    {
        if(indata<root->data)
        root->lchild=in(root->lchild,indata);
        else
        root->rchild=in(root->rchild,indata);
        return root;
    }
}
void outprintf(bst root,int height)
{
    if(root->lchild==NULL&&root->rchild==NULL)
    {
        printf("%d %d\n",root->data,height);
        return;
    }
    
    else 
    {
        if(root->lchild!=NULL)
    outprintf(root->lchild,height+1);
    if(root->rchild!=NULL)
    outprintf(root->rchild,height+1);
    return root; // @@ [Error: 'return root;' in a void function is invalid and causes a compilation error. The function is declared as void, so it should not return a value. Remove this line or change it to 'return;'.]
    }
}
int main()
{
    int n;
    bst root=NULL;
    scanf("%d",&n);
    int m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        in(root,m); // @@ [Error: The return value of 'in' is ignored. The function returns the updated root, but it is not assigned back to 'root', so the tree remains empty. Should be 'root = in(root,m);'.]
    }
    outprintf(root,1); // @@ [Error: Since 'root' is never updated, it remains NULL, causing a segmentation fault when 'outprintf' tries to access root->lchild.]
    return 0;
}