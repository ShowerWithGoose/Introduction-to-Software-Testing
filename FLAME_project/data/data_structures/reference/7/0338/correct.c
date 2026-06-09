#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
}BTNode, *BTNodeptr;
BTNodeptr first;

BTNodeptr New(BTNodeptr root, int item, int deep); //新建节点
void print(BTNodeptr root);                   //打印叶节点

int main()
{
    BTNodeptr root = NULL;
    int i,n, item;
    scanf("%d", &n);
    for (i = 0; i < n; i++) //创建树
    {
        scanf("%d", &item);

        int deep = 0;
        root = New(root, item, deep);
    }
    print(root);
    return 0;
}

BTNodeptr New(BTNodeptr root, int item, int deep)
{
    deep++;
    if (root == NULL)
    {
        root = (BTNodeptr)malloc(sizeof(BTNode));
        root->data = item;
        root->left = root->right = NULL;
        first = root;
        root->high = deep;
    }
    else if (item < root->data)
        root->left = New(root->left, item, deep);
    else if (item >= root->data)
        root->right = New(root->right, item, deep);
    return root;
}

void print(BTNodeptr root)
{
    if (root)
    {
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->data, root->high);
        }
        print(root->left);
        print(root->right);
    }
}



