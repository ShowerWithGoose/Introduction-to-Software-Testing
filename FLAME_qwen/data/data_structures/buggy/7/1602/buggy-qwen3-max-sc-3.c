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
if(p->h>1000)p->h=1; // @@ [Uninitialized read: p->h is used before being initialized. When a new node is created, h should be set to the correct height (e.g., passed as a parameter), but here it's uninitialized and then conditionally assigned only if >1000, which leads to undefined behavior.]
}
else if (item < p->data){
p->lchild = insertBST(p->lchild, item);
p->lchild->h=p->h+1;} // @@ [Incorrect height propagation: The height of the child is set after the recursive call, but the parent's height may not be correctly set (especially if parent was just created and h is uninitialized). Also, this approach fails when duplicates are inserted via >=, and more critically, the root's height is never initialized to 1.]
else if (item >= p->data){
p->rchild = insertBST(p->rchild, item);
p->rchild->h=p->h+1;} // @@ [Same issue as above: relies on p->h being valid, but root and intermediate nodes may have uninitialized h.]
else{
    
}

 //树中存在该元素 
 return p;
}

void blBST(BTNodeptr p){
    if(p!=NULL){
        if(p->lchild==NULL&&p->rchild==NULL){
            printf("%d %d\n",p->data,p->h); // @@ [May print garbage height because h was never properly initialized for many nodes, especially the root.]
            
        }
        blBST(p->lchild);
        blBST(p->rchild);
        
    }
}