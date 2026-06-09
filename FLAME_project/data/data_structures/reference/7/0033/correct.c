#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} Tree;


Tree *inserts(Tree *p, int temp, int len); //新建节点
void print(Tree *p);                   //打印叶节点

int main()
{
    Tree *p = NULL;
    int n, temp,i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &temp);

        int len = 0;
        p = inserts(p, temp, len);
    }
    print(p);
    return 0;
}

Tree *inserts(Tree *p, int temp, int len)
{
    len++;
    if (p == NULL)
    {
        p = (Tree *)malloc(sizeof(Tree));
        p->data = temp;
        p->left = p->right = NULL;

        p->high = len;
    }
    else if (temp < p->data)
        p->left = inserts(p->left, temp, len);
    else if (temp >= p->data)
        p->right = inserts(p->right, temp, len);
    return p;
}

void print(Tree *p)
{
    if (p)
    {
        if ((p->left==NULL) && (p->right==NULL))
        {
            printf("%d %d\n", p->data, p->high);
        }
        print(p->left);
        print(p->right);
    }
}


