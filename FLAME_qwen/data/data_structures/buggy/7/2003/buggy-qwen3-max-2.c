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
    if (root == NULL) return; // @@ [Missing null check before accessing root->left and root->right, leading to segmentation fault when root is NULL]
    if (root->left != NULL)
        printBst(root->left, height + 1);
    if (root->right != NULL)
        printBst(root->right, height + 1);
    if (root->left == NULL && root->right == NULL)
        printf("%d %d\n", root->data, height);
}

int main()
{
    BstNode *root = NULL;
    int n, i, data;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &data);
        root = insBst(root, data);
    }
    if (root != NULL) // @@ [Calling printBst with NULL root leads to undefined behavior; should guard against empty tree]
        printBst(root, 1);
    return 0;
}