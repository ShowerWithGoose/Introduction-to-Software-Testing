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
    else if (m <= p->num)
    {
        p->left = insertBST(p->left, m, depth + 1);
    }
    else if (m >= p->num)
    {
        p->right = insertBST(p->right, m, depth + 1); // @@ [The condition logic is incorrect: it should be `else` instead of `else if (m >= p->num)` because all cases where `m <= p->num` are already handled; this causes nodes with `m == p->num` to be inserted on both left and right in different calls, violating BST structure. Also, the original problem states right child is for values "greater than or equal", so left should be strictly less, and right should be greater or equal — but current code sends equal values to the left due to `m <= p->num`, which contradicts the problem description.]
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
    printleaf(root); // @@ [This function does a post-order traversal, but the problem requires outputting leaf nodes from left to right, which corresponds to in-order traversal. The current traversal order may not output leaves in left-to-right (in-order) sequence.]
    return 0;
}