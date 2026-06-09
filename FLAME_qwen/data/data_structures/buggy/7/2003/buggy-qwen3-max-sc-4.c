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
    if (root == NULL) return; // @@ [The original code dereferences root without checking for NULL, which causes undefined behavior when the tree is empty or during recursive calls on NULL children.]
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
    if (root != NULL) // @@ [If the input n is 0, root remains NULL and calling printBst(root, 1) would dereference a NULL pointer. The reference program avoids this by checking root in printBst, but this version doesn't. However, the immediate crash happens inside printBst, so the primary fix is there. Still, guarding here also helps. But per instructions, only annotate lines with errors. The real error is in printBst's first line not checking NULL.]
        printBst(root, 1);
    return 0;
}