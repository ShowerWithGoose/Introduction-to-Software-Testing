#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

BstNode *insBst(BstNode *root, int data)
{
    if (root == NULL)
    {
        root = (BstNode *)malloc(sizeof(BstNode));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
    {
        root->left = insBst(root->left, data);
    }
    else
    {
        root->right = insBst(root->right, data);
    }
    return root;
}

void printBst(BstNode *root, int height)
{
    if (root->left != NULL)
        printBst(root->left, height + 1);
    if (root->right != NULL)
        printBst(root->right, height + 1);
    if (root->left == NULL && root->right == NULL)
        printf("%d %d\n", root->data, height);
} // @@ [The function does not handle the case when root is NULL, leading to potential segmentation fault when the tree is empty or during recursive calls on NULL children.]

int main()
{
    BstNode *root = NULL;
    int n, i, data;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &data);
        root = insBst(root, data);
    }
    printBst(root, 1); // @@ [If n is 0, root remains NULL and passing NULL to printBst causes dereferencing of NULL pointer. Also, even for non-empty trees, printBst may access root->left/right without checking if root is NULL first.]
    return 0;
}