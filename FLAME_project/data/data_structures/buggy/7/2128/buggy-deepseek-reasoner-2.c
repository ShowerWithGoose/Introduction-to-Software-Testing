/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node
{
    datatype num;
    struct node *lchild, *rchild;
} BTNode, *BTREE;
BTREE T = NULL, p, q;
void search(BTREE *T, BTREE p)
{
    if (p->num < (*T)->num)
    {
        if ((*T)->lchild == NULL)
        {
            (*T)->lchild = p;
        }
        else
        {
            search(&(*T)->lchild, p);
        }
    }
    else
    {
        if ((*T)->rchild == NULL)
        {
            (*T)->rchild = p;
        }
        else
        {
            search(&((*T)->rchild), p);
        }
    }
}
void visit(BTREE T, int depth)
{
    if (T->lchild != NULL) // @@ 错误：如果左子树存在，只递归左子树，未递归右子树，也未检查当前节点是否为叶，导致无法遍历整个树
    {
        visit(T->lchild, depth + 1);
    }
    else
    {
        if (T->rchild != NULL) // @@ 错误：当左子树为空时才考虑右子树，但未正确处理既有左子树又有右子树的情况，导致只遍历了最左路径
        {
            visit(T->rchild, depth + 1);
        }
        else
            printf("%d %d\n", T->num, depth);
    }
}
int main()
{
    int n;
    datatype a;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        if (T == NULL)
        {
            p = (BTREE)malloc(sizeof(BTNode));
            p->num = a;
            p->lchild = NULL;
            p->rchild = NULL;
            T = p;
        }
        else
        {
            p = (BTREE)malloc(sizeof(BTNode));
            p->num = a;
            p->lchild = NULL;
            p->rchild = NULL;
            search(&T, p);
        }
    }
    visit(T, 1);
    return 0;
}