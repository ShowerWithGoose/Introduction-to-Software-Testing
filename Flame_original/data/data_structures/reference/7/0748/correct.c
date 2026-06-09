#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
    int height;
    int data;
    struct node *lchild,*rchild;
}BTnode,*BTnodeptr;

BTnodeptr insert(BTnodeptr p,int item,int height){
    if(p==NULL){
        p=(BTnodeptr)malloc(sizeof(BTnode));
        p->data=item;
        p->lchild=NULL;
        p->rchild=NULL;
        p->height=height;
    }
    else if(item<p->data){
        p->lchild=insert(p->lchild,item,height+1);

    }
    else if(item>=p->data){
        p->rchild=insert(p->rchild,item,height+1);
    }
    return p;
}
void print(BTnodeptr root){
    if(root!=NULL){
        print(root->lchild);
        if(root->lchild==NULL&&root->rchild==NULL){
            printf("%d %d\n",root->data,root->height);
        }
        print(root->rchild);
    }
}
int main()
{
    int num=0,i=0,r=0;
    int item=0;
    BTnodeptr root=NULL,*p;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&item);
        root=insert(root,item,1);
    }
    print(root);
    return 0;
}

