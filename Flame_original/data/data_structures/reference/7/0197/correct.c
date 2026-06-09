#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//二叉树
struct TreeNode
{
    int data;
    struct TreeNode *Lchild, *Rchild;
};
typedef struct TreeNode BTNode, *BTNodeptr;
//销毁
void destroyBT(BTNodeptr p)
{
    if (p != NULL)
    {
        destroyBT(p->Lchild);
        destroyBT(p->Rchild);
        free(p);
        p = NULL;
    }
}
//遍历
void preorder(BTNodeptr t, int depth)
{

    if (t != NULL)
    {
        if (t->Lchild == NULL && t->Rchild == NULL)
            printf("%d %d\n", t->data, depth);
        preorder(t->Lchild, depth + 1);
        preorder(t->Rchild, depth + 1);
    }
}
//插入
BTNodeptr Root = NULL; // 根
void insertBST(int item)
{
    BTNodeptr p, q;
    p = (BTNodeptr)malloc(sizeof(BTNode));
    p->data = item;
    p->Lchild = NULL;
    p->Rchild = NULL;
    if (Root == NULL)
        Root = p;
    else
    {
        q=Root;
        while(1)
        {
            if(item<q->data)
            {
                if(q->Lchild==NULL) {q->Lchild=p;break;}
                else q=q->Lchild;
            }
            else 
            {
                if(q->Rchild==NULL) {q->Rchild=p;break;}
                else q=q->Rchild;
            }
            
        }
    }
}
int main()
{
    int num, tmp;
    scanf("%d", &num);
    while (num--)
    {
        scanf("%d",&tmp);
     insertBST(tmp);
    }
    preorder(Root,1);
    destroyBT(Root);
    return 0;
}


