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
    else; // @@ This line handles the case when item == p->data, but does nothing, causing duplicate values to be ignored. According to the problem, right child should be >= root, so duplicates should be inserted into the right subtree. The correct condition should be "else if (item >= p->data)" without the else clause.
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