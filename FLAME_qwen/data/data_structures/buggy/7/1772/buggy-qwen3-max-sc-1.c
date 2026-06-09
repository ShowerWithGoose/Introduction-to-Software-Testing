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
    inorder(root); // @@ [function 'inorder' is used but not declared before use; missing function declaration]
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item) {
    h++;
    if(p == NULL) {
        p = (BTNodeptr)malloc(sizeof(BTNode)); // @@ [missing #include <stdlib.h> for malloc()]
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
void  inorder(BTNodeptr t) // @@ [function 'inorder' is defined after use and without prior declaration]
{
      if(t!=NULL){
             inorder(t->left);
             VISIT(t);       /* 访问T指结点  */ // @@ [function 'VISIT' is used but not declared before use]
             inorder(t->right);
       }
}
void VISIT(BTNodeptr m) // @@ [function 'VISIT' is defined after use and without prior declaration]
{
    if((m->left==NULL)&&(m->right==NULL))
    printf("%d %d\n",m->data,m->dep);
}