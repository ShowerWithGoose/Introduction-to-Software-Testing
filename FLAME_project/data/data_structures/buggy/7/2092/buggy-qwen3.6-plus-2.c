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
    
    else if(data<T->data) // @@ The problem states left child is less than root, right child is greater than or equal. The original code used data<=T->data for left, which puts equal values on the left. It should be data<T->data for left, and else (which covers >=) for right.
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
    if(T==NULL) return; // @@ The original code accesses T->lchild and T->rchild before checking if T is NULL, which causes a segmentation fault or undefined behavior if T is NULL. Although the main logic calls it on non-null root, recursive calls might pass NULL children if not checked properly inside the recursion structure, but more importantly, the check `if(T->lchild==NULL&&T->rchild==NULL)` dereferences T. If T is NULL, this crashes. The check for NULL must happen first.
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