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
            findnote(orin,tree->data,1); // @@ [This approach searches the entire tree again for each leaf node to find its height, which is inefficient and incorrect when duplicate values exist. In particular, when there are duplicate values like 100, it prints the height of the first occurrence (root, height=1) instead of the actual leaf node's height (which is 4). The height should be tracked during tree construction or traversal, not looked up by value.]
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