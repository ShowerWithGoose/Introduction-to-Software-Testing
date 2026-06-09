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
            findnote(orin,tree->data,1); // @@ [This function call incorrectly starts height at 1 for every leaf, and searches the entire tree to find the leaf again, which is inefficient and logically flawed. The height of a leaf should be computed during traversal, not by restarting from root.]
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