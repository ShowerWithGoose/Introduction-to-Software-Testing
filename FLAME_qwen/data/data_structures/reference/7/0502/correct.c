//binary search tree, bst
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node *lchild;
    struct Node *rchild;
} Node;
typedef Node *NodeP;

NodeP bst_insert(NodeP t, DataType item);
void pre_order(NodeP t);

int h = 1; //height of item

int main()
{
    int n; //number of data
    int i;
    DataType item;
    NodeP root = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &item);
        root = bst_insert(root, item);
    }
    pre_order(root);
    return 0;
}

NodeP bst_insert(NodeP t, DataType item)
{
    if (t == NULL)
    {
        t = (NodeP)malloc(sizeof(Node));
        t->data = item;
        t->lchild = t->rchild = NULL;
    }
    else if (item < t->data)
    {
        t->lchild = bst_insert(t->lchild, item);
    }
    else if (item > t->data)
    {
        t->rchild = bst_insert(t->rchild, item);
    }
    else //if (item = t->data)
    {
        t->rchild = bst_insert(t->rchild, item);
    }
    return t;
}

void pre_order(NodeP t)
{
    if (t != NULL)
    {
        if (t->lchild == NULL && t->rchild == NULL) //leaf
        {
            printf("%d %d\n", t->data, h);
        }
        h++;
        pre_order(t->lchild);
        pre_order(t->rchild);
        h--;
    }
}

