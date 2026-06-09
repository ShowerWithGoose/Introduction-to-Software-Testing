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
            findnote(orin,tree->data,1); // @@ The height of the root node should be 1, but this function always starts searching from height 1, which is incorrect because the leaf node's height should be determined by its actual depth in the tree, not by searching from the root again.
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
    preorder(root,root);
    return 0;
}