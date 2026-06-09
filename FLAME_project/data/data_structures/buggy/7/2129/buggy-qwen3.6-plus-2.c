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
    else if (m <= p->num) // @@ The problem states left child is less than root, right child is greater than or equal. This condition puts equal values to the left, which contradicts the requirement. It should be m < p->num.
    {
        p->left = insertBST(p->left, m, depth + 1);
    }
    else if (m >= p->num) // @@ Consequently, this branch handles m > p->num (since m==p->num was caught above). While logically consistent with the previous error, the standard BST definition given requires left < root and right >= root. Fixing the first condition to 'm < p->num' makes this 'else if (m >= p->num)' correct for the right side. However, strictly speaking, if the first condition is fixed to '<', this condition covers '>=' which is correct. The primary error is the first condition.
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