#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct Node *lchild,*rchild;
}Node;


Node *getNewNode(int val)
{
    Node *root=(Node*)malloc(sizeof(Node));
    root->val=val;
    root->lchild=root->rchild=NULL;
    return root;
}

Node* insert(Node *root,int val)
{
    if(root==NULL)
    {
        root=getNewNode(val);
        return root;
    }
    if(val<root->val) root->lchild=insert(root->lchild,val);
    else root->rchild=insert(root->rchild,val);
    return root;
}

void output(Node *root,int k)
{
    if(root->lchild==NULL&&root->rchild==NULL)
    {
        printf("%d %d\n",root->val,k);
        return ;
    }
    if(root->lchild) output(root->lchild,k+1);
    if(root->rchild) output(root->rchild,k+1);
    return ;

}

int main()
{
    int n;
    int val;
    int i;
    Node *root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        root=insert(root,val);
    }
    output(root,1);
    return 0;
}

