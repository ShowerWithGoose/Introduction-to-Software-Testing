#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} BTree;
BTree *first;
BTree *New(BTree *T, int temp, int flag); //新建节点
void print(BTree *T);                   //打印叶节点
int main()
{
    BTree *T = NULL;
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) //创建树
    {
        scanf("%d", &temp);

        int flag = 0;
        T = New(T, temp, flag);
    }
    print(T);
    return 0;
}
BTree *New(BTree *T, int temp, int flag)
{
    flag++;
    if (T == NULL)
    {
        T = (BTree *)malloc(sizeof(BTree));
        T->data = temp;
        T->left = T->right = NULL;
        first = T;
        T->high = flag;
    }
    else if (temp < T->data)
        T->left = New(T->left, temp, flag);
    else if (temp >= T->data)
        T->right = New(T->right, temp, flag);
    return T;
}
void print(BTree *T)
{
    if (T!=NULL)
    {
        if ((T->left==NULL) && (T->right==NULL))
        {
            printf("%d %d\n", T->data, T->high);
        }
        print(T->left);
        print(T->right);
    }
}

