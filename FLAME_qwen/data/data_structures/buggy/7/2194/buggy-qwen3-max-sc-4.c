#include <stdio.h>
#include <stdlib.h>
typedef struct _Node 
{
    int data;
    struct _Node *lchild, *rchild; 
} BTNode, *BTNodeptr;
void visit(int n,int h){
    printf("%d %d\n",n,h);
}
void findnote(BTNodeptr t,int num,int h){
    if (t != NULL) 
    {
        if(t->data==num){
            visit(num,h);
        }
        findnote(t->lchild,num,h+1);
        findnote(t->rchild,num,h+1);
    }
}
void preorder(BTNodeptr tree,BTNodeptr orin) 
{
    if (tree != NULL) 
    {
        if(tree->lchild==NULL && tree->rchild==NULL){
            findnote(orin,tree->data,1); @@ [This is logically incorrect: it searches the entire tree again for the leaf's value to print its height, but the height passed is always 1. The correct height of the leaf in its actual position is not tracked. Instead, the height should be passed down during traversal, not looked up via a separate search.]
        }
        preorder(tree->lchild,orin);
        preorder(tree->rchild,orin); 
    
    } 
}
BTNodeptr insertBST(BTNodeptr p, int item)
{
    if (p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));  
        p->data = item;
        p->lchild = p->rchild = NULL;
    }
    else if (item < p->data)
        p->lchild = insertBST(p->lchild, item);
    else if (item >= p->data)
        p->rchild = insertBST(p->rchild, item);
    return p;
}
int main(){
    int i, item,n;
    scanf("%d",&n);
    BTNodeptr root = NULL;
    for (i = 0; i <n; i++)
    {
        scanf("%d", &item);
        root = insertBST(root, item);
    }
    preorder(root,root); @@ [The function 'preorder' is misnamed and misused—it does an inorder-like traversal of leaves but then incorrectly uses 'findnote' to recompute height from root, which leads to wrong height values. The height should be accumulated during the initial traversal, not recalculated by restarting from height 1.]
    return 0;
}