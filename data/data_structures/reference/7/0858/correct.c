#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *l, *r;
} BTNode, *BTNodeptr;
BTNodeptr insertBST(BTNodeptr, int, int);
typedef struct TEMP
{
    int data;
    int count;
} Temp;
Temp datacount[1024];
int datatemp[1024];
void postOrder(BTNodeptr);
int dataSearch(int[], int, int);
int n;
int main()
{
    int i, item;
    scanf("%d", &n);
    BTNodeptr root = NULL;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &item);
        datacount[i].data = item;
        datacount[i].count = 1;
        root = insertBST(root, item, i);
    }
    for (i = 0; i < n; i++)
    {
        datatemp[i] = datacount[i].data;
    }
    postOrder(root);
    system("pause");
    return 0;
}
BTNodeptr insertBST(BTNodeptr p,int item, int i)
{
    int flag = i;
    if(p==NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->l = p->r = NULL;
    }
    else if(item<p->data)
    {
        datacount[flag].count++;
        p->l = insertBST(p->l, item, flag);
    }
    else if(item>=p->data)
    {
        datacount[flag].count++;
        p->r = insertBST(p->r, item, flag);
    }
    return p;
}
void postOrder(BTNodeptr T)
{
    if(T==NULL)
        return;
    postOrder(T->l);
    postOrder(T->r);
    if(T->l==NULL&&T->r==NULL)
    {
        printf("%d %d\n", T->data, dataSearch(datatemp, T->data, n));
    }
}
int dataSearch(int key[],int keynum, int n)
{
    int i;
    for (i = 1; i < n; i++)
        if (key[i] == keynum)
            return datacount[i].count;
    return 1;
}
