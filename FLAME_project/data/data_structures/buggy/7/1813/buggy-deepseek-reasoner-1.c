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
    } else if (a <= p->data) { // @@ 错误：应改为 a < p->data，题目要求左子树小于根节点
        p->left = InsertBST(p->left, a, depth + 1);
    } else if (a > p->data) { // @@ 错误：应改为 a >= p->data，题目要求右子树大于等于根节点
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
    if (Isleaf(p)) { // @@ 错误：应先递归左子树再判断叶子，以保证从左到右输出
        printf("%d %d\n", p->data, p->depth);
    }
    VisitBST(p->left); // @@ 错误：应先递归左子树，再输出叶子，最后递归右子树
    VisitBST(p->right); // @@ 错误：顺序应为 VisitBST(p->left); if(Isleaf(p)) printf; VisitBST(p->right);
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