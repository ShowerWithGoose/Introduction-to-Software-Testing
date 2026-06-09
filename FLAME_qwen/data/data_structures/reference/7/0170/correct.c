#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *lft;
    struct node *rit;
} * bst, bstval;
bst root, current, prev;
typedef struct nd
{
    int stage;
    int num;
} leaf;
leaf leaves[1000];
int ileaves;

void bstin()
{
    bst tmpbst;
    int tmpnum, lftflg = 1;
    scanf("%d", &tmpnum);
    tmpbst = root;
    while (tmpbst != NULL)
    {
        //printf("%d ",tmpbst->num);
        //printf("1\n");
        prev = tmpbst;
        if (tmpnum >= tmpbst->num)
        {
            tmpbst = tmpbst->rit;
            lftflg = 0;
        }
        else{
            tmpbst = tmpbst->lft;
            lftflg=1;
        }
    }
    current = (bst)malloc(sizeof(bstval));
    if (root == NULL)
    {
        root = current;
    }
    else
    {
        if (lftflg == 0)
            prev->rit = current;
        else
            prev->lft = current;
    }
    current->num = tmpnum;
    current->lft=NULL;
    current->rit=NULL;
}

void dfsbst(bst tmpp, int x)
{
    if (tmpp == NULL)
    {
        return;
    }
    //printf("%d %d\n", tmpp->num, x);
    if ((tmpp->lft == NULL) && (tmpp->rit == NULL))
    {
        leaves[ileaves].num = tmpp->num;
        leaves[ileaves++].stage = x;
        //printf("%d %d\n", tmpp->num, x);
    }
    dfsbst(tmpp->lft, x + 1);
    dfsbst(tmpp->rit, x + 1);
}
int main()
{
    //freopen("bstin.txt", "r", stdin);
    int n, i;
    scanf("%d", &n);
    while (n--)
    {
        //printf("!");
        bstin();
    }
    dfsbst(root, 1);
    for (i = 0; leaves[i].stage > 0; i++)
    {
        printf("%d %d\n", leaves[i].num, leaves[i].stage);
    }
    return 0;
}
