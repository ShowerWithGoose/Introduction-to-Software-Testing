#include "stdio.h"
#include "stdlib.h"

//按照左子结点值小于根结点值、右子结点值大于等于根结点值的方式构造一棵二叉查找树
//然后从左至右输出所有树中叶结点的值及高度（根结点的高度为1）

typedef struct node {
    int data;
    int layer;
    struct node *left;
    struct node *right;
} treeNode;

treeNode *createTree() {
    treeNode *new = (treeNode *) malloc(sizeof(treeNode));
    new->left = NULL;
    new->right = NULL;
    new->layer = 0;
    return new;
}

int isLeaf(treeNode *node) {
    if (node->right == NULL && node->left == NULL) {
        return 1;
    }
    return 0;
}

void attach(treeNode *tree, int data) {

    if (data < tree->data) {

        if (tree->left == NULL) {
            treeNode *new = (treeNode *) malloc(sizeof(treeNode));
            new->data = data;
            new->left = NULL;
            new->right = NULL;

            tree->left = new;
            new->layer = tree->layer + 1;
            return;
        }

        attach(tree->left, data);

    } else {

        if (tree->right == NULL) {
            treeNode *new = (treeNode *) malloc(sizeof(treeNode));
            new->data = data;
            new->left = NULL;
            new->right = NULL;
            tree->right = new;
            new->layer = tree->layer + 1;
            return;
        }
        attach(tree->right, data);
    }
    return;
}

void midSearch(treeNode *tree) {
    treeNode *p = tree;
    if (tree == NULL) {
        return;
    }
    if (!isLeaf(p)) {
        //如果不是叶子
        midSearch(p->left);
        midSearch(p->right);
    }
    //是叶子
    printf("%d %d\n", p->data, p->layer); // @@ [Error: This prints all nodes, not just leaf nodes. The condition for printing leaf nodes is incorrect; it prints after the if block regardless of whether the node is a leaf. Should only print when isLeaf(p) is true, and the traversal order should be left-to-right (in-order).]
    return;
}

void freeTree(treeNode *tree) {
    treeNode *p = tree;
    if (p != NULL) {
        freeTree(p->left);
        freeTree(p->right);
        free(p);
    }
    return;
}

int main() {
    setbuf(stdout, 0);

    int n;
    scanf("%d", &n);
    int in[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    treeNode *tree = createTree();
    if (n == 0) {
        printf("没数\n");
        exit(-1);
    }
    tree->layer = 1;
    tree->data = in[0];     //处理头结点

    //把树组织起来
    for (int i = 1; i <= n - 1; i++) {
        attach(tree, in[i]);
    }

    //使用中序查找
    midSearch(tree);

    freeTree(tree);
    return 0;
}