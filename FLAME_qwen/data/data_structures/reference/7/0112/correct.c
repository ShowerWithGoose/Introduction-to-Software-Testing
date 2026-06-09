#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} Tree;
Tree *first;

Tree *New(Tree *r, int a, int len)
{
    len++;
    if (r == NULL)
    {
        r = (Tree *)malloc(sizeof(Tree));
        r->data = a;
        r->left = r->right = NULL;
        first = r;
        r->high = len;
    }
    else if (a < r->data)
        r->left = New(r->left, a, len);
    else if (a >= r->data)
        r->right = New(r->right, a, len);
    return r;
}

void search(Tree *r)
{
    if (r)
    {
        if (!(r->left) && !(r->right))
        {
            printf("%d %d\n", r->data, r->high);
        }
        search(r->left);
        search(r->right);
    }
}
int main()
{
    Tree *r = NULL;
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) //创建树
    {
        scanf("%d", &a);

        int len = 0;
        r = New(r, a, len);
    }
    search(r);
    return 0;
}
