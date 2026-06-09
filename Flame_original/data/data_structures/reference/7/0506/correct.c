#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    int height;
    struct node *lchild, *rchild;
}BTNode, *BTNodeptr;

BTNodeptr BTinsert(BTNodeptr t, int val, int height);   //要用作递归的函数都不能设为void型
void inorder(BTNodeptr t);

int main()
{
    int n, val, height=1;
    BTNodeptr root=NULL;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &val);
        root=BTinsert(root, val, height);//若root=NULL，在这里更新root
    }
    inorder(root);
    return 0;
}

BTNodeptr BTinsert(BTNodeptr t, int val, int height)
{
    if(t==NULL)
    {
        t=(BTNodeptr)malloc(sizeof(BTNode));
        t->val=val; t->height=height;
        t->lchild=t->rchild=NULL;
    }
    else if(val<t->val)
        t->lchild=BTinsert(t->lchild, val, height+1);   //曾错 通过《赋值》的方式，更新并malloc新节点的位置
    else if(val>=t->val)
        t->rchild=BTinsert(t->rchild, val, height+1);   //若t->rchild!=NULL还好说，否则，这样的操作可以起到赋予空间的作用
    return t;
}

void inorder(BTNodeptr t)
{
    if(t)
    {
        inorder(t->lchild);
        if(!t->lchild && !t->rchild)
            printf("%d %d\n", t->val, t->height);
        inorder(t->rchild);
    }
    return;
}

