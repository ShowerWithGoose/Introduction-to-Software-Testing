#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *left, *right;
} Node;

Node *create(Node *root, int data) //创建二叉树 
{
    Node *p;
    if(root == NULL)
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = data;
        p->left = p->right = NULL;
        return p;
    }else
    if(data < root->data)
    {
        root->left = create(root->left, data);
    }else
    if(data > root->data) // @@ [The problem requires right child to include values >= root, but this code only inserts when data > root->data, ignoring equal values. This causes duplicate values to be silently dropped, leading to incorrect tree structure and missing leaf nodes.]
    {
        root->right = create(root->right, data);
    }
    return root;
}

void print(Node *root, int height) //后序遍历打印叶结点值及高度 
{
    if(root->left != NULL)
    {
        print(root->left, height + 1);
    }
    if(root->right != NULL)
    {
        print(root->right, height + 1);
    }
    if(root->left == NULL && root->right == NULL)
    {
        printf("%d %d\n", root->data, height);
    }
}

int main()
{
    Node *root = NULL;
    int n, data, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = create(root, data);
    }
    print(root, 1);
    return 0;
}