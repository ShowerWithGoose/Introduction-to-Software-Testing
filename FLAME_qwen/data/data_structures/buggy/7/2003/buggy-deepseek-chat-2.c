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
    if (root->left != NULL) // @@ Error: This line does not check if root is NULL before accessing root->left. If root is NULL, this will cause a segmentation fault.
        printBst(root->left, height + 1);
    if (root->right != NULL) // @@ Error: Same issue as above; no NULL check for root before accessing root->right.
        printBst(root->right, height + 1);
    if (root->left == NULL && root->right == NULL) // @@ Error: This line also accesses root without checking if root is NULL, leading to potential crash.
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
    printBst(root, 1);
    return 0;
}