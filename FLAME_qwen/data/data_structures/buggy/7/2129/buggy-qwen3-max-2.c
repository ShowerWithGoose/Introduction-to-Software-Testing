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
        p->right = insertBST(p->right, m, depth + 1); // @@ [The condition logic is flawed: both `m <= p->num` and `m >= p->num` can be true when m == p->num, causing the right subtree to be incorrectly updated after already handling the left. This leads to duplicate insertion or incorrect BST structure. It should use `else` instead of `else if (m >= p->num)`.]
    }
    return p;
}
void printleaf(tree *node)
{
    if (node == NULL) // @@ [Missing null check at the beginning of the function. If root is NULL (e.g., n=0), calling printleaf(root) will dereference a null pointer, causing runtime crash. Also, recursive calls may pass NULL without checking first.]
    {
        return;
    }
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