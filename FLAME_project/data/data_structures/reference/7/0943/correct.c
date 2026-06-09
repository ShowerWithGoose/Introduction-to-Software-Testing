#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) (a>b?a:b)
typedef struct Node{
    int val;
    struct Node *lchild,*rchild;
}BTNode,*BTree;
BTree insertx(BTree p ,int x){
    if(p==NULL){
        p=(BTree)malloc(sizeof(BTNode));
        p->val=x;
        p->lchild=p->rchild=NULL;
    }
    else {
        if(x<p->val) p->lchild=insertx(p->lchild,x);
        else p->rchild=insertx(p->rchild,x);//相等的数也往右子树放。
    }
    return p;
}//使用时需要用p=insert(p,x);
int depth=0;//注意每求一个数都要把depth初始化一下；
void height_x(BTree t,int x,int dep){//求某个数的深度，这里考虑了多个重复的数的情况，如果不重复直接return就可以了
    if(t==NULL){
        return;
    }
    if(t->val==x){
        depth=max(depth,dep);
    }
    height_x(t->lchild,x,dep+1);
    height_x(t->rchild,x,dep+1);
}
BTree p=NULL;
void pre_order(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d ",t->val);
            depth=0;
            height_x(p,t->val,1);
            printf("%d\n",depth);
        }
        pre_order(t->lchild);
        pre_order(t->rchild);
    }
}
int main(){
    int n,m;
    scanf("%d ",&n);
    for(int i=1;i<=n;++i){
        scanf(" %d",&m);
        p=insertx(p,m);
    }
    pre_order(p);
    return 0;
}
