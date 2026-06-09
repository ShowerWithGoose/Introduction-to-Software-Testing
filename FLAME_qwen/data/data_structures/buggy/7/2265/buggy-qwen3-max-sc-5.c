#include <stdio.h>
typedef int Datatype;
struct node {
    Datatype data;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item);
void f(BTNodeptr p,int height);
int main()
{
    int n;
    int i, item;
    BTNodeptr  root=NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++){ //构造一个有10个元素的BST树
         scanf("%d", &item);
         root =insertBST(root, item);
     }
     f(root,1);
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode)); @@ [Missing #include <stdlib.h> for malloc]
        p->data = item;
        p->left = p->right = NULL;
    } 
    else if(item < p->data)
        p->left = insertBST(p->left, item);
    else if( item > p->data)
       p->right = insertBST(p->right,item); @@ [BST insertion should allow duplicates on the right, but this skips equal items entirely, causing them to be ignored]
    return p;
} 
void f(BTNodeptr p,int height){
    if(p==NULL) return; @@ [Missing null check before accessing p->left and p->right, leading to segmentation fault when called on empty tree or during recursion]
    if(p->left==NULL&&p->right==NULL){
        printf("%d %d\n",p->data,height);
        return;
    }
     if(p->left!=NULL){
        f(p->left,height+1);
    }
    if(p->right!=NULL){
        f(p->right,height+1);
    }
}