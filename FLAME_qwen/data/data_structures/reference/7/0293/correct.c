#include<stdio.h>
#include<stdlib.h>
#define MAX 64
typedef struct{//定义节点
    int value;
    int layer;
    struct node *lchild;
    struct node *rchild;
}node;

node *createnode(node *r,int i,int array[]){//新建节点
    r = (node *)malloc(sizeof(node));
    r->value = array[i];
    r->layer = 1;
    r->lchild = NULL;
    r->rchild = NULL;
    return r;
}

void insert(node *branch,node *leaf){//插入节点
    while(1){
        if (leaf->value < branch->value){
            if (branch->lchild == NULL){
                branch->lchild = leaf;
                leaf->layer++;
                break;
            }
            else {
                branch = branch->lchild;
                leaf->layer += 1;
            }
        }
        else {
            if (branch->rchild == NULL){
                branch->rchild = leaf;
                leaf->layer++;
                break;
            }
            else {
                branch = branch->rchild;
                leaf->layer += 1;
            }
        }
    }
}

void in_order(node *n){//中序遍历并打印叶节点，使用非递归算法，参考课本
    node *stack[MAX];
    node *p = n;
    int top = -1;
    if(n != NULL){
        do{
            while(p != NULL){
                stack[++top] = p;
                p = p->lchild;
            }
            p = stack[top--];
            if(p->lchild == NULL &&p->rchild == NULL){
                printf("%d %d\n",p->value,p->layer);
            }
            p = p->rchild;
        }while(p != NULL || top != -1);
    }
}

int main(){
    int cnt = 0,i = 0;
    int num[MAX] = {};
    node *r = NULL,*p = NULL,*bstree = NULL; 
    scanf("%d",&cnt);
    for (;i < cnt;i++){
        scanf("%d",&num[i]);
    }
    for (i = 0;i < cnt;i++){
        r = createnode(r,i,num);
        if (bstree == NULL){
            p = bstree = r;
        }
        else {
            p = bstree;
            insert(p,r);
        }
    }
    in_order(bstree);
    return 0;
}


