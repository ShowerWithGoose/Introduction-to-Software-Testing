#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10000
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

typedef struct Node{
    int num;
    int height;
    struct Node *left;
    struct Node *right;
}tree;
int num, h, i, b;

tree *insertBST(tree *a, int h, int b)
{
    b++;
    if(a == NULL)
    {
        a = (tree*)malloc(sizeof(tree));
        a->num = h;
        a->height = b;
        a->left = a->right = NULL;
    }
    else if(h < a->num)
        a->left = insertBST(a->left, h, b);
    else if(h >= a->num)
        a->right = insertBST(a->right, h, b);
    return a;
}

void output(tree *a)
{
    if (a != NULL)
    {
        if ((a->left == NULL) && (a->right == NULL))
        {
            printf("%d %d\n", a->num, a->height);
        }
        output(a->left);
        output(a->right);
    }
}

int main()
{
    scanf("%d", &num);
    tree *a = NULL;
    for(i=0;i<num;i++)
    {
        b = 0;
        scanf("%d", &h);
        a = insertBST(a, h, b);
    }
    output(a);
    return 0;
}

