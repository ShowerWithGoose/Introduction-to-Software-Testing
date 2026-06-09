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
    if (T->lchild != NULL)
    {
        visit(T->lchild, depth + 1);
    }
    else
    {
        if (T->rchild != NULL) // @@ Error: This else block incorrectly handles the case when left child is NULL but right child is not NULL. It should not skip visiting the right subtree when left is NULL; instead, it should recursively visit the right child regardless. The current logic only visits the right child if left is NULL, but then prints the node only if both children are NULL, which is correct for leaf detection. However, the structure is flawed: when left is NULL and right is not NULL, it visits the right child but does not continue to check for leaves in the right subtree properly because the recursion is inside an else block that prevents further traversal. The correct approach is to always recursively visit both children if they exist, and only print when both are NULL.
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