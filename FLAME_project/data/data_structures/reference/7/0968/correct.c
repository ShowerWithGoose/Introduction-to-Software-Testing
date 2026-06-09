#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <malloc.h>
typedef struct Tree
{
    int data;
    int layer;
    struct Tree *left;
    struct Tree *right;
} * Tree, Lnode;
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
Tree find_loc(Tree root, int data, int *dir)
{
    if (root->data > data && root->left == NULL)
    {
        *dir = -1;
        return root;
    }
    if (root->data > data && root->left != NULL)
        return find_loc(root->left, data, dir);
    if (root->data <= data && root->right == NULL)
    {
        *dir = 1;
        return root;
    }
    if (root->data <= data && root->right != NULL)
        return find_loc(root->right, data, dir);
}
Tree build_tree_point(Tree root, int data)
{
    Tree p = NULL, loc = NULL;
    int dir = 0;
    p = (Tree)malloc(sizeof(Lnode));
    p->data = data;
    p->left = p->right = NULL;
    if (root == NULL)
    {
        p->layer = 1;
        return p;
    }
    loc = find_loc(root, data, &dir);
    p->layer = loc->layer + 1;
    if (dir < 0)
        loc->left = p;
    else
        loc->right = p;
    return p;
}
void data_out(Tree root)
{
    if (root->left == root->right && root->left == NULL)
        printf("%d %d\n", root->data, root->layer);
    if (root->left != NULL)
        data_out(root->left);
    if (root->right != NULL)
        data_out(root->right);
}
void free_tree(Tree root)
{
    Tree p = NULL;
    if (root != NULL && root->left == NULL && root->right == NULL)
        free(root);
    if (root != NULL && root->left != NULL)
    {
        p = root;
        free_tree(root->left);
        free(p);
    }
    if (root != NULL && root->right != NULL)
    {
        p = root;
        free_tree(root->right);
        free(p);
    }
}
int main()
{
    int data, i, n;
    Tree p = NULL, root = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        if (root == NULL)
            root = build_tree_point(NULL, data);
        else
            build_tree_point(root, data);
    }
    data_out(root);
    free_tree(root);
    return 0;
}
