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
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
    } 
    else if(item < p->data)
        p->left = insertBST(p->left, item);
    else if( item > p->data) // @@ Error: The condition should be `item >= p->data` to handle duplicate values correctly. The problem states that right child values are greater than or equal to the root, so equal values should go to the right subtree. With `item > p->data`, the duplicate value 100 is not inserted, causing the leaf node 100 to be missing from the output.
       p->right = insertBST(p->right,item);
    return p;
} 
void f(BTNodeptr p,int height){
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