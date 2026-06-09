/*
 * @Author:
 * @Date: 2022-05-05 22:37:16
 * @LastEditors:
 * @LastEditTime: 2022-05-06 09:41:16
 * @FilePath: \c_code\shujujiegou\p5\1.c
 * @Description: ??????,???`customMade`, ??koroFileHeader???? ????: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int Datatype;
// int depth=1;
struct TreeNode
{
    Datatype data;
    struct TreeNode *lchild,*rchild;
};
typedef struct TreeNode BTNode,*BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,Datatype item){
    if(p==NULL){
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=item;
        p->lchild=p->rchild=NULL;//???????
    }
    else if(item <p->data)
    p->lchild=insertBST(p->lchild,item);
    else if(item>=p->data)
    p->rchild=insertBST(p->rchild,item);
//    else 
//    printf("It have appeared!");
    return p;
}
void preOrder(BTNodeptr t,int depth){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,depth);
        }
        preOrder(t->lchild,depth+1);
        preOrder(t->rchild,depth+1);
    }
}

int main(){
    int Queue[500]={};
    int front=0,end=0;//???????
    int n,i,j,k;
    int item;
    int depth=1;
    scanf("%d",&n);
    BTNodeptr root=NULL;
    for(i=0;i<n;i++){
        scanf("%d",&item);
        root=insertBST(root,item);
    }
    preOrder(root,1);
}

