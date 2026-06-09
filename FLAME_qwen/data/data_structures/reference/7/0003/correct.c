#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct tree {
    int num;
    int depth;
    struct tree *rchild,*lchild;   
}*head=NULL,*p=NULL,*pb;
int x;
int N,n;

void print_tree(struct tree *q){
    if (q->lchild!=NULL||q->rchild!=NULL)
    {
        if(q->lchild!=NULL)print_tree(q->lchild);
        if(q->rchild!=NULL)print_tree(q->rchild);
    }
    else printf("%d %d\n",q->num,q->depth);
}

int main(){
    scanf("%d",&n);
    head=(struct tree*)malloc(sizeof(struct tree));
    scanf("%d",&head->num);
    head->depth = 1;
    n--;
    while (n>0)
    {
        scanf("%d",&x);
        for (p = pb = head,N=1; p!=NULL; N++){
            pb = p;
            if (x<p->num)p=p->lchild;
            else p=p->rchild;
        }
        p=(struct tree*)malloc(sizeof(struct tree));
        p->num=x;
        p->depth=N;
        if (x<pb->num)pb->lchild=p;
        else pb->rchild=p;
        n--;
    }
    print_tree(head);
}
