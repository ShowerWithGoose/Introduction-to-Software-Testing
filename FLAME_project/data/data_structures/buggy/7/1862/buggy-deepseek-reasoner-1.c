#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 100000
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} tree;

tree *newnode(int val)
{
    tree *new = (tree *)malloc(sizeof(tree));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}
tree *insertTree(tree *t, int val)
{
    if (t == NULL)
    {
        t = newnode(val);
        return t;
    }
    else if (val < t->data)
    {
        t->left = insertTree(t->left, val);
    }
    else if (val > t->data) // @@ The condition should be `else` (i.e., val >= t->data) to match the problem's requirement that the right child accepts values greater than or equal to the root. As written, duplicate values are ignored, causing the leaf node 100 to be missing.
    {
        t->right = insertTree(t->right, val);
    }
    else
        return t;
    return t;
}
void printleaves(tree *t, int temp)
{

    if (t->left == NULL && t->right == NULL)
    {
        printf("%d %d\n", t->data, temp);
        return;
    }
    if (t->left != NULL)
        printleaves(t->left, temp + 1);
    if (t->right != NULL)
        printleaves(t->right, temp + 1);
}
int main()
{
    int num;
    tree *bst = NULL;
    scanf("%d", &num);
    int values;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &values);
        bst = insertTree(bst, values);
    }

    printleaves(bst, 1);

    return 0;
}