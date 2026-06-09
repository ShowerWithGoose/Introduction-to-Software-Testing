#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    int depth;
    struct node *lchild, *rchild;
};
typedef struct node bst;
typedef struct node *treebst;
treebst Root=NULL;
void visit(treebst t)
{
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL)
            printf("%d %d\n",t->data,t->depth);
        visit(t->lchild);
        visit(t->rchild);
    }
}
treebst create(treebst root,int x,int n)
{
    n++;
    if(root==NULL){
        root=(treebst)malloc(sizeof(bst));
        root->data=x;
        root->lchild=root->rchild=NULL;
        Root=root;
        root->depth=n;
    }
    else if (x<root->data)
        root->lchild=create(root->lchild,x,n);
    else if (x>=root->data)
        root->rchild=create(root->rchild,x,n);
    return root;
}
int main()
{
    treebst treeroot=NULL;
    int n,m;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&m);
        int count=0;
        treeroot=create(treeroot,m,count);
    }
    visit(treeroot);
    return 0;
}

