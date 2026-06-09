#include <stdio.h>
#include <stdlib.h>
typedef struct p{
    int d;
    int f;
    struct p *lchild,*rchild;
}*btr,btrnode;
btr insertbst(btr,int,int);
void leaf(btr);
int main()
{
    int n,i,x;
    btr t=NULL;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        t=insertbst(t,x,0);
    }
    leaf(t);
    return 0;
}
btr insertbst(btr t,int x,int fl)
{
      if(t==NULL){
        t=(btr)malloc(sizeof(btrnode));
        t->d=x;
        t->f=fl+1;
        t->lchild=NULL;
        t->rchild=NULL;}
      else{
      if(x<t->d)
            t->lchild=insertbst(t->lchild,x,fl+1);
      if(x>=t->d)
            t->rchild=insertbst(t->rchild,x,fl+1);
      }
      return t;
}
void leaf(btr t)
{
    if(t!=NULL){
        leaf(t->lchild);
        if(t->lchild==NULL&&t->rchild==NULL)
            printf("%d %d\n",t->d,t->f);
        leaf(t->rchild);
    }
}

