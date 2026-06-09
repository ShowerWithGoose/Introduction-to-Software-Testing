#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *BinTree;
struct TreeNode
{
    int value;
    int depth;
    BinTree left;
    BinTree right;
};

BinTree Insert(int, BinTree, int); //插入结点
void Inordervisit(BinTree);        //中序访问结点

int main()
{
    int n, m, depth = 1;
    BinTree r = NULL; //定义一个空树
    scanf("%d ", &n);
    while (n--)
    {
        scanf("%d", &m);
        r = Insert(m, r, depth); //将值为m的结点插入树中
    }
    Inordervisit(r); //中序访问
    return 0;
}

BinTree Insert(int m, BinTree t, int depth)
{
    if (!t) //若为空树则创建结点插入
    {
        t = (BinTree)malloc(sizeof(struct TreeNode));
        t->value = m;
        t->left = NULL;
        t->right = NULL;
        t->depth = depth;
    }
    else
    {
        BinTree p = t;
        for (; p != NULL;)
        {
            depth++;
            if (m >= p->value)
            {
                if (p->right == NULL)
                {
                    p->right = (BinTree)malloc(sizeof(struct TreeNode));
                    p->right->value = m;
                    p->right->left = NULL;
                    p->right->right = NULL;
                    p->right->depth = depth;
                    break;
                }
                else
                    p = p->right;
            }
            else
            {
                if (p->left == NULL)
                {
                    p->left = (BinTree)malloc(sizeof(struct TreeNode));
                    p->left->value = m;
                    p->left->left = NULL;
                    p->left->right = NULL;
                    p->left->depth = depth;
                    break;
                }
                else
                    p = p->left;
            }
        }
    }
    return t; //返回树的根结点的指针
}

void Inordervisit(BinTree t)
{
    BinTree stack[10000];
    int top = -1;
    while (t != NULL || top != -1)
    {
        while (t != NULL)
        {
            if (t->left == NULL && t->right == NULL)
                printf("%d %d\n", t->value, t->depth);
            stack[++top] = t;
            t = t->left;
        }
        if (top != -1)
        {
            t = stack[top--];
            t = t->right;
        }
    }
}
