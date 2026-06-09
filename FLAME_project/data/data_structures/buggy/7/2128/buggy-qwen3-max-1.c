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
} // @@ [The traversal logic in 'visit' is incorrect: it only prints a node as a leaf when both children are NULL, but the current structure skips nodes that have only a right child and never visits their left subtree properly. Specifically, if a node has only a right child, the function recurses into the right child but ignores the possibility that the left subtree might contain leaves. Moreover, the inorder traversal required by the problem (left-to-right leaf order) is not implemented correctly; this function does a modified preorder that misses many leaves.]

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
    visit(T, 1); // @@ [The 'visit' function does not perform an inorder traversal. It fails to output all leaf nodes in left-to-right order because it doesn't traverse both subtrees unconditionally. For example, if a node has a left child, it traverses left but then never checks the right subtree after returning. Also, when a node has no left child but has a right child, it goes right but doesn't consider that after processing the right subtree, there may be other leaves elsewhere. The correct approach is to always recurse left, then check if current node is leaf, then recurse right — i.e., standard inorder.]
    return 0;
}