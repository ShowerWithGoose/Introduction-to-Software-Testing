#include <stdio.h>
#include <stdlib.h>

struct BstNode {
    int data;
    struct BstNode *left, *right;
};

struct BstNode *insNode(struct BstNode *root, int data) {
    struct BstNode *p;
    if (root == NULL) {
        p = (struct BstNode *)malloc(sizeof(struct BstNode));
        p->data = data;
        p->left = p->right = NULL;
        return p;
    } else if (data < root->data)
        root->left = insNode(root->left, data);
    else
        root->right = insNode(root->right, data);
    return root;
}

void printLeafNode(struct BstNode *root, int hight) {
    if (root->left != NULL)
        printLeafNode(root->left, hight + 1);
    if (root->right != NULL)
        printLeafNode(root->right, hight + 1);
    if (root->left == NULL && root->left == NULL) // @@ [Error: The condition should check both left and right pointers, but it incorrectly checks root->left twice. It should be `root->left == NULL && root->right == NULL`. This causes the condition to never be true for leaf nodes, so no leaf nodes are printed. However, the buggy output shows leaf nodes, indicating the actual code in the buggy version had the correct condition. The real issue is that the traversal is post-order, printing leaf nodes after children, but the expected output requires left-to-right order. Post-order prints left subtree, then right subtree, then root, which for leaf nodes results in left-to-right order only if the tree is traversed correctly. The buggy output includes an extra node "130 7" and "10 1", which are not leaf nodes. This suggests the condition is wrong in the buggy version, printing non-leaf nodes. The correct condition should be `root->left == NULL && root->right == NULL`. The buggy code has `root->left == NULL && root->left == NULL`, which is always equivalent to `root->left == NULL`, so it prints any node with no left child, including internal nodes like 130 (which has no left child but has a right child) and 10 (which has no left child but has a right child). This explains the extra output.]
        printf("%d %d\n", root->data, hight);
}

int main () {
    int n, data;
    struct BstNode *root = NULL; //root一直为根节点
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insNode(root, data);
    }
    printLeafNode(root, 1);
    return 0;
}