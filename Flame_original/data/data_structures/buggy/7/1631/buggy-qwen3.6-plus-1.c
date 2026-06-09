#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int num;
    int deep;
    struct tree *lchild;
    struct tree *rchild;
}TREE;
int n,i,a,cnt=0,flag=0;
TREE *list=NULL,*p=NULL,*q=NULL,*r=NULL;

void printleaf(TREE *point) {
    if(point->lchild!=NULL) printleaf(point->lchild);
    if(point->rchild!=NULL) printleaf(point->rchild);
    if(point->lchild==NULL && point->rchild==NULL) {
        printf("%d %d\n",point->num,point->deep);
    }
}

int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        p=(TREE *)malloc(sizeof(TREE));
        p->num=a;
        p->lchild=NULL;
        p->rchild=NULL;
        if(i==0) {
            q=list=p;
            p->deep=1;
        }
        else {
            r=q=list;
            cnt=1;
            while(q!=NULL) {
                if(q->num<a) { // @@ The condition should be q->num <= a to satisfy the problem requirement that the right child's value is greater than or equal to the root's value. Currently, equal values are incorrectly directed to the left subtree.
                    r=q;
                    q=q->rchild;
                    flag=1;
                    cnt++;
                }
                else {
                    r=q;
                    q=q->lchild;
                    flag=2;
                    cnt++;
                }
            }
            if(flag==1)r->rchild=p;
            else r->lchild=p;
            p->deep=cnt;
        }
    }
printleaf(list);
    return 0;
}