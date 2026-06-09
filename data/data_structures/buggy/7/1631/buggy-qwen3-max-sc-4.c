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
                if(q->num<a) {
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
            if(flag==1)r->rchild=p; // @@ [The 'flag' variable is not reset between insertions, so it retains its value from previous iterations, causing incorrect assignment to left or right child.]
            else r->lchild=p;
            p->deep=cnt;
        }
    }
printleaf(list);
    return 0;
}