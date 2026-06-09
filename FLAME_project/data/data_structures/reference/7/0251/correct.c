#include<stdio.h>
#include<stdlib.h>
typedef struct Bst
{
    int data;
    struct Bst *left,*right;
}Bst,*PBst;

PBst createtree(PBst root,int data)
{
if(root==NULL)
{
    root=(PBst)malloc(sizeof(Bst));
    root->data=data;
    root->right=NULL;
    root->left=root->right;
    return root;
}
else if(data<root->data)
{
root->left=createtree(root->left,data);
}
else
{
    root->right=createtree(root->right,data);
}
return root;
}

void printBst(PBst root,int height)
{
    if(root==NULL)
    return;
    if(root->left!=NULL)
    printBst(root->left,height+1);
    if(root->right!=NULL)
    {
        printBst(root->right,height+1);
    }
    if(root->left==NULL&&root->right==NULL)
    {
        printf("%d %d\n",root->data,height);
        return;
    }
}

int main()
{
PBst root = NULL;
int n,data;
scanf("%d",&n);
while(n--)
{
    scanf("%d",&data);
    root=createtree(root,data);
}
printBst(root,1);
}

