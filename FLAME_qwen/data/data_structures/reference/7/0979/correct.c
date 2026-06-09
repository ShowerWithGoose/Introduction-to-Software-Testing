#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct BiTnode
{
    int data;
    struct BiTnode *lchild, *rchild;
    int height;
} Tree;


Tree *first;

Tree *new (Tree *root, int temp, int len)
{
    len++;
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->data = temp;
        root->height = len;
        root->lchild = root->rchild = NULL;
        first=root;
    }
    else if (temp < root->data)
    {
        root->lchild = new (root->lchild, temp, len);
    }
    else if (temp >= root->data)
    {
        root->rchild = new (root->rchild, temp, len);
    }
    return root;
}

void print(Tree *root)
{
    if (root)
    {
        if (!(root->lchild) && !(root->rchild))
        {
            printf("%d %d\n", root->data, root->height);
        }
        print(root->lchild);
        print(root->rchild);
        // free(root);
    }
}

int main()
{
    Tree *root = NULL;
    int n, temp, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        int len = 0;
        root = new (root, temp, len);
    }
    print(root);
    return 0;
}
