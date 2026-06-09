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
        h=0; // @@ Logical error: resetting global height counter for each insertion prevents correct depth tracking.
        scanf("%d", &item);
        root = insertBST(root, item);
    }
    inorder(root); // @@ Compilation error: function 'inorder' is called before its declaration.
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item) {
    h++; // @@ Logical error: incrementing global 'h' on every recursive call incorrectly computes node depth.
    if(p == NULL) {
        p = (BTNodeptr)malloc(sizeof(BTNode)); // @@ Compilation error: 'malloc' is undeclared, missing #include <stdlib.h>.
        p->data = item;
        p->left = p->right = NULL;
        p->dep=h;
    } else if( item < p->data)
        p->left = insertBST(p->left, item);
    else if( item > p->data) // @@ Logical error: condition should be 'item >= p->data' to place duplicates in the right subtree as per problem statement.
        p->right = insertBST(p->right,item);
    else; // @@ Logical error: empty statement ignores duplicate values instead of inserting them.
    return p;
}
void  inorder(BTNodeptr t) // @@ Compilation error: function defined after use without prior forward declaration.
{
      if(t!=NULL){
             inorder(t->left);
             VISIT(t);       /* 访问T指结点  */ // @@ Compilation error: function 'VISIT' is called before its declaration.
             inorder(t->right);
       }
}
void VISIT(BTNodeptr m)
{
    if((m->left==NULL)&&(m->right==NULL))
    printf("%d %d\n",m->data,m->dep);
}