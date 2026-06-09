#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct bst
{
    int num;
    struct bst *left;
    struct bst *right;
};
typedef struct bst ptr;
ptr *creat_point(int num)
{
    ptr *q;
    q = (ptr *)malloc(sizeof(ptr));
    q->num = num;
    q->left = NULL;
    q->right = NULL;
    return q;
}
ptr *creat_tree(ptr *root, int num)
{
    if (num < root->num)
    {
        if (root->left == NULL)
        {
            ptr *q;
            q = creat_point(num);
            root->left = q;
        }
        else
        {
            creat_tree(root->left, num);
        }
    }
    else if (num >= root->num)
    {
        if (root->right == NULL)
        {
            ptr *q;
            q = creat_point(num);
            root->right = q;
        }
        else
        {
            creat_tree(root->right, num);
        }
    }
    return root;
}
void put_out(ptr *point, int count)
{
    if (point->left == NULL && point->right == NULL)
    {
        printf("%d %d\n", point->num, count);
        return;
    }
    else
    {
        if(point->left != NULL)
        {
            put_out(point->left , count + 1);
        }
        if(point->right != NULL)
        {
            put_out(point->right,count + 1);
        }
    }
}
void free_point(ptr *point)
{
    if(point->left != NULL)
    free_point(point->left);
    if(point->right != NULL)
    free_point(point->right);
    free(point);
}
int main()
{
    int n;
    ptr *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int number;
        scanf("%d", &number);
        if (root == NULL)
        {
            ptr *q;
            q = creat_point(number);
            root = q;
        }
        else
        {
            root = creat_tree(root, number);
        }
    }
    put_out(root, 1);
    free_point(root);
}
