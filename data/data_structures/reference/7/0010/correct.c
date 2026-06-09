#include<stdio.h>
#include<stdlib.h>

typedef struct btree{
    int data;
    struct btree *lchild,*rchild;
}BTREE;

BTREE* createB(BTREE *T,int n)
{
    int i,m;
    BTREE *p,*q;
    for(i=0;i<n;++i)
    {
        p=(BTREE*)malloc(sizeof(T));
        scanf("%d",&m);
        p->data=m;
        p->lchild=NULL;
        p->rchild=NULL;
        if(T==NULL)
            T=p;
        else
        {
            q=T;
            while(1)
                if(p->data<q->data)
                    if(q->lchild!=NULL)
                        q=q->lchild;
                    else
                    {
                        q->lchild=p;
                        break;
                    }
                else
                    if(q->rchild!=NULL)
                        q=q->rchild;
                    else
                    {
                        q->rchild=p;
                        break;
                    }
        }
    }
    return T;
}

void travelB(BTREE *T,int n)
{
    int top=-1,flag,stock2[n];
    BTREE *stock[n],*p;
    p=T;
    do
    {
        while(p!=NULL)
        {
            stock[++top]=p;
            stock2[top]=0;
            p=p->lchild;
        }
        p=stock[top];
        flag=stock2[top--];
        if(flag==0)
        {
            stock[++top]=p;
            stock2[top]=1;
            p=p->rchild;
        }
        else
        {
            if(p->lchild==NULL && p->rchild==NULL)
                printf("%d %d\n",p->data,top+2);
            p=NULL;
        }
    }while(p!=NULL || top!=-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    BTREE *T=NULL;
    T=createB(T,n);
    travelB(T,n);
    return 0;
}


