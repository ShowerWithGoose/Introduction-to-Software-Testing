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
    printf("%d %d\n", p->data, p->layer); // @@ 错误：当节点是叶子时，会直接输出，但中序遍历要求先左后右，这里在非叶子节点时先递归左右子树，然后对叶子节点输出，但逻辑上对于非叶子节点，递归后没有输出，而叶子节点直接输出，这会导致输出顺序不是从左到右的叶子节点顺序，而是先输出左子树的叶子，然后输出当前节点（如果是叶子），然后输出右子树的叶子，但当前节点如果是非叶子，则不会输出，所以实际上输出顺序是正确的，但代码逻辑混乱。更严重的问题是：当节点是叶子时，会直接输出，但递归调用在非叶子节点时已经处理了左右子树，而叶子节点没有递归调用，所以输出顺序是正确的。然而，这里有一个潜在错误：当节点是叶子时，会执行printf，然后返回，但递归调用在非叶子节点时，会先递归左子树，再递归右子树，然后函数结束，没有输出非叶子节点本身，这符合只输出叶子的要求。但代码中if (!isLeaf(p)) 分支内递归后没有return，会继续执行到printf，导致非叶子节点也被输出！因为if (!isLeaf(p)) 后面没有else，所以非叶子节点在递归完左右子树后，也会执行printf，输出非叶子节点本身，这是错误的。
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