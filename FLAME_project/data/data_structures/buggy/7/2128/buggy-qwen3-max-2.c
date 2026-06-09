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
        if (T->rchild != NULL)
        {
            visit(T->rchild, depth + 1);
        }
        else
            printf("%d %d\n", T->num, depth);
    }
} // @@ [The traversal logic in 'visit' is incorrect: it only prints a node if both children are NULL, but the way it traverses skips nodes that have only a right child and no left child. Specifically, if a node has no left child but has a right child, it recursively visits the right child—but if that right child is a leaf, it will be printed. However, the structure of the 'else' block means that when a node has a left child, it never checks whether the right subtree might contain leaves that should be printed after the left ones. More critically, the function does not handle the case where a node has only a right child correctly in the context of in-order traversal. The correct approach is to always traverse left, then check if current node is leaf, then traverse right—like the reference program's INORDER function. This implementation fails to print all leaf nodes in left-to-right (in-order) sequence because it abandons the standard in-order pattern.]

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