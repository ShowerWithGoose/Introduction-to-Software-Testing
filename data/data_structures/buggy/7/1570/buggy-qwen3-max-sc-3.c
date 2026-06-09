#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int data;
    struct _Node *lchild,*rchild;
}BTNode,*BTNodeptr;
        
int height=1; // @@ [Using a global variable 'height' leads to incorrect height tracking during traversal because it is shared across all recursive calls and does not represent the actual depth of each node.]

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
            printf("%d %d\n",t->data,height); // @@ [Printing the global 'height' instead of the actual height of the current leaf node. The global height does not reflect the true depth of the node in the tree.]
        }
        else
        {
            height++; // @@ [Modifying a global height variable during traversal causes incorrect height values for different branches due to shared state across recursive calls.]
            preorder(t->lchild);
            preorder(t->rchild);
            height--; // @@ [Decrementing global height after recursion assumes symmetric traversal and fails when one subtree is missing or traversal order affects height, leading to wrong heights for subsequent nodes.]
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