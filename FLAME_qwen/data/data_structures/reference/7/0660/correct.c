//
//  main.c
//  bst
//
//  Created by  on 2022/4/30.
//

/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXN 1005

typedef struct BTnode{
    int num;
    int layer;
    struct BTnode *lchild, *rchild;
}BTnode, *BTnodeptr;

BTnodeptr insertBST(BTnodeptr, int, int);
void print_leaf(BTnodeptr);

int main()
{
    int n, a, h=1;
    BTnodeptr root=NULL;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a);
        root=insertBST(root, a, h);
    }
    print_leaf(root);
    
    return 0;
}

BTnodeptr insertBST(BTnodeptr p, int item, int h)
{
    if (p==NULL)
    {
        p=(BTnodeptr)malloc(sizeof(BTnode));
        p->num=item;
        p->layer=h;
        p->lchild=p->rchild=NULL;
    }
    else
    {
        if (item>=p->num)
        {
            p->rchild=insertBST(p->rchild, item, h+1);
        }
        else if (item<p->num)
        {
            p->lchild=insertBST(p->lchild, item, h+1);
        }
    }
    return p;
}
void print_leaf(BTnodeptr p)
{
    if (p==NULL)
        return;
    else if (p->lchild==NULL && p->rchild==NULL)
    {
        printf("%d %d\n", p->num, p->layer);
        free(p);
    }
    else
    {
        print_leaf(p->lchild);
        print_leaf(p->rchild);
        free(p);
    }
}




