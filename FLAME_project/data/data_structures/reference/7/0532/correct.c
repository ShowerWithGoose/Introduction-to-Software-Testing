#include <stdio.h>
#include <stdlib.h>
typedef struct node{
int num;
int high;
struct node *lchild;
struct node *rchild;
}tree;
void pushn(tree *q,tree *p){
q->high=p->high+1;
if(q->num<p->num)
{
if(p->lchild==NULL)
p->lchild=q;
else
pushn(q,p->lchild);
}
else
{
if(p->rchild==NULL)
p->rchild=q;
else
pushn(q,p->rchild);
}
return;
}
void first(tree *p){
if(p->lchild==NULL&&p->rchild==NULL)
printf("%d %d\n",p->num,p->high);
else
{
if(p->lchild!=NULL)
first(p->lchild);
if(p->rchild!=NULL)
first(p->rchild);
}
return;
}
int main(){
int n,a;
scanf("%d",&n);
scanf("%d",&a);
tree *head=(tree *)malloc(sizeof(tree)),*q;
head->num=a;
head->high=1;
head->lchild=NULL;
head->rchild=NULL;
for(int i=1;i<n;i++)
{scanf("%d",&a);
q=(tree *)malloc(sizeof(tree));
q->num=a;
q->lchild=NULL;
q->rchild=NULL;
pushn(q,head);
}
first(head);
return 0;

}



