#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct BiTNode  
{
   int data;
   struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
int depth=1;
//添加元素到树里面
void add(BiTree *t,int data)
{
    if(*t==NULL)
    {
        *t=(BiTree)malloc(sizeof(BiTNode));
        (*t)->data=data;
        (*t)->lchild=NULL;
        (*t)->rchild=NULL;
    }    
    else
    {
        if(data<(*t)->data)
        {
            add(&(*t)->lchild,data);
            
        }
        else
        {
            add(&(*t)->rchild,data);
        }
    }
} 

//找到叶结点 
void find(BiTree t,int depth)
{
    if(t->lchild!=NULL)
    {
        find(t->lchild,depth++); // @@ [Using post-increment (depth++) passes the original value of depth to the recursive call, so the child node receives the same depth as the parent. Should use pre-increment (++depth) or pass depth+1.]
    }
    if(t->rchild!=NULL)
    {
        find(t->rchild,depth++); // @@ [Same issue: post-increment does not increase depth before passing to the function. This causes incorrect height calculation for right subtree nodes.]
    }
    if(t->lchild==NULL && t->rchild==NULL)
    {
        printf("%d %d\n",t->data,depth);
    }
}
 
void PreOrderTraverse(BiTree t)
{ 
    if(t==NULL)
        return;
    printf("%d ",t->data);
    PreOrderTraverse(t->lchild); 
    PreOrderTraverse(t->rchild); 
}

int main()
{
    BiTree t;
    t=NULL;
    int num,n,i;
    scanf("%d",&num);
    for (i=0;i<num;i++)
    {
        scanf("%d",&n);
        add(&t,n);
    }
    find(t,1);
//    PreOrderTraverse(t);

    return 0;
}