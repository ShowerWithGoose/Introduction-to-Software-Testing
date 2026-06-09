#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct tree
{
    int data;
    int high;
    struct tree *left, *right;
} Tree;
Tree *first;

Tree *New(Tree *root, int temp, int len); //新建节点
                   
void print(Tree *root)//打印叶节点
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


int main()
{
	int i;
    Tree *root = NULL;
    int n, tmp;
    scanf("%d", &n);
    for (i = 0; i < n; i++) //创建树
    {
        scanf("%d", &tmp);

        int len = 0;
        root = New(root, tmp, len);
    }
    print(root);
    return 0;
}

Tree *New(Tree *root, int tmp, int len)
{
    len++;
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->data = tmp;
        root->left = root->right = NULL;
        first = root;
        root->high = len;
    }
    else if (tmp < root->data)
        root->left = New(root->left, tmp, len);
    else if (tmp >= root->data)
        root->right = New(root->right, tmp, len);
    return root;
}



