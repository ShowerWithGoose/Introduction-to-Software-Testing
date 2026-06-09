#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct node{
    int num;
    struct node *lchild, *rchild;
    int depth;
} tree, *ptree;
void preread(ptree b);//前序遍历
int main()
{
    tree a;
    ptree p;
    p = &a;
    a.lchild = NULL;
    a.rchild = NULL;
    int n, i, j,tmp;//n为输入整数个数
    scanf("%d", &n);
    scanf("%d", &a.num);
    a.depth = 1;
    for (i = 0; i < n-1;i++)
    {
        scanf("%d", &tmp);
        j = 1;
        while (((p->lchild!=NULL)&&(p->num>tmp))||((p->rchild!=NULL)&&(p->num<=tmp)))
        {
            if ((p->lchild!=NULL)&&(p->num>tmp))
                p = p->lchild;
            else if (((p->rchild!=NULL)&&(p->num<=tmp)))
                p = p->rchild;
            j++;
        }
        if (tmp<p->num)
        {
            p->lchild = (ptree)malloc(sizeof(tree));
            p->lchild->lchild = NULL;
            p->lchild->rchild = NULL;
            p->lchild->num = tmp;
            j++;
            p->lchild->depth = j;
            p = &a;
        }
        else
        {
            p->rchild = (ptree)malloc(sizeof(tree));
            p->rchild->lchild = NULL;
            p->rchild->rchild = NULL;
            p->rchild->num = tmp;
            j++;
            p->rchild->depth = j;
            p = &a;
        }
    }//读入数据
    p = &a;
    preread(p);
    return 0;
}
void preread(ptree b)
{
    if (b!=NULL)
    {
        if (b->lchild==NULL&&b->rchild==NULL)
        {
            printf("%d %d\n", b->num, b->depth);
        }
        preread(b->lchild);
        preread(b->rchild);
    }
}
