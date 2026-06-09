#include <stdio.h>
#include <stdlib.h>

typedef struct inttree
{
    int ele;
    struct inttree *lc, *rc;
} inttree;

inttree *inputtree(inttree *curp, int ele)
{
    if (curp == NULL)
    {
        curp = (inttree *)malloc(sizeof(inttree));
        curp->lc = curp->rc = NULL;
        curp->ele = ele;
    }
    else if (curp->ele <= ele)
    {
        curp->rc = inputtree(curp->rc, ele);
    }
    else
    {
        curp->lc = inputtree(curp->lc, ele);
    }
    return curp;
}

void inttreeprint(inttree *curp, int height)
{
    if (curp != NULL)
    {
        inttreeprint(curp->lc, height + 1);
        if(curp->lc==curp->rc)
        printf("%d %d\n", curp->ele, height);
        inttreeprint(curp->rc, height+1);
    }
    return;
}

int main()
{
    int n, ele;
    inttree *gen = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        gen = inputtree(gen, ele);
    }
    inttreeprint(gen, 1);
}
