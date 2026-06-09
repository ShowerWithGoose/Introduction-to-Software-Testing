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
if(p->h>1000)p->h=1; // @@ [The 'h' field is uninitialized, so checking if it's >1000 is meaningless. The root height should be set to 1 here.]
}
else if (item < p->data){
p->lchild = insertBST(p->lchild, item);
p->lchild->h=p->h+1;} // @@ [If p->h was never initialized (e.g., for root), then p->h+1 is undefined behavior. Also, this assignment assumes parent's height is already correct, which may not be true during insertion.]
else if (item >= p->data){
p->rchild = insertBST(p->rchild, item);
p->rchild->h=p->h+1;} // @@ [Same issue as above: relies on parent's uninitialized or incorrect height.]
else{
    
}

 //树中存在该元素 
 return p;
}

void blBST(BTNodeptr p){
    if(p!=NULL){
        if(p->lchild==NULL&&p->rchild==NULL){
            printf("%d %d\n",p->data,p->h); // @@ [Since node heights are not correctly initialized or propagated, leaf nodes may have incorrect or garbage height values (e.g., 0 instead of 1 for single-node tree).]
            
        }
        blBST(p->lchild);
        blBST(p->rchild);
        
    }
}