#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
typedef int datatype;
typedef struct eachpoint
{
    datatype num;
    int height;
    struct eachpoint *left, *right;

} node;

node *insertBST(node *p, datatype item, int h);
void answer(node *root);
int main()
{
    int i, item, n, h;
    node *root = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &item);
        h = 0;
        root = insertBST(root, item, h);
    }
    answer(root);

    return 0;
}
node *insertBST(node *p, datatype item, int h)
{
    h++;
    if (p == NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->num = item;
        p->left = p->right = NULL;
        p->height = h;
    }
    else if (item < p->num)
    {
        p->left = insertBST(p->left, item, h);
    }
    else if (item >= p->num)
    {
        p->right = insertBST(p->right, item, h);
    }
    return p;
}
void answer(node *root)
{

    if (root)
    {
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->num, root->height);
        }
        answer(root->left);
        answer(root->right);
    }
}



