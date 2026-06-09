#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
    int data;
    struct node *lchild,*rchild;
};
typedef struct node bstnode,*bstptr;
bstptr insertbst(bstptr t,int num);//t树num元素
void bianli(bstptr t);
int h = 1;
int main()
{
    int n, i, num;
    bstptr t = NULL;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &num);
        t = insertbst(t, num);
    }
    bianli(t);
    return 0;
}

bstptr insertbst(bstptr t, int num)
{
    if(t == NULL)
    {
        t = (bstptr)malloc(sizeof(bstnode));
        t -> data = num;
        t -> lchild = NULL;
        t -> rchild = NULL;
    }//根节点
    else if(num < t -> data)
    {
        t -> lchild = insertbst(t -> lchild, num);
    }
    else if(num >= t -> data)
    {
        t -> rchild = insertbst(t -> rchild, num);
    }
    return t;
}
void bianli(bstptr t)//遍历叶结点
{
    if(t == NULL)
        return;
    else
    {
        if(t -> lchild == NULL && t -> rchild == NULL)//叶结点
            printf("%d %d\n", t -> data, h);
        h++;
        bianli(t -> lchild);
        bianli(t -> rchild);
        h--;
    }
}




