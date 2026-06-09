#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int depth;
    struct node *lchild,*rchild;
} Tree,*Treep;
Treep root=NULL;
void VISIT(Treep t);
void inorder(Treep t);
void Insert(Treep *t,int data,int depth);
int main()
{
    int n,d,i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&d);
        Insert(&root,d,1);
    }
    inorder(root);
    return 0;
}
void VISIT(Treep t)
{
    printf("%d %d\n",t->data,t->depth);
}
void inorder(Treep t)
{
    if(t!=NULL)
    {
        inorder(t->lchild);
        if(t->lchild==NULL&&t->rchild==NULL)
        {
            VISIT(t);
        }
        inorder(t->rchild);
    }
}
void Insert(Treep *t,int data,int depth)
{
    if(*t==NULL)
    {
        *t=(Treep)malloc(sizeof(Treep));
        (*t)->lchild=NULL;
        (*t)->rchild=NULL;
        (*t)->data=data;
        (*t)->depth=depth;
    }
    else if(data<((*t)->data))
    {
        Insert(&((*t)->lchild),data,depth+1);
    }
    else
    {
        Insert(&((*t)->rchild),data,depth+1);
    }
}

