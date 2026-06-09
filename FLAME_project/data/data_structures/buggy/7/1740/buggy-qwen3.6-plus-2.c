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
void outprintf(bst root,int height) // @@ [Return type is void, but the function attempts to return a value 'root' at the end, causing a compilation/logical error. It should be bst or the return statement removed.]
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
    return root; // @@ [Cannot return a value from a function with void return type. Also, logic suggests this function should just traverse and print, not return anything.]
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
        root = in(root,m); // @@ [The return value of in() must be assigned back to root, otherwise root remains NULL after the first insertion because C passes pointers by value.]
    }
    outprintf(root,1);
    return 0;
}