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
        find(t->lchild,depth++); // @@ depth++ evaluates to the current depth value before incrementing, so the recursive call receives the wrong depth. It should be depth + 1.
    }
    if(t->rchild!=NULL)
    {
        find(t->rchild,depth++); // @@ depth++ evaluates to the current depth value before incrementing, so the recursive call receives the wrong depth. It should be depth + 1.
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