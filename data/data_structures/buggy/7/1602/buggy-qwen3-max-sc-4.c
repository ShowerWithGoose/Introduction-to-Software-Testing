#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Datatype;
struct node{
Datatype data;
struct node *lchild, *rchild;
int h;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p, Datatype item);
void blBST(BTNodeptr p);

int main(){
int i, item;
int n;
scanf("%d",&n);
BTNodeptr root = NULL;
for (i = 0; i < n; i++)
{ //构造一个有10个元素的BST树
scanf("%d", &item);
root = insertBST(root, item);
}
blBST(root);

return 0;
}

BTNodeptr insertBST(BTNodeptr p, Datatype item)
{
if (p == NULL)
{
p = (BTNodeptr)malloc(sizeof(BTNode));
p->data = item;
p->lchild = p->rchild = NULL;
if(p->h>1000)p->h=1; // @@ [Uninitialized variable: p->h is used before being assigned a valid initial value. When p is newly allocated, p->h contains garbage. The condition `if(p->h>1000)` is meaningless and does not set h to 1 in the normal case. The root height should be initialized properly (e.g., to 1 when inserting at root level).]
}
else if (item < p->data){
p->lchild = insertBST(p->lchild, item);
p->lchild->h=p->h+1;} // @@ [Incorrect height propagation: This assumes p->h is already correctly set, but if p was just created in a deeper recursive call without proper h initialization, this will propagate garbage. Also, height should be passed during insertion, not set after returning from recursion.]
else if (item >= p->data){
p->rchild = insertBST(p->rchild, item);
p->rchild->h=p->h+1;} // @@ [Same issue as above: relies on p->h being correct, which it may not be due to missing initialization in the base case.]
else{
    
}

 //树中存在该元素 
 return p;
}

void blBST(BTNodeptr p){
    if(p!=NULL){
        if(p->lchild==NULL&&p->rchild==NULL){
            printf("%d %d\n",p->data,p->h);
            
        }
        blBST(p->lchild);
        blBST(p->rchild);
        
    }
}