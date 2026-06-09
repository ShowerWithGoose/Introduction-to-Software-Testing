#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *lchild,*rchild;
    int h;
}*Btree;
Btree Sorttree(int a[],int n);
void InsertBST(Btree* T,int item);
void InOrder(Btree T);
int main()
{
    int a[105]={0};
    int n,i=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    Btree T= Sorttree(a,n);
    InOrder(T);
    return 0;
}
Btree Sorttree(int a[],int n)
{
    Btree T=NULL;
    int i;
    if(n>0)
    {
        for(i=0;i<n;i++)
        InsertBST(&T,a[i]);
    }
    return T;
}
void InsertBST(Btree* T,int item)
{
    Btree p,q;
    p=(Btree)malloc(sizeof(struct node));
    p->data=item;
    p->lchild=NULL;
    p->rchild=NULL;
    p->h=1;
    if(*T==NULL)
    *T=p;
    else
    {
        q=*T;
        while(1)
        {
            if(item<q->data)
            {
                p->h++;
                if(q->lchild!=NULL)
                {
                    q=q->lchild;
                }
                else
                {
                    q->lchild=p;
                    break;
                }
            }
            else
            {
                p->h++;
                if(q->rchild!=NULL)
                {
                    q=q->rchild;
                }
                else
                {
                    q->rchild=p;
                    break;
                }
            }
        }
    }
}
void InOrder(Btree T)
{
    if(T!=NULL)
    {
        InOrder(T->lchild);
        if(T->lchild==NULL&&T->rchild==NULL)
        {
            printf("%d ",T->data);
            printf("%d\n",T->h);
        }
        InOrder(T->rchild);
    }
}
