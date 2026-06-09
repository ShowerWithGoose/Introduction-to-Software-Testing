#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
    int data;
    int depth;
    struct NODE *left;
    struct NODE *right;
} Node;

Node *root = NULL;

Node* InsertBST(Node* p, int a, int depth) {
    if (p == NULL) {
        p = (Node*)malloc(sizeof(Node));
        p->data = a;
        p->depth = depth; // 初始化节点的深度
        p->left = NULL;
        p->right = NULL;
    } else if (a < p->data) { // @@ The problem states left child is less than root, right child is greater than or equal. The original code used a <= p->data for left, which puts equal values on the left. It should be a < p->data for left.
        p->left = InsertBST(p->left, a, depth + 1);
    } else if (a >= p->data) { // @@ Correspondingly, the right child condition should be a >= p->data to handle values greater than or equal to the root. The original code used a > p->data.
        p->right = InsertBST(p->right, a, depth + 1);
    }
    return p;
}

int Isleaf(Node *p) {
    if (p != NULL && p->left == NULL && p->right == NULL)
        return 1;
    return 0;
}

void VisitBST(Node *p) {
    if (p == NULL)
        return;
    VisitBST(p->left); // @@ To output leaf nodes from left to right, an in-order traversal (Left-Root-Right) is required. The original code checked the current node before traversing children (Pre-order-like), which does not guarantee left-to-right order for leaves in all BST structures, although for leaves it might seem similar, standard in-order is safer and matches the reference. More importantly, the reference uses in-order. Let's look closer. Actually, for leaves, pre-order and in-order might differ in sequence if the tree structure is complex? No, leaves are visited when encountered. In-order ensures left subtree leaves are printed before right subtree leaves. The original code visits root, then left, then right. If root is a leaf, it prints it. Then it goes left. This is actually Pre-order. The problem asks for "from left to right". In-order traversal guarantees that nodes are visited in sorted order of their keys, which corresponds to left-to-right spatial arrangement in a BST. Pre-order does not. For example, if a node has a right child which is a leaf, and the node itself is not a leaf, pre-order visits the node (skips print), then left subtree, then right leaf. In-order visits left subtree, then node (skips print), then right leaf. The order of leaves relative to each other is determined by their position. In-order is the standard "left-to-right" traversal for BSTs.
    if (Isleaf(p)) {
        printf("%d %d\n", p->data, p->depth);
    }
    VisitBST(p->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        root = InsertBST(root, num, 1); // 根节点的深度设置为1
    }
    VisitBST(root);
    return 0;
}