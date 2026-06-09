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
    else if (data <= root->data) // @@ The problem states that left child is less than root, and right child is greater than or equal to root. This condition puts duplicates and equal values in the left subtree, which contradicts the requirement. It should be `data < root->data` for left, and `else` (which covers >=) for right.
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