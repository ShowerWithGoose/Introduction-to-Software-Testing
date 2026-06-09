#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int data;
    struct _Node *lchild,*rchild;
}BTNode,*BTNodeptr;
        
int height=1; // @@ [Using a global variable 'height' leads to incorrect height tracking during traversal because it is shared across all recursive calls and not specific to each node.]

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
            printf("%d %d\n",t->data,height); // @@ [The height printed is the global 'height', which does not reflect the actual height of the current leaf node in the tree.]
        }
        else
        {
            height++; // @@ [Modifying a global 'height' during traversal causes incorrect values when backtracking or traversing right subtrees after left ones.]
            preorder(t->lchild);
            preorder(t->rchild);
            height--; // @@ [This decrement assumes a strict DFS stack-like behavior, but global state makes it error-prone especially with multiple branches.]
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