#include <stdio.h>
typedef int Datatype;
struct node {
    Datatype data;
    struct node *left, *right;
    int dep;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item);
int h; // @@ Global variable h is misused for tracking node depth; depth should be passed recursively or calculated relative to parent.
int main() {
    int i, item;
    BTNodeptr  root=NULL;
    int n;
    scanf("%d",&n);
    for(i=0; i<n; i++) { //构造一个有10个元素的BST树
        h=0; // @@ Resetting global h to 0 for each insertion breaks depth calculation; h should not be global or reset here.
        scanf("%d", &item);
        root = insertBST(root, item);
    }
    inorder(root); // @@ Function 'inorder' is called before its declaration/definition, causing implicit declaration error.
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item) {
    h++; // @@ Incrementing global h on every recursive call incorrectly calculates depth; depth depends on tree structure, not call count.
    if(p == NULL) {
        p = (BTNodeptr)malloc(sizeof(BTNode)); // @@ Missing #include <stdlib.h> for malloc function.
        p->data = item;
        p->left = p->right = NULL;
        p->dep=h;
    } else if( item < p->data)
        p->left = insertBST(p->left, item);
    else if( item > p->data) // @@ Condition should be >= to insert duplicates to the right as per problem description.
        p->right = insertBST(p->right,item);
    else; // @@ Empty statement ignores duplicate values; should be removed or handled.
    return p;
}
void  inorder(BTNodeptr t)
{
      if(t!=NULL){
             inorder(t->left);
             VISIT(t);       /* 访问T指结点  */ // @@ Function 'VISIT' is called before its declaration/definition.
             inorder(t->right);
       }
}
void VISIT(BTNodeptr m)
{
    if((m->left==NULL)&&(m->right==NULL))
    printf("%d %d\n",m->data,m->dep);
}