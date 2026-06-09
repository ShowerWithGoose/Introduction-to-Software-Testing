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
    
    else if(data<=T->data)
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
} // @@ [The traversal order is not in-order; the problem requires left-to-right leaf output which corresponds to in-order traversal, but this function uses a modified pre-order that may skip internal nodes incorrectly and does not guarantee left-to-right leaf order when both children exist.]

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
    } // @@ [The BST insertion logic uses `data<=T->data` to go left, but the problem states: "left child is less than the root, right child is greater than or equal". This condition should be `data < T->data` for left, not `<=`. Using `<=` puts equal values on the left, violating the BST definition given.]

    PREORDER(root); // @@ [Calling PREORDER on an empty tree (n=0) would dereference NULL. Also, the function PREORDER assumes T is not NULL when checking children, leading to undefined behavior if root is NULL.]

    return 0;
}