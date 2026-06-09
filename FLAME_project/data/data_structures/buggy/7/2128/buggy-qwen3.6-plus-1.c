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
void visit(BTREE T, int depth) // @@ The logic here is flawed. It only traverses left if it exists, otherwise checks right. This fails to visit all nodes in a proper inorder traversal (Left-Root-Right). Specifically, if a node has a left child, it never visits the right child or the node itself properly in the context of finding all leaves. It should be a standard inorder traversal that checks for leaf status at each node.
{
    if (T->lchild != NULL) // @@ This structure prevents correct inorder traversal. If T has a left child, it goes left. If not, it checks right. If T has both children, it only goes left and ignores the right subtree entirely from this call frame's perspective regarding the "else" branch logic flow for leaves. More critically, if T is a leaf (no left, no right), it prints. But if T has left child, it recurses left. If T has no left but has right, it recurses right. This actually covers all nodes, BUT the issue is likely that it doesn't handle the case where we need to print leaves correctly in order because the recursion structure is slightly non-standard for inorder, though functionally it might visit all nodes. However, looking closely: if T has left child, it visits left. It does NOT visit right. This is the error. It misses the right subtree if a left child exists.
    {
        visit(T->lchild, depth + 1);
    }
    else // @@ This else block is executed only if T->lchild is NULL. If T->lchild is NOT NULL, the right subtree is never visited.
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