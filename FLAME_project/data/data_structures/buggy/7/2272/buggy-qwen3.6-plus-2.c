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

void midSearch(treeNode *tree) { // @@ The function name suggests mid-order (in-order), but the logic is flawed. It prints non-leaf nodes' children incorrectly or misses the standard in-order traversal structure for printing leaves left-to-right. Specifically, it only recurses if NOT a leaf, but then prints regardless. This actually performs a pre-order-like visit for leaves but fails to traverse correctly if a node is not a leaf but one child is null. More importantly, the problem requires Left-to-Right output of leaves. In-order traversal (Left, Root, Right) ensures left-to-right order for BST leaves. The current logic: if not leaf, recurse left, recurse right. Then print. This is effectively a Post-Order traversal for the printing step relative to the recursion decision, but since it returns immediately if leaf, it prints leaves. However, the recursion condition `if (!isLeaf(p))` prevents traversing into children if the current node is a leaf (correct), but if it's not a leaf, it traverses both. The issue is that `midSearch` is implemented as a post-order traversal for printing (print happens after recursive calls). Wait, let's trace: If node is leaf, it skips the `if` block and prints. If node is not leaf, it goes left, goes right, THEN prints. But we only want to print leaves. The `printf` is outside the `if`. So non-leaf nodes will also be printed if they reach the printf line? No, because if it's not a leaf, it enters the if, does recursion, then falls through to printf. So non-leaf nodes ARE printed. That is Error 1.
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
    printf("%d %d\n", p->data, p->layer); // @@ This line executes for ALL nodes, not just leaves. If the node is not a leaf, it still prints its data and layer after recursing. It should only print if it IS a leaf.
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