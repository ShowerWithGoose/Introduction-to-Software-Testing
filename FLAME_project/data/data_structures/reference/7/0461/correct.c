#include<stdio.h>
struct node{
    int a;
    int high;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node *Tree;
Tree root=NULL;
typedef struct node tree;
void insertNode(int item,int th)
{
     Tree p,r;
     r=(Tree)malloc(sizeof(tree));
     r->high=th;
     r->a=item;
     r->lchild=NULL;
     r->rchild=NULL;
     if(root==NULL)
     {
         root=r;
     }
     else
     {
         p=root;
         while(1)
         {
             if(item<p->a)
             {
                 if(p->lchild==NULL)
                 {
                     r->high++;
                     p->lchild=r;

                     break;
                 }
                 else
                    {
                        r->high++;
                        p=p->lchild;
                    }
             }
             else if(item>p->a)
             {
                 if(p->rchild==NULL)
                 {
                     r->high++;
                     p->rchild=r;
                     break;
                 }
                 else
                    {
                        r->high++;
                        p=p->rchild;
                    }
             }
             else if(item==p->a)
             {
                 if(p->lchild==NULL)
                 {
                     r->high++;
                     p->rchild=r;
                     break;
                 }
                 else
                    {
                        r->high++;
                        p=p->rchild;
                    }
             }
         }
     }
 }
 void printNode(Tree q)
 {

     if(q!=NULL)
     {
         printNode(q->lchild);
         if(q->lchild==NULL&&q->rchild==NULL)
         {
             printf("%d %d\n",q->a,q->high);
         }
         printNode(q->rchild);
     }
}
int main()
{
    Tree q;
    int i,n,m=0,item;
    int th=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        insertNode(item,th);
    }
    q=root;
    printNode(q);
    return 0;
}



