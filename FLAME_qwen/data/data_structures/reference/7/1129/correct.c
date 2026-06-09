#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define eps 1 e - 7
struct node
{
    int data;
    int depth;
    struct node *left, *right;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr insertBST(BTNodeptr, int, int);
void inorder(BTNodeptr);
int main()
{
    BTNodeptr Root = NULL;
    int n, i;
    int x;
    int a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        Root = insertBST(Root, a[i], 0);
    }
    inorder(Root);
    getchar();
    return 0;
}
BTNodeptr insertBST(BTNodeptr p, int item, int h)
{
    if (p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->depth = h;
        p->left = p->right = NULL;
    }
    else if (item < p->data)
        p->left = insertBST(p->left, item, h + 1);
    else if (item >= p->data)
        p->right = insertBST(p->right, item, h + 1);
    return p;
}
void inorder(BTNodeptr t)
{
    if (t != NULL)
    {
        inorder(t->left);
        if (t->left == NULL && t->right == NULL)
            printf("%d %d\n", t->data, t->depth + 1); //访问T指结点
        inorder(t->right);
    }
}
