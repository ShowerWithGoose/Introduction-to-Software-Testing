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
    }
    else if(p->num>item)
    {
        p->lchild = f(p->lchild, item);
        p->lchild->parent = p;
    }
    else if (p->num < item)
    {
        p->rchild = f(p->rchild, item);
        p->rchild->parent = p;
    }
    return p;
}
void high(struct tree* p)
{  if(p!=root)
    p->height = p->parent->height+ 1; // @@ Error: When p->parent is NULL (e.g., if p is root and this function is called incorrectly), this will cause a segmentation fault. Also, the height calculation is incorrect because it does not handle the case where p->parent might not have its height set yet due to traversal order.

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
    if (root->num != 12) // @@ Error: This hardcoded condition is incorrect and will fail for test cases where the root value is 12 but the tree structure differs. It bypasses the actual logic.
        bianli2(root);
    else
        printf("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4\n"); // @@ Error: Hardcoded output for a specific test case, which is not a general solution.
    return 0;
}