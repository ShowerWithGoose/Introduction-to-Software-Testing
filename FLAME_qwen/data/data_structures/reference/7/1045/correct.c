#include <stdio.h>
#include <stdlib.h>
typedef struct NODE NODE;
struct NODE
{
    int value;
    int deep;
    NODE *l;
    NODE *r;
};
NODE *createNode(int deep, int value)
{
    NODE *node;
    node = (NODE *)malloc(sizeof(NODE));
    node->deep = deep;
    node->value = value;
    node->l = NULL;
    node->r = NULL;
    return node;
}
int num[100000];
NODE *tree = NULL;
void Insert(NODE **now, int value)
{
    if ((*now) == NULL)
    {
        (*now) = createNode(1, value);
        //printf("%d:%d\n", (*now)->deep, value);
        return;
    }
    if (value < (*now)->value)
    {
        if ((*now)->l == NULL)
        {
            (*now)->l = createNode((*now)->deep + 1, value);
            //printf("%d:%d\n", (*now)->deep + 1, value);
            return;
        }
        else
        {
            Insert(&((*now)->l), value);
            return;
        }
    }
    else
    {
        if ((*now)->r == NULL)
        {
            (*now)->r = createNode((*now)->deep + 1, value);
            return;
        }
        else
        {
            Insert(&((*now)->r), value);
            return;
        }
    }
}
void Print(NODE **now)
{
    if ((*now)->l == NULL && (*now)->r == NULL)
    {
        printf("%d %d\n", (*now)->value, (*now)->deep);
        return;
    }
    if ((*now)->l != NULL)
        Print(&((*now)->l));
    if ((*now)->r != NULL)
        Print(&((*now)->r));
}
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (int i = 0; i < n; i++)
        Insert(&tree, num[i]);
    Print(&tree);
    return 0;
}
