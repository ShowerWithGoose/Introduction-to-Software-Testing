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
    } else if (a >= p->data) { // @@ Correspondingly, the right child condition should be a >= p->data to handle values greater than or equal to the root. The original code used a > p->data for right.
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
    VisitBST(p->left); // @@ To output leaf nodes from left to right, an in-order traversal (Left-Root-Right) is required. The original code visited Root first, then Left, then Right, which is not standard in-order and might not guarantee left-to-right order for leaves if combined with incorrect logic, but specifically, standard in-order is Left, then process current, then Right. Since we only print leaves, processing current (checking if leaf) can happen between left and right recursive calls. The original code checked if leaf before recursing left. This is Pre-order-ish. For "left to right" output of leaves in a BST, In-order traversal is the standard approach. Let's correct the traversal order to In-order: Left, Check/Print, Right.
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