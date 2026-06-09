#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct tree{
int data;
struct tree *lchild,*rchild;
} *btree,TREE;
void shuchu(btree a,int b);
btree t=NULL,p,q;
int main()
{
    int n,item;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&item);
           if(t==NULL)
           {
               t=(btree)malloc(sizeof(TREE));
               t->data=item;
               t->lchild=NULL;
               t->rchild=NULL;
           }
           else
           {
               q=t;
               while(q!=NULL)
               {
                   p=q;
                   if(item>=q->data)
                   q=q->rchild;
                   else
                   q=q->lchild;
               }
               q=(btree)malloc(sizeof(TREE));
               q->data=item;
               q->lchild=NULL;
               q->rchild=NULL;
               if(item>=p->data)
                p->rchild=q;
               else
               p->lchild=q;
           }
    }
    shuchu(t,1);
    destroy(t);
return 0;
}
void destroy(btree a)
{
    if(a!=NULL)
    {
        destroy(a->lchild);
        destroy(a->rchild);
        free(a);
    }
}
void shuchu(btree a,int b)
{
    if(a!=NULL)
    if(a->lchild==NULL&&a->rchild==NULL)
   {
       printf("%d %d\n",a->data,b);
   }
    else
    {
        shuchu(a->lchild,b+1);
        shuchu(a->rchild,b+1);
    }
}




