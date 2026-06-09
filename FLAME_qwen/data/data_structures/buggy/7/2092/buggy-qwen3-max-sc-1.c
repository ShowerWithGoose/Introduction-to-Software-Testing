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
} // @@ [The traversal logic is flawed: the function returns early when encountering a leaf, but for non-leaf nodes, it doesn't check if T is NULL before accessing lchild/rchild. Also, the condition `if(T!=NULL)` comes after already dereferencing T, which causes undefined behavior on empty tree.]

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
    
    PREORDER(root); // @@ [If the input n is 0, root remains NULL, and passing NULL to PREORDER will cause a segmentation fault because PREORDER dereferences T without checking for NULL first.]
    
    return 0;
}