#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node
{
    int data;
    int height;
    struct node *left, *right;
} Tree;
Tree *Insert(Tree *root, int num, int count)
{
    count++;
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->data = num;
        root->left = root->right = NULL;
        root->height = count;
    }
    else if (num < root->data)
        root->left = Insert(root->left, num, count);
    else if (num >= root->data)
        root->right = Insert(root->right, num, count);
    return root;
}
void print(Tree *root)
{
    if (root!=NULL)
    {
        if (root->left ==NULL&&root->right==NULL)
        {
            printf("%d %d\n", root->data, root->height);
        }
        print(root->left);
        print(root->right);
    }
}

int main()
{
    Tree *root = NULL;
    int n, num,count;
	int i=0;
    scanf("%d", &n);
    for ( i = 0; i <= n-1; i++)
    {
        scanf("%d", &num);

         count = 0;
        root = Insert(root, num, count);
    }
    print(root);
    return 0;
}







