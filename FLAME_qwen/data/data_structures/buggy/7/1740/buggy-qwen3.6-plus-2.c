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
    return root; // @@ [Compilation Error] The function 'outprintf' is declared as void, so it cannot return a value.
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
        in(root,m); // @@ [Logical Error] The return value of the insertion function is discarded, so 'root' remains NULL and the tree is not constructed correctly.
    }
    outprintf(root,1);
    return 0;
}