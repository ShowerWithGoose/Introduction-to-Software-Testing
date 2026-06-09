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
        p->right = insertBST(p->right, m, depth + 1); // @@ [The condition `m >= p->num` overlaps with the previous `m <= p->num`, causing all values equal to the current node to be inserted into both left and right subtrees in different recursive paths. More critically, when `m == p->num`, it satisfies both `m <= p->num` and `m >= p->num`, but due to `else if`, only the left branch is taken. However, the problem states that right child should be used for values "greater than or equal", so the left condition should be strictly `<`, not `<=`. This leads to incorrect BST structure.]
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
        printleaf(node->right); // @@ [This traversal is post-order (left, right, then process), but the problem requires outputting leaf nodes from left to right, which corresponds to in-order traversal. The current order may output leaves in an incorrect sequence. For example, a right subtree leaf might be printed before a left subtree leaf of a higher ancestor if the structure is skewed. The correct approach is to use in-order traversal: traverse left, process current if leaf, then traverse right.]
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
    printleaf(root); // @@ [If the input `n` is 0, `root` remains NULL, and calling `printleaf(root)` will dereference a NULL pointer, causing a runtime crash. The function `printleaf` does not check for NULL input before accessing `node->left` or `node->right`.]
    return 0;
}