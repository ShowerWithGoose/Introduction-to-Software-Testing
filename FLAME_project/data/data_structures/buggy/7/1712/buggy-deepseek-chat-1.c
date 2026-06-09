#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent; // 父节点的引用
} node, *ptr;

ptr insert(ptr p, int item, ptr parent)
{
    if (p == NULL)
    {
        p = (ptr)malloc(sizeof(node));
        if (p == NULL)
        {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }
        p->data = item;
        p->left = p->right = NULL;
        p->parent = parent; // 设置父节点
    }
    else if (item < p->data)
        p->left = insert(p->left, item, p); // 传递当前节点作为父节点
    else if (item > p->data) // @@ [Error: This condition uses '>' instead of '>='. According to the problem, right child should be greater than or equal to the root. Since the input contains duplicate value 100, using '>' will cause the second 100 to not be inserted, resulting in the missing leaf node 100 in the output.]
        p->right = insert(p->right, item, p); // 传递当前节点作为父节点

    return p;
}

// 计算叶节点的高度应该是从该节点遍历到根节点的路径长度
int leafHeight(ptr leaf)
{
    int height = 0;
    while (leaf)
    {
        height++;
        leaf = leaf->parent; // 向上遍历到父节点
    }
    return height;
}

// 修改 search 函数来使用 leafHeight 函数计算每个叶节点的高度
void search(ptr t)
{
    if (t)
    {
        if (!t->left && !t->right)
        {
            int high = leafHeight(t);
            printf("%d %d\n", t->data, high);
        }
        search(t->left);
        search(t->right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int item;
    ptr root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        root = insert(root, item, NULL);
    }
    search(root);
    return 0;
}