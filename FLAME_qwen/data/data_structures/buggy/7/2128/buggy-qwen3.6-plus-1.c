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
    if (T->lchild != NULL) // @@ [Logical error: This condition prevents visiting the right subtree when a left child exists, failing to traverse the entire tree to find all leaves.]
    {
        visit(T->lchild, depth + 1); // @@ [Logical error: Only recursively visits the left child, missing the right subtree and other leaf nodes.]
    }
    else // @@ [Logical error: The else branch incorrectly handles tree traversal, as it should visit both subtrees independently regardless of the left child's existence.]
    {
        if (T->rchild != NULL) // @@ [Logical error: Right child is only checked if left child is NULL, which skips leaves in right subtrees of nodes that have left children.]
        {
            visit(T->rchild, depth + 1); // @@ [Logical error: Incomplete traversal logic leads to missing leaf nodes.]
        }
        else // @@ [Logical error: This branch is only reached when left child is NULL, incorrectly identifying leaves and missing those with left children.]
            printf("%d %d\n", T->num, depth); // @@ [Logical error: Leaf printing condition is flawed due to incorrect traversal structure; should check if both children are NULL.]
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