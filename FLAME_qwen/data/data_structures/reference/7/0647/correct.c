#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 1024

typedef struct BTREE
{
    int val;
    struct BTREE *lchild, *rchild;
}BTNode, *BTS;

BTS tree = NULL;

void INSERT(BTS *head, int value)
{
    if(*head==NULL)
    {
        *head = (BTS)malloc(sizeof(BTNode));
        (*head)->val = value;
        (*head)->lchild = NULL;
        (*head)->rchild = NULL;
    }
    else if((*head)->val > value)
        INSERT(&((*head)->lchild),value);
    else if((*head)->val <= value)
        INSERT(&((*head)->rchild),value);
} 

int DEP(BTS T, BTS q)
{
    BTS p = T;
    BTS STACK[110];
    int Flag[110];
    int flag;
    int top = -1;
    if(T!=NULL)
    {
        do
        {
            while(p!=NULL)
            {
                STACK[++top] = p;
                Flag[top] = 0;
                p = p->lchild;
            } 
            p = STACK[top];
            flag = Flag[top--];
            if(flag == 0)
            {
                STACK[++top] = p;
                Flag[top] = 1;
                p = p->rchild;
            }
            else if(flag==1)
            {
                if(p == q)
                    return top + 2;
                p = NULL;
            }
        }while(!(p==NULL && top==-1));
    }
}

void PreOrder(BTS p)
{
	if(p!=NULL)
	{
        int depth = 0;
        if(p->lchild==NULL && p->rchild==NULL)
        {
            depth = DEP(tree,p);
            printf("%d %d\n",p->val,depth);
        }
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

int main()
{
    tree = (BTS)malloc(sizeof(BTNode));
    int n; int value;
    scanf("%d",&n);
    scanf("%d",&value);
    tree->val = value;
    tree->lchild = NULL;
    tree->rchild = NULL;
    while(--n)
    {
        scanf("%d",&value);
        INSERT(&tree,value);
    }
    PreOrder(tree);
}
