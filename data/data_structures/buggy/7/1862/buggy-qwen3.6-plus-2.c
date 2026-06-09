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
    else if (val > t->data) // @@ The condition should be 'else' or 'val >= t->data' because the problem specifies that the right child's value must be greater than or equal to the root, so duplicates should be inserted into the right subtree.
    {
        t->right = insertTree(t->right, val);
    }
    else // @@ This branch incorrectly ignores duplicate values instead of placing them in the right subtree as required by the problem statement.
        return t;
    return t;
}
void printleaves(tree *t, int temp)
{

    if (t->left == NULL && t->right == NULL) // @@ Missing a NULL check for 't' at the beginning of the function, which will cause a segmentation fault if the input tree is empty (n=0).
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