#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct tree{
int data;
struct tree *lchild,*rchild;
} *btree,TREE;
void shuchu(btree a,int b);
btree p=NULL,p,q;
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
           if(p==NULL)
           {
               p=(btree)malloc(sizeof(TREE));
               p->data=a;
               p->lchild=NULL;
               p->rchild=NULL;
           }
           else
           {
               q=p;
               while(q!=NULL)
               {
                   p=q;
                   if(a>=q->data)
                   q=q->rchild;
                   else
                   q=q->lchild;
               }
               q=(btree)malloc(sizeof(TREE));
               q->data=a;
               q->lchild=NULL;
               q->rchild=NULL;
               if(a>=p->data)
                p->rchild=q;
               else
               p->lchild=q;
           }
    }
    shuchu(p,1);
    destroy(p);
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




