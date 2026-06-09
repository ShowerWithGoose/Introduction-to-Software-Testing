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
        root->left = insBst(root->left, data); // @@ [Incorrect BST insertion logic: values equal to the root should go to the right subtree, not the left. According to the problem, right child is >= root, so `data < root->data` should go left, and `data >= root->data` should go right.]
    }
    else
    {
        root->right = insBst(root->right, data);
    }
    return root;
}

void printBst(BstNode *root, int height)
{
    if (root == NULL) return; // @@ [Missing null check before accessing root's children. When the tree is empty or during recursion on non-existent children, this causes undefined behavior. However, in this specific test case, root is not null initially, but more critically, the traversal order is correct (in-order), but the real issue is the incorrect tree structure due to insertion bug. The missing null check could cause crash on empty input, but here the main error is in insertion logic. Still, for safety and correctness, a null check is needed at start of function. But per problem output mismatch, the core bug is in insertion condition.]
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
    if (root != NULL) printBst(root, 1); // @@ [Missing null check before calling printBst. If n=0, root is NULL and printBst would dereference null. But in given test case n=15, so not the cause of WA. However, the reference program includes this check. But the primary cause of wrong answer is the insertion logic.]
    return 0;
}