#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
    int data;
    int high;
    struct node *lchild,*rchild;
}BTNode,*BTREE;

BTREE BUILDBT(BTREE T,int data,int high)
{
    if(T==NULL)
    {
        T=(BTREE)malloc(sizeof(BTNode));
        T->data=data;
        T->high=high;
        T->lchild=NULL;
        T->rchild=NULL;
    }
    
    else if(data<=T->data) // @@ This condition incorrectly places duplicate values (equal to root) in the left subtree, but the problem requires them to go to the right subtree (right child >= root). As a result, node 87 becomes a non-leaf and duplicate 100 becomes a leaf with incorrect height, causing the missing leaf 87 and wrong height for 100.
    {
        T->lchild=BUILDBT(T->lchild,data,high+1);
    }
    
    else
    {
        T->rchild=BUILDBT(T->rchild,data,high+1);
    }
    
    return T;
}

void PREORDER(BTREE T)
{
    if(T->lchild==NULL&&T->rchild==NULL)
    {
        printf("%d %d\n",T->data,T->high);
        return;
    }
    
    if(T!=NULL)
    {
        if(T->lchild)
        PREORDER(T->lchild);
        
        if(T->rchild)
        PREORDER(T->rchild);
    }
}

int main()
{
    int n;
    
    scanf("%d",&n);
    
    BTREE root=NULL;
    
    for(int i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        root=BUILDBT(root,data,1);
    }
    
    PREORDER(root);
    
    return 0;
}