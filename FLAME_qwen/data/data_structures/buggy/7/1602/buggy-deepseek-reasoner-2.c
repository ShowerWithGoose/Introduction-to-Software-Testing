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
if(p->h>1000)p->h=1; // @@ 错误：p->h未初始化，条件无意义；应直接设置p->h为1（根节点高度）或传入高度参数
}
else if (item < p->data){
p->lchild = insertBST(p->lchild, item);
p->lchild->h=p->h+1;} // @@ 错误：p->h可能未正确初始化，且递归插入时子节点高度应通过参数传递，而非事后赋值
else if (item >= p->data){
p->rchild = insertBST(p->rchild, item);
p->rchild->h=p->h+1;} // @@ 错误：同上，高度计算逻辑错误
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