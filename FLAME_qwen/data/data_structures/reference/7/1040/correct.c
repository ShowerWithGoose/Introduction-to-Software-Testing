#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

typedef int Datatype;
struct node
{
    Datatype data;
    Datatype high;
    struct node *left, *right;
};

typedef struct node BTNode, *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p, Datatype item,Datatype len);
void Print(BTNodeptr p);

int main()
{
    int i, item;
    int n,len;
    scanf("%d", &n);
    BTNodeptr root = NULL;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &item);
        len=0;
        root = insertBST(root, item,len);
    }
    Print(root);
    return 0;
}

BTNodeptr insertBST(BTNodeptr p, Datatype item,Datatype len)
{
    len++;
    if (p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
        p->high=len;
    }
    else if (item < p->data)
        p->left = insertBST(p->left, item,len);
    else if (item >= p->data)
        p->right = insertBST(p->right, item,len);
    return p;
}

void Print(BTNodeptr p)
{
    if(p)
    {
        if(!(p->left)&&!(p->right))
            printf("%d %d\n",p->data,p->high);
        Print(p->left);
        Print(p->right);
    }
}

