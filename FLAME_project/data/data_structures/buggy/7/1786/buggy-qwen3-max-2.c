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
    p->height = p->parent->height+ 1;

}
void bianli(struct tree* p)
{
    if (p != NULL)
    {
        high(p); // @@ [The `high` function only sets the height based on parent, but it's called in a pre-order traversal. This means a node's height is set before its parent's height might be correctly updated, leading to incorrect heights. Also, the root's height is set to 1 in main, but children are not recursively updated properly because `high` doesn't propagate depth correctly during traversal.]
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
            printf("%d %d \n", p->num, p->height); // @@ [There's an extra space before the newline: " %d \n" should be " %d\n". This causes output format mismatch.]
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
    if (root->num != 12)
        bianli2(root);
    else
        printf("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4\n"); // @@ [This hardcoded branch is clearly a hack for a specific test case and breaks general correctness. It indicates the height computation logic is flawed, so the developer resorted to hardcoding output for one input. This is not a valid solution.]
    return 0;
}