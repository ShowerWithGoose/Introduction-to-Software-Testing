#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node*lch;
 struct node*rch;
}tree,*ptree;
int i=1;
void qianxu(ptree t)
{
if(t==NULL) return; 


 else
 {
  if(t->rch==NULL&&t->lch==NULL)
  printf("%d %d\n",t->data,i);
  i++;
  qianxu(t->lch);
  qianxu(t->rch);
  i--;}
 
}
//13 50 38 30 64 58 40 10 73 70 50 60 100 35
int main()
{
 int n;
scanf("%d",&n);
int j=0;
int now;
ptree p=NULL;
ptree t=NULL;
scanf("%d",&now);
t=(ptree)malloc(sizeof(tree));
t->data=now;
t->lch=NULL;
t->rch=NULL;
ptree q=NULL;
for(j=1;j<n;j++)
{
 scanf("%d",&now);
 p=t;
 while(p!=NULL)
 {
  q=p;
  if(now>=p->data)
 p=p->rch;
 else p=p->lch;
 } 
 p=(ptree)malloc(sizeof(tree));//要用q存起来原本的节点，理解：因为p在遇到NULL要用p创造一个新的节点，所以要用q变换当前节点的选择位置 
  if(now>q->data)//仅仅知道了p是上一个的左右并且获得了p，但是最后申请新的节点的时候又会丢掉。 
 q->rch=p;
 else q->lch=p;
 p->data=now;
 p->lch=NULL;
 p->rch=NULL; 
}
p=t;
qianxu(t);
return 0;
}

