#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int high;
    struct node *lchild,*rchild;
}BNode,*BNodeptr;
int height=0;
int isleaf(BNodeptr p){
    if(p->lchild==NULL&&p->rchild==NULL)
        return 1;
    else return 0;
}
void order(BNodeptr p){
    if(p!=NULL)
    {
        if(isleaf(p))
            printf("%d %d\n",p->data,p->high);
        order(p->lchild);
        order(p->rchild);
    }
}
BNodeptr insertBST(BNodeptr p,int item){
    height++;
    if(p==NULL)
    {
        p=(BNodeptr)malloc(sizeof(BNode));
        p->data=item;
        p->high=height;
        p->lchild=NULL, p->rchild=NULL;
    }
    else if(item<p->data)
        p->lchild=insertBST(p->lchild,item);
    else if(item>=p->data)
        p->rchild=insertBST(p->rchild,item);
    return p;
}
int main(){
    int i,item;
    BNodeptr root=NULL;
    scanf("%d",&i);
    for(;i>0;i--)
    {
        height=0;
        scanf("%d",&item);
        root=insertBST(root,item);
    }
    order(root);
    return 0;
}
