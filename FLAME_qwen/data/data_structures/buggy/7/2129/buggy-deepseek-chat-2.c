#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct tnode
{
    int num, depth;
    struct tnode *left, *right;
} tree;
tree *insertBST(tree *p, int m, int depth)
{
    if (p == NULL)
    {
        p = (tree *)malloc(sizeof(tree));
        p->depth = depth, p->left = p->right = NULL, p->num = m;
    }
    else if (m <= p->num) // @@ The condition should be m < p->num to match the problem description (left child less than root, right child greater than or equal to root). Using <= here incorrectly sends equal values to the left subtree.
    {
        p->left = insertBST(p->left, m, depth + 1);
    }
    else if (m >= p->num) // @@ This condition is redundant; it should be just else. Also, using >= here is unnecessary since the previous condition already handles m <= p->num. The correct logic is: if m < p->num go left, else go right.
    {
        p->right = insertBST(p->right, m, depth + 1);
    }
    return p;
}
void printleaf(tree *node)
{
    if (node->left != NULL)
    {
        printleaf(node->left);
    }
    if (node->right != NULL)
    {
        printleaf(node->right);
    }
    if (node->left == NULL && node->right == NULL)
    {
        printf("%d %d\n", node->num, node->depth);
    }
    return;
}
int main(int argc, char const *argv[])
{
    int i, n, m;
    scanf("%d", &n);
    tree *root = NULL;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        // printf("%d ", m);
        root = insertBST(root, m, 1);
    }
    // printf("\n");
    printleaf(root);
    return 0;
}