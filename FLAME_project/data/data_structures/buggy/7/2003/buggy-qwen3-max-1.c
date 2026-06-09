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
        root->left = insBst(root->left, data); // @@ [Incorrect BST insertion logic: values equal to the root should go to the right subtree, not the left. According to the problem, right child is >= root, so 'data < root->data' should go left, and 'data >= root->data' should go right.]
    }
    else
    {
        root->right = insBst(root->right, data);
    }
    return root;
}

void printBst(BstNode *root, int height)
{
    if (root == NULL) return; // @@ [Missing null check before accessing root->left and root->right. When the tree is empty or during recursion on non-existent children, this causes undefined behavior or skips necessary base case handling. However, in this specific test case the tree isn't empty, but more critically, the traversal order is correct but the missing null check could cause crashes in other cases. But the main issue causing wrong answer is the insertion logic above. Additionally, note that the expected output includes '87 4' which is missing in buggy output — this node becomes internal instead of leaf due to incorrect insertion of duplicate '100'.]

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