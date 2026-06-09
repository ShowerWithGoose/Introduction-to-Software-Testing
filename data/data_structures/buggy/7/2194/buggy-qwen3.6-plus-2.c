#include <stdio.h>
#include <stdlib.h>
typedef struct _Node  // @@ [Identifier '_Node' starts with an underscore followed by a capital letter, which is reserved for the implementation in C. This may cause a compilation error on strict compilers. Use 'Node' instead.]
{
    int data;
    struct _Node *lchild, *rchild; 
} BTNode, *BTNodeptr;
void visit(int n,int h){
    printf("%d %d\n",n,h);
}
void findnote(BTNodeptr t,int num,int h){ // @@ [Logical error: This function performs a full tree search for each leaf node to find its height, which is highly inefficient and will produce incorrect output if duplicate values exist in the BST. The height should be tracked during the initial traversal.]
    if (t != NULL) 
    {
        if(t->data==num){
            visit(num,h);
        }
        findnote(t->lchild,num,h+1);
        findnote(t->rchild,num,h+1);
    }
}
void preorder(BTNodeptr tree,BTNodeptr orin)  // @@ [Logical error: Passing the original root 'orin' to 'findnote' for every leaf causes redundant searches. The height should be passed directly in the recursive calls instead of searching the tree again.]
{
    if (tree != NULL) 
    {
        if(tree->lchild==NULL && tree->rchild==NULL){
            findnote(orin,tree->data,1);
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