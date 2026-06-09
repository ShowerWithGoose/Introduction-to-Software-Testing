#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int data;
    struct _Node *lchild,*rchild;
}BTNode,*BTNodeptr;
        
int height=1; // @@ [Using a global variable 'height' causes incorrect height tracking during traversal because it is shared across all recursive calls and modified in preorder traversal, leading to wrong height values for leaf nodes.]

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
            printf("%d %d\n",t->data,height); // @@ [The height of the current node is not stored in the node itself, and the global 'height' variable does not reflect the actual depth of the current node due to flawed increment/decrement logic.]
        }
        else
        {
            height++; // @@ [Incrementing height before traversing children assumes both children exist, but if only one child exists, the height adjustment becomes inconsistent. Also, global state makes this approach error-prone.]
            preorder(t->lchild);
            preorder(t->rchild);
            height--; // @@ [Decrementing after both recursive calls fails to correctly backtrack height when only one subtree is traversed or when recursion paths diverge.]
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