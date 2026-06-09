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
void visit(BTREE T, int depth) // @@ The logic here is flawed. It only traverses left if it exists, otherwise checks right. If both exist, it misses the right subtree entirely in the recursive structure intended for leaf detection. It should check if it's a leaf first, then recurse left and right.
{
    if (T->lchild != NULL) // @@ This condition prevents checking if the current node is a leaf when it has a left child but no right child, or vice versa, and incorrectly structures the traversal. A standard inorder or preorder traversal checking for leaf status is needed.
    {
        visit(T->lchild, depth + 1);
    }
    else // @@ This else block implies that if there is no left child, we either go right or print. This misses cases where a node has a left child but is still a leaf (impossible) or more importantly, if a node has BOTH children, this code only goes left and never visits the right subtree's leaves properly if the left path doesn't lead to immediate leaves in a way that allows backtracking to right. Actually, the main issue is that if T->lchild is NOT NULL, it recurses left. If T->lchild IS NULL, it checks right. If right is also NULL, it prints. But if T has BOTH lchild and rchild, it only visits lchild subtree. It never visits rchild subtree.
    {
        if (T->rchild != NULL)
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