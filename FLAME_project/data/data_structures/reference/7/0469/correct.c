#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int num;
    struct node *lchild,*rchild;
} BTNode,*BTREE;
int a[1000];

void INSERTBST(BTREE *ptr,int item,int len)
{
    len++;
    if((*ptr)==NULL)
    {
        (*ptr)=(BTREE)malloc(sizeof(BTNode));
        (*ptr)->data=item;
        (*ptr)->num=len;
        (*ptr)->lchild=NULL;
        (*ptr)->rchild=NULL;
    }
    else if(item<(*ptr)->data)
        INSERTBST(&((*ptr)->lchild),item,len);
    else
        INSERTBST(&((*ptr)->rchild),item,len);
}
BTREE SORTTREE(int n)
{
    int len;
    BTREE T=NULL;
    struct node **ptr=&T;
    int i;
    if(n>0)
        for(i=0; i<n; i++)
        {
            len=0;
            INSERTBST(ptr,a[i],len);
        }
    return T;
}

void print(BTREE root)
{
    BTREE p=root;
    if(p)
    {
        if(!(p->lchild)&&!(p->rchild))
        {
            printf("%d %d\n",p->data,p->num);
        }
        print(p->lchild);
        print(p->rchild);
    }
}
int main()
{
    BTREE root;
    int i;
    int n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    root=SORTTREE(n);
    print(root);
    return 0;
}

