#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct tree* root = NULL, * q = NULL;
struct tree {
    int num;
    int height;
    struct tree* lchild;
    struct tree* rchild;
    struct tree* parent;
};
struct tree* f(struct tree* p,int item)
{
    if (p == NULL)
    {
        p = (struct tree*)malloc(sizeof(struct tree));
        p->num = item;
        p->height = 0;
        p->lchild = p->rchild = NULL;
        p->parent = NULL; // @@ The parent pointer is not initialized for the new node, which can lead to undefined behavior when accessing p->parent in the high() function.
    }
    else if(p->num>item)
    {
        p->lchild = f(p->lchild, item);
        p->lchild->parent = p;
    }
    else if (p->num < item) // @@ The problem states that right child values are greater than or equal to the root. This condition should be else (covering >=) or explicitly p->num <= item for the right side, but since the left is strict >, this else-if misses the case where p->num == item. It should be just else to handle >= correctly as per BST definition given.
    {
        p->rchild = f(p->rchild, item);
        p->rchild->parent = p;
    }
    return p;
}
void high(struct tree* p)
{  if(p!=root)
    p->height = p->parent->height+ 1;

}
void bianli(struct tree* p)
{
    if (p != NULL)
    {
        high(p);
        bianli(p->lchild);
        bianli(p->rchild);
    }
}
void bianli2(struct tree* p)
{
    if (p != NULL)
    {
        bianli2(p->lchild);
        if (p->lchild == NULL && p->rchild == NULL)
            printf("%d %d \n", p->num, p->height);
        bianli2(p->rchild);
        
    }
}
int main()
{
    
    int n;
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = f(root, x);
    }
    root->height = 1;
    bianli(root);
    if (root->num != 12) // @@ This conditional check is arbitrary and incorrect. It assumes a specific test case (root == 12) requires hardcoded output, which is not a general solution. It should always call bianli2(root).
        bianli2(root);
    else
        printf("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4\n");
    return 0;
}