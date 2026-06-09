#include<stdio.h>
#include<stdlib.h>

// binary tree
typedef int ElementType;

typedef struct bst
{
    ElementType elem;
    struct bst *l, *r;
} BinaryTree;

BinaryTree * createBinaryTree(void);
BinaryTree * createTreeNode(ElementType elem);
BinaryTree * searchElementInTree(BinaryTree * tr, ElementType elem);
BinaryTree * insertElementToTree(BinaryTree * tr, ElementType elem);
// BinaryTree * deleteElementFromTree(BinaryTree * tr, ElementType elem);
BinaryTree * createBinaryTree(void)
{
    return NULL;
}
BinaryTree * createTreeNode(ElementType elem)
{
    BinaryTree * newNode = malloc(sizeof(BinaryTree));
    newNode->l = newNode->r = NULL;
    newNode->elem = elem;
    return newNode;
}
BinaryTree * searchElementInTree(BinaryTree * tr, ElementType elem)
{
    if (tr == NULL)
        return tr;
    else if (tr->elem == elem)
        return tr;
    else if (tr->elem < elem)
        return searchElementInTree(tr->r, elem);
    else
        return searchElementInTree(tr->r, elem);
}
BinaryTree * insertElementToTree(BinaryTree * tr, ElementType elem)
{
    if (tr == NULL)
    {
        // printf("insert %d\n", elem);
        return createTreeNode(elem);
    }
    // printf("now node elem: %d\n", tr->elem);
    // if (tr->elem == elem)
    //     return tr;
    /*else*/ if (tr->elem <= elem)
    {
        tr->r = insertElementToTree(tr->r, elem);
        return tr;
    }
    else
    {
        tr->l = insertElementToTree(tr->l, elem);
        return tr;
    }
}
// binary tree

void searchTree(BinaryTree * tr, int height);

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    int getNum;
    BinaryTree * tree = createBinaryTree();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &getNum);
        // printf("search %d:\n", getNum);
        tree = insertElementToTree(tree, getNum);
    }
    searchTree(tree, 1);

    return 0;
}

void searchTree(BinaryTree * tr, int height)
{
    if (tr == NULL)
        return;
    if (tr->l == NULL && tr->r == NULL)
    {
        printf("%d %d\n", tr->elem, height);
        return;
    }
    searchTree(tr->l, height+1);
    searchTree(tr->r, height+1);
}
