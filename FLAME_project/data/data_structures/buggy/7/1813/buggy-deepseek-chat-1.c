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
    } else if (a <= p->data) { // @@ [Error: The condition should be a < p->data for left child, as per problem description "left child is less than the root". Using <= causes equal values to go left, but the expected output shows 100 at depth 4, meaning the second 100 should go right (>=). This changes the tree structure and leaf depths.]
        p->left = InsertBST(p->left, a, depth + 1);
    } else if (a > p->data) { // @@ [Error: The condition should be a >= p->data for right child, as per problem description "right child is greater than or equal to the root". Using > causes equal values to go left, which is incorrect and leads to wrong leaf depths.]
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
    if (Isleaf(p)) {
        printf("%d %d\n", p->data, p->depth);
    }
    VisitBST(p->left);
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