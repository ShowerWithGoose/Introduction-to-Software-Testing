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
        high(p); // @@ [The `high` function only sets height based on parent, but traversal order is preorder. This causes nodes to be processed before their parents' heights are correctly propagated in some cases, leading to incorrect height calculation for nodes not visited in proper bottom-up or top-down order.]
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
            printf("%d %d \n", p->num, p->height); // @@ [There's an extra space before the newline: " %d \n" should be " %d\n". This causes presentation error (though in this test case it may still appear correct visually, it's technically wrong format).]
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
    bianli(root); // @@ [The `bianli` function uses a preorder traversal to assign heights, but since `high()` depends on the parent's height being already set, and the traversal goes top-down, it actually works for direct children. However, the real issue is that `f()` does not handle equal values (`p->num == item`). According to problem description, right child is for values >= root, but this code ignores duplicates (does nothing when equal), causing missing nodes. However, in given test input there are no duplicates, so this may not be the cause here. The main bug is in height assignment logic and traversal order interaction.]
    if (root->num != 12)
        bianli2(root);
    else
        printf("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4\n"); // @@ [This hardcoded branch suggests the program was patched to pass specific test cases, which is incorrect general logic. But since input root is 180 ≠ 12, this line isn't executed for the given test case, so not the direct cause of the observed WA.]
    return 0;
}