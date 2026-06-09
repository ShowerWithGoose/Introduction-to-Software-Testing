#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>
struct tree
{
    int num;
    struct tree *left;
    struct tree *right;
};
struct tree *tree;
void in_tree(int n, struct tree *p)
{
    if (n < p->num && p->left == NULL)
    {
        p->left = (struct tree *)malloc(sizeof(struct tree));
        p = p->left;
        p->left = NULL;
        p->right = NULL;
        p->num = n;
    }
    else if (n >= p->num && p->right == NULL)
    { 
        p->right = (struct tree *)malloc(sizeof(struct tree));
        p = p->right;
        p->left = NULL;
        p->right = NULL;
        p->num = n;
    }
    else if (n < p->num)
        in_tree(n, p->left);
    else
        in_tree(n, p->right);
}
void dlr(struct tree *tree, int height)
{
    if (tree != NULL)
    {
        if (tree->left == NULL && tree->right == NULL)
            printf("%d %d\n", tree->num, height);
        else
        {
            dlr(tree->left, height + 1);
            dlr(tree->right, height + 1);
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    tree = (struct tree *)malloc(sizeof(struct tree));
    scanf("%d", &(tree->num));
    tree->left = NULL;
    tree->right = NULL;
    int inp;
    for (int i = 0; i < num-1; i++)
    {
        scanf("%d",&inp);
        in_tree(inp, tree);
    }
    dlr(tree, 1);
    return 0;
}
