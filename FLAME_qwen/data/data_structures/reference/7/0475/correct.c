#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct TreeNode
{
    int date; //数据域
    struct TreeNode *lchild, *rchild;
} TreeNode;
TreeNode* InsertBT(TreeNode *, int /*数据域*/);
void ptLeaveNode(TreeNode *, int);
int main()
{
    int n, date, i;
    struct TreeNode *T = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &date);
        T=InsertBT(T, date);
    }
    ptLeaveNode(T, 1);
    return 0;
}
TreeNode* InsertBT(TreeNode *T, int item)
{
    if (T == NULL)
    {
        T = (TreeNode *)malloc(sizeof(TreeNode));
        T->date = item;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else if (item < T->date)
    {
        T->lchild=InsertBT(T->lchild, item);
    }
    else
    {
        T->rchild=InsertBT(T->rchild, item);
    }
    return T;
}
void ptLeaveNode(TreeNode *t, int l0)
{
    int l1 = l0;
    if (t->lchild == NULL && t->rchild == NULL)
    {
        printf("%d %d\n", t->date, l1);
    }
    else
    {
        if (t->lchild!=NULL)
        {
        ptLeaveNode(t->lchild, l1 + 1);
        }
        if (t->rchild!=NULL)
        {
        ptLeaveNode(t->rchild, l1 + 1);
        }
    }
}
