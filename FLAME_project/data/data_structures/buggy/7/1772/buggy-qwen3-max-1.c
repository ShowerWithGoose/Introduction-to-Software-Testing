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
    inorder(root);
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item) {
    h++;
    if(p == NULL) {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
        p->dep=h;
    } else if( item < p->data)
        p->left = insertBST(p->left, item);
    else if( item > p->data)
        p->right = insertBST(p->right,item);
    else; // @@ [The 'else' clause does nothing when item == p->data, so duplicate values are ignored and not inserted. However, according to the problem description, right child should be >= root, meaning duplicates should be inserted to the right. This causes the second '100' to be skipped, so the leaf node '100' is missing in output.]
    return p;
}
void  inorder(BTNodeptr t)
{
      if(t!=NULL){
             inorder(t->left);
             VISIT(t);       /* 访问T指结点  */
             inorder(t->right);
       }
}
void VISIT(BTNodeptr m)
{
    if((m->left==NULL)&&(m->right==NULL))
    printf("%d %d\n",m->data,m->dep);
}