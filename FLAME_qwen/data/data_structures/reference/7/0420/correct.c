#include<stdio.h>
#include<stdlib.h>
typedef struct BTtree
{
    int data;
    struct BTtree *lchild,*rchild;
}BTNode,*BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,int item)
{
    if(p==NULL)
    {
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=item;
        p->lchild=p->rchild=NULL;
    }
    else if(item<p->data)
    {
        p->lchild=insertBST(p->lchild,item);
    }
    else
    {
        p->rchild=insertBST(p->rchild,item);
    }
    return p;
}
void visit(int data,int hight)
{
    printf("%d %d\n",data,hight);
}
void PreOrderTraverse(BTNodeptr T,int hight)
{
    if(T)
    {
        if(T->lchild==NULL&&T->rchild==NULL)
        {
            visit(T->data,hight);
        }
        PreOrderTraverse(T->lchild,hight+1);
        PreOrderTraverse(T->rchild,hight+1);
    }
}
int main()
{
    BTNodeptr p=NULL;
    int n,i,data,hight=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        p=insertBST(p,data);
    }
    PreOrderTraverse(p,hight);
    return 0;
}

