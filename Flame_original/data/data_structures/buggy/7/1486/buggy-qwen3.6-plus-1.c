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
        find(t->lchild,depth++); // @@ depth++ is post-increment, it passes the current depth value to the recursive call instead of depth+1, causing incorrect height calculation.
    }
    if(t->rchild!=NULL)
    {
        find(t->rchild,depth++); // @@ Same issue: post-increment passes the wrong depth value. Should be depth+1 to correctly propagate the height.
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