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
if(p->h>1000)p->h=1; // @@ [Uninitialized variable: p->h is used before being assigned a valid initial value. When p is newly allocated, p->h contains garbage. The condition `if(p->h>1000)` is meaningless and does not set h to 1 in the normal case. The root height should be initialized properly, e.g., to 1, but this code fails to do so.]
}
else if (item < p->data){
p->lchild = insertBST(p->lchild, item);
p->lchild->h=p->h+1;} // @@ [Potential null pointer dereference: if insertBST returns NULL (which it shouldn't in this logic, but more critically, p->h may be uninitialized if parent's h was never set), then p->lchild->h assignment is invalid. Also, the height propagation assumes p->h is valid, but root's h is never initialized correctly.]
else if (item >= p->data){
p->rchild = insertBST(p->rchild, item);
p->rchild->h=p->h+1;} // @@ [Same issue as above: relies on p->h being correctly set, which it isn't for the root or any node due to missing initialization.]
else{
    
}

 //树中存在该元素 
 return p;
}

void blBST(BTNodeptr p){
    if(p!=NULL){
        if(p->lchild==NULL&&p->rchild==NULL){
            printf("%d %d\n",p->data,p->h); // @@ [p->h may be uninitialized or contain garbage because node heights are never properly initialized during insertion, leading to incorrect or undefined output for leaf heights.]
            
        }
        blBST(p->lchild);
        blBST(p->rchild);
        
    }
}