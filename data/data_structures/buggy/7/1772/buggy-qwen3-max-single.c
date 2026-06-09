#include <stdio.h>
typedef int Datatype;
struct node {
    Datatype data;
    struct node *left, *right;
    int dep;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item);
int h;
int main() {
    int i, item;
    BTNodeptr  root=NULL;
    int n;
    scanf("%d",&n);
    for(i=0; i<n; i++) { //构造一个有10个元素的BST树
        h=0;
        scanf("%d", &item);
        root = insertBST(root, item);
    }
    inorder(root); // @@ [Function 'inorder' is used but not declared before this point; missing function declaration or definition above main]
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item) {
    h++; // @@ [Global variable 'h' is used to track depth, but it's reset to 0 in main loop and incremented during recursive calls, which leads to incorrect depth calculation due to shared state across recursive branches]
    if(p == NULL) {
        p = (BTNodeptr)malloc(sizeof(BTNode)); // @@ [Missing #include <stdlib.h> for malloc; causes compilation error]
        p->data = item;
        p->left = p->right = NULL;
        p->dep=h;
    } else if( item < p->data)
        p->left = insertBST(p->left, item);
    else if( item > p->data)
        p->right = insertBST(p->right,item);
    else;
    return p;
}
void  inorder(BTNodeptr t) // @@ [Function 'inorder' is defined after being used in main without prior declaration; also, it doesn't pass height information correctly since height is stored in node's 'dep' field, but traversal doesn't update it properly due to flawed insertion logic]
{
      if(t!=NULL){
             inorder(t->left);
             VISIT(t);       /* 访问T指结点  */ // @@ [Function 'VISIT' is used but not declared before this point; missing function declaration]
             inorder(t->right);
       }
}
void VISIT(BTNodeptr m)
{
    if((m->left==NULL)&&(m->right==NULL))
    printf("%d %d\n",m->data,m->dep);
}