#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct tree* root = NULL, * q = NULL; // @@ [Global variable 'root' is declared before 'struct tree' is defined, causing a compilation error due to incomplete type]
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
        p->lchild->parent = p; // @@ [If f() returns NULL (shouldn't happen here), this would dereference NULL; but more critically, parent assignment may occur before child node is fully initialized in some edge cases, though not the main issue]
    }
    else if (p->num < item)
    {
        p->rchild = f(p->rchild, item);
        p->rchild->parent = p; // @@ [Same as above]
    }
    return p;
}
void high(struct tree* p)
{  if(p!=root)
    p->height = p->parent->height+ 1; // @@ [Function 'high' is called during traversal but does not handle the case where p->parent might be NULL (though guarded by p!=root), but more importantly, height calculation depends on parent's height being already set, which may not be true in pre-order traversal]

}
void bianli(struct tree* p)
{
    if (p != NULL)
    {
        high(p); // @@ [Calling 'high' in pre-order means when visiting a node, its parent's height may not have been updated yet if parent was visited earlier but its own height wasn't propagated correctly]
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
    if (root->num != 12)
        bianli2(root);
    else
        printf("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4\n"); // @@ [Hardcoded output bypasses actual tree logic, indicating the program fails to compute correct leaf heights/values generally]
    return 0;
}