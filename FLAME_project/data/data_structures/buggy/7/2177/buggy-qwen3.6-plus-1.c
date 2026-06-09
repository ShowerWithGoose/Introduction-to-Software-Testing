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
    if (root->left == NULL && root->left == NULL) // @@ The condition checks root->left twice instead of checking root->right. It should be (root->left == NULL && root->right == NULL) to correctly identify leaf nodes. Because of this bug, the root node (which has a left child but the condition incorrectly evaluates based on left being non-NULL? No, wait. If root has left child, root->left is not NULL. So the first if executes. Then second if executes if right exists. Then the final if checks if left is NULL AND left is NULL. If left is NOT NULL, this is false. So leaves are printed only if left is NULL. But wait, if a node is a leaf, left is NULL and right is NULL. The condition `root->left == NULL && root->left == NULL` is true. So leaves are printed. However, if a node has ONLY a right child (left is NULL, right is not NULL), the condition `root->left == NULL && root->left == NULL` is TRUE. So it prints nodes that have only a right child as leaves, which is incorrect. In the test case, 10 is the root. It has a right child (20). Left is NULL. So `root->left == NULL` is true. The condition passes. So 10 is printed as a leaf with height 1. This explains the extra output "10 1".
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