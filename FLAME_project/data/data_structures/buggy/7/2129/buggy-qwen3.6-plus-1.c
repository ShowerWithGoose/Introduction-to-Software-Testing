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
    else if (m < p->num) // @@ The problem states left child is less than root, right child is greater than or equal. The original code used m <= p->num for left, which incorrectly puts equal values in the left subtree. It should be m < p->num for left.
    {
        p->left = insertBST(p->left, m, depth + 1);
    }
    else if (m >= p->num) // @@ This condition is now redundant if the previous one is corrected to strict less than, but logically it handles the >= case. However, since the first condition was changed to strict less than, this else-if correctly captures the >= case. Note: In C, if the first if is false (m >= p->num), this else-if will also be true. It's better to use just 'else' here to avoid logical redundancy or potential issues if conditions overlap, but strictly speaking, with the fix above, this block handles the right insertion. The main error was the direction of equality.
    {
        p->right = insertBST(p->right, m, depth + 1);
    }
    return p;
}
void printleaf(tree *node)
{
    if (node == NULL) return; // @@ Added null check to prevent segmentation fault if root is NULL, though not strictly the cause of the wrong answer logic, it's good practice. However, looking at the specific error: The traversal order is Left-Right-Node (Post-orderish) but checks children before recursing? No, it recurses left, then right, then prints if leaf. This is effectively a pre-order traversal regarding when it visits nodes, but it only prints at leaves. Wait, the reference uses Pre-order (Print, Left, Right). The buggy code does: Recurse Left, Recurse Right, Print if Leaf. This is actually valid for printing leaves in left-to-right order because it fully explores left subtree, then right subtree, then processes current node (which is a leaf only if both children are null). Since leaves have no children, the recursion stops and it prints. The order of visiting leaves will be left-to-right. So the traversal logic is actually correct for leaves. The main issue is the BST insertion logic.
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