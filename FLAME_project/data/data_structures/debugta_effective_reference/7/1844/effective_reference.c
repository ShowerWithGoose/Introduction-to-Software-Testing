#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) (a>b?a:b)
typedef struct Node{
    int val;
    struct Node *lchild,*rchild;
}BTNode,*BTree;
BTree insertx(BTree root ,int x){
    if(root==NULL){
        root=(BTree)malloc(sizeof(BTNode));
        root->val=x;
        root->lchild=root->rchild=NULL;
    }
    else {
        if(x<root->val) root->lchild=insertx(root->lchild,x);
        else root->rchild=insertx(root->rchild,x);//相等的数也往右子树放。
    }
    return root;
}//使用时需要用p=insert(p,x);
int high=0;//注意每求一个数都要把depth初始化一下；
void height_x(BTree t,int x,int dep){//求某个数的深度，这里考虑了多个重复的数的情况，如果不重复直接return就可以了
    if(t==NULL){
        return;
    }
    if(t->val==x){
        high=max(high,dep);
    }
    height_x(t->lchild,x,dep+1);
    height_x(t->rchild,x,dep+1);
}
BTree root=NULL;
void pre_order(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d ",t->val);
            high=0;
            height_x(root,t->val,1);
            printf("%d\n",high);
        }
        pre_order(t->lchild);
        pre_order(t->rchild);
    }
}
int main(){
    int n,x;
    scanf("%d ",&n);
    for(int i=1;i<=n;++i){
        scanf(" %d",&x);
        root=insertx(root,x);
    }
    pre_order(root);
    return 0;
}
