#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int num;
    struct tree *lchild;
    struct tree *rchild;
} * treeptr;
treeptr root = NULL;
void makeNewNode(int i);
void LDRprint(treeptr a);
int ANSprint(treeptr a, int i);
int main()
{
    int n, i;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &i);
        makeNewNode(i);
    }
    //LDRprint(root);
    ANSprint(root, 1);
    return 0;
}

void makeNewNode(int i)
{
    treeptr p, a, b;
    p = (treeptr)malloc(sizeof(struct tree));
    p->num = i;
    p->lchild = NULL;
    p->rchild = NULL;
    if (root == NULL)
        root = p;
    else
    {
        a = root;
        while (a != NULL)
        {
            b = a;
            if (i < a->num)
                a = a->lchild;
            else if (i > a->num)
                a = a->rchild;
            else
            {
                if (a == root)
                    a = a->rchild;
                else
                    printf("error 1\n");
            }
        }
        if (i < b->num)
            b->lchild = p;
        else if (i > b->num)
            b->rchild = p;
    }
}

void LDRprint(treeptr a)
{
    if (a == NULL)
        return;
    LDRprint(a->lchild);
    printf("%d ", a->num);
    LDRprint(a->rchild);
}

int ANSprint(treeptr a, int i)
{
    if (a == NULL)
        return 1;
    if (ANSprint(a->lchild, i + 1) && ANSprint(a->rchild, i + 1))
        if (a->lchild == NULL && a->rchild == NULL)
            printf("%d %d\n", a->num, i);
    // return 0;
}


