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
if(p->h>1000)p->h=1; // @@ Error: p->h is uninitialized when p is newly created; this condition is meaningless and does not set the initial height to 1 as required (root height should be 1)
}
else if (item < p->data){
p->lchild = insertBST(p->lchild, item);
p->lchild->h=p->h+1;} // @@ Error: p->h is uninitialized for the root node, leading to undefined behavior; also, the height should be passed recursively, not set after insertion
else if (item >= p->data){
p->rchild = insertBST(p->rchild, item);
p->rchild->h=p->h+1;} // @@ Error: Same issue as above; height is not properly initialized or propagated
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