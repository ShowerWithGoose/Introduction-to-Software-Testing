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
            visit(num,h); // @@ This prints every occurrence of num, including non-leaf nodes with the same value, causing extra output (e.g., root 100 at depth 1).
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
            findnote(orin,tree->data,1); // @@ This searches the entire tree for all nodes with the leaf's value, leading to duplicate lines and incorrect depth (starting from 1). Should directly output the leaf's own depth.
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