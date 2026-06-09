#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int data;
    struct _Node *lchild,*rchild;
}BTNode,*BTNodeptr;
        
int height=1; // @@ [Using a global variable 'height' leads to incorrect height tracking during traversal because it is shared across all recursive calls and modified in preorder traversal, causing wrong height values for leaf nodes.]

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
            printf("%d %d\n",t->data,height); // @@ [The height printed here is the global 'height', which does not represent the actual depth of the current node in the tree. The height should be stored per node or passed as a parameter during traversal.]
        }
        else
        {
            height++; // @@ [Modifying a global 'height' variable during recursion causes incorrect state sharing between different branches of the tree, leading to wrong height values for leaf nodes.]
            preorder(t->lchild);
            preorder(t->rchild);
            height--; // @@ [This decrement assumes a strict DFS backtracking pattern, but due to the global nature and possible early returns or unbalanced traversal, the height may not be correctly restored.]
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