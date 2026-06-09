#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int data;
    struct _Node *lchild,*rchild;
}BTNode,*BTNodeptr;
        
int height=1; // @@ [Using a global variable 'height' causes incorrect height tracking during traversal because it is shared across all recursive calls and does not represent the actual depth of each node.]

BTNodeptr insertBST(BTNodeptr p,int item)
{
    if(p==NULL)//新建树 
    {
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=item;
        p->lchild=p->rchild=NULL;
    }
    else if(item<p->data)
        p->lchild=insertBST(p->lchild,item);
    else if(item>p->data)
        p->rchild=insertBST(p->rchild,item);
    return p; 
}

void preorder(BTNodeptr t)
{
    if(t!=NULL)//先判断t非空 
    {
        if(t->lchild==NULL&&t->rchild==NULL)
        {
            printf("%d %d\n",t->data,height); // @@ [The global 'height' does not reflect the true height of the current leaf node; it changes during traversal and is not passed or tracked per node.]
        }
        else
        {
            height++; // @@ [Modifying a global 'height' during recursion leads to incorrect values when backtracking and traversing right subtrees.]
            preorder(t->lchild);
            preorder(t->rchild);
            height--; // @@ [This decrement assumes a strict left-right backtrack, but global state makes it unreliable for complex trees.]
        }
        
    }
}
 
int main()
{
    int n,item;
    BTNodeptr root=NULL;
    scanf("%d",&n);
    
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        root=insertBST(root,item);
    }
    preorder(root);
    return 0;
}