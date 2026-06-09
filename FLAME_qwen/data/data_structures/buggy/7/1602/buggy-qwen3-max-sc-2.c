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
if(p->h>1000)p->h=1; // @@ [Uninitialized read: p->h is used before being initialized. When a new node is created, h should be set to the correct height (e.g., 1 for root), but here it's left uninitialized and then conditionally assigned only if >1000, which is undefined behavior.]
}
else if (item < p->data){
p->lchild = insertBST(p->lchild, item);
p->lchild->h=p->h+1;} // @@ [Incorrect height propagation: The height of the child is set after recursive insertion, but if the child was just created in the recursive call, its h is uninitialized. Also, this assignment assumes p->h is already valid, which may not be true if p itself had uninitialized h.]
else if (item >= p->data){
p->rchild = insertBST(p->rchild, item);
p->rchild->h=p->h+1;} // @@ [Same issue as above: p->h might be uninitialized, and child's h is set after creation without ensuring parent's h is valid.]
else{
    
}

 //树中存在该元素 
 return p;
}

void blBST(BTNodeptr p){
    if(p!=NULL){
        if(p->lchild==NULL&&p->rchild==NULL){
            printf("%d %d\n",p->data,p->h); // @@ [p->h may be uninitialized or incorrect due to errors in insertBST, leading to wrong or garbage height output.]
            
        }
        blBST(p->lchild);
        blBST(p->rchild);
        
    }
}