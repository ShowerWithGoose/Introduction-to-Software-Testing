#include <stdio.h>
#include <stdlib.h>

typedef struct BSTnode{
    int data;
    struct BSTnode *l, *r;
} node;

node *insert(node *root, int data)
{
    node *p;
    if (root == NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->data = data;
        p->l = p->r = NULL;
        return p;
    }
    else if (data < root->data)
    {
        root->l = insert(root->l, data);
    }
    else
    {
        root->r = insert(root->r, data);
    }
    return root;
}
void printfAns(node *root, int depth)
{
    if (root->l == NULL && root->r == NULL)
    {
        printf("%d %d\n", root->data, depth);
        return;
    }
    if(root->l != NULL)
    {
        printfAns(root->l, depth + 1);
    }
    if(root->r != NULL)
    {
        printfAns(root->r, depth + 1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    printfAns(root, 1);
    return 0;
}