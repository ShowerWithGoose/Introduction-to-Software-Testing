#include <stdio.h>
#include <stdlib.h>
#define max 300
struct node
{
    struct node *lchild;
    struct node *rchild;
    int n;   // 存储数据
    int dep; // 存储该节点位于树中的深度
};
typedef struct node btnode;
typedef struct node *btree;
btree insert(btree T, int data, int dep)
{
    if (T == NULL)
    {
        T = (btree)malloc(sizeof(btnode));
        T->lchild = NULL;
        T->rchild = NULL;
        T->n = data;
        T->dep = dep;
    }
    else if (data < T->n)
        T->lchild = insert(T->lchild, data, dep + 1);
    else
        T->rchild = insert(T->rchild, data, dep + 1);
    //两点注意：
    //1.必须要写"T->l/rchild="insert...,这样才能够及时更新T的左右节点
    //因为C语言函数是值传递，不加上的话没法在函数外部改变
    //2.可以通过加第三个参数-dep,来记录当前二叉查找树中节点的深度
    return T;
}
void post_retrive(btree T) //后序遍历
{
    if (T != NULL)
    {
        post_retrive(T->lchild);
        post_retrive(T->rchild);
        if (T->lchild == NULL && T->rchild == NULL)
            printf("%d %d\n", T->n, T->dep);
    }
}
int main()
{
    int n;
    int data;
    btree T = NULL;
    scanf("%d", &n);
    // 组建二叉查找树
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        T = insert(T, data, 1); //必须要写"T="这样才能做到把值传递到函数外部，从而实现对T的更新
    }
    post_retrive(T);
}
