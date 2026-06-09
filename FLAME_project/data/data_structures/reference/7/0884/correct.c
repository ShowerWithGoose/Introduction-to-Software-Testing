#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node
{
    int number;
    int high;
    struct node *lchild;
	struct node *rchild;
} btree;
btree *head;

btree *New(btree *T, int temp, int length)
{
    length++;
    if (T == NULL)
    {
        T = (btree *)malloc(sizeof(btree));
        T->number = temp;
        T->lchild = T->rchild = NULL;
        head = T;
        T->high = length;
    }
    else if (temp < T->number)
        T->lchild = New(T->lchild, temp, length);
    else if (temp >= T->number)
        T->rchild= New(T->rchild, temp, length);
    return T;
}

void bar(btree *T)
{
    if (T!=NULL)
    {
        if (T->lchild==NULL&& (T->rchild)==NULL)
        {
            printf("%d %d\n", T->number, T->high);
        }
        bar(T->lchild);
        bar(T->rchild);
    }
}     

int main()
{
    btree *T = NULL;
    int n, temp,i;
    scanf("%d", &n);
    for ( i = 0; i < n; i++) 
    {
        scanf("%d", &temp);

        int len = 0;
        T = New(T, temp, len);
    }
    bar(T);
    return 0;
}



