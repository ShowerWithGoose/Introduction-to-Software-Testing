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
    if (root->left == NULL && root->left == NULL) // @@ The condition checks root->left twice instead of checking root->right. It should be (root->left == NULL && root->right == NULL) to correctly identify leaf nodes. Because of this bug, the root node (which has a left child but the condition incorrectly evaluates based on left being non-NULL? No, wait. If root has left child, root->left is not NULL. The condition is root->left == NULL && root->left == NULL. If root has left child, root->left is not NULL, so condition is false. If root has NO left child, root->left is NULL. Then it prints. This means any node without a left child is printed as a leaf, even if it has a right child. In the test case, 10 has left=NULL? No, 10 is root. 20 > 10 goes right. 15 < 20 goes left of 20. So 10 has right child 20, left is NULL. The buggy condition sees left==NULL and prints 10. The expected output does not include 10 because it is not a leaf (it has right child). Also 130 has right child 140, left NULL. It gets printed. 140 is leaf.
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