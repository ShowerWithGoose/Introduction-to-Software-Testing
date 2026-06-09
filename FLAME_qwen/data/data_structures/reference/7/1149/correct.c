#include <stdio.h>
#include <stdlib.h>

typedef struct BIT
{
    int ele;
    int high;
    struct BIT *lchild,*rchild;
}BIT;

typedef struct BIT *bitree;

int createtree(bitree L,int input)
{
    int j=0;
    int height=1;
    bitree p,s;
    p=L;
    while(j==0)
    {
        if(input>=((p)->ele))
        {
            if((p->rchild)!=NULL)
            {
                p=p->rchild;
                height++;
            }
            else
            {
                s=(BIT *)malloc(sizeof(BIT));
                p->rchild=s;
                s->ele=input;
                s->high=height+1;
                p=s;
                s->lchild=NULL;
                s->rchild=NULL;
                return 0;
            }
        }
        else
        {
            if((p->lchild)!=NULL)
            {
                p=p->lchild;
                height++;
            }
            else
            {
                s=(BIT *)malloc(sizeof(BIT));
                p->lchild=s;
                s->ele=input;
                s->high=height+1;
                p=s;
                s->lchild=NULL;
                s->rchild=NULL;
                return 0;
            }
        }
    }
}

void searchleaf(BIT *L)
{
    bitree p;
    p=L;
    if(p)
    {
        searchleaf(p->lchild);
        if(p->lchild==NULL && p->rchild==NULL)
        {
            printf("%d %d\n",p->ele,p->high);
        }
        searchleaf(p->rchild);
    }
}

int main()
{
    int number,input,i;
    scanf("%d",&number);
    scanf("%d",&input);
    bitree L;
    L=(BIT *)malloc(sizeof(BIT));
    L->ele=input;
    L->lchild=NULL;
    L->rchild=NULL;
    L->high=1;
    for(i=0;i<number-1;i++)
    {
        scanf("%d",&input);
        createtree(L,input);
    }
    searchleaf(L);
}


