#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node
{
    DataType data;
    DataType height;
    struct node *left, *right;
} BTNode, *BTNodeptr;

BTNodeptr insertBST(BTNodeptr p, DataType item);
void preOrderPrintLeaves(BTNodeptr p);

BTNodeptr root = NULL;
int height = 1;

int main(int argc, char *argv[])
{
    int num = 0, tmp;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &tmp);
        root = insertBST(root, tmp);
    }
    preOrderPrintLeaves(root);

    return 0;
}

BTNodeptr insertBST(BTNodeptr p, DataType item)
{
    if (p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->height = height;
        p->left = p->right = NULL;
        height = 1;
    }
    else if (item < p->data)
    {
        height++;
        p->left = insertBST(p->left, item);
    }
    else if (item >= p->data)
    {
        height++;
        p->right = insertBST(p->right, item);
    }
    return p;
}

void preOrderPrintLeaves(BTNodeptr p)
{
    if (p != NULL)
    {
        if (p->left == NULL && p->right == NULL)
            printf("%d %d\n", p->data, p->height);
        preOrderPrintLeaves(p->left);
        preOrderPrintLeaves(p->right);
    }
}



