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
        insert(T->lchild, data, dep + 1); // @@ [The recursive call returns a new node, but the result is not assigned to T->lchild, so the left subtree is never updated]
    else
        insert(T->rchild, data, dep + 1); // @@ [The recursive call returns a new node, but the result is not assigned to T->rchild, so the right subtree is never updated]
    return T;
}
void post_retrive(btree T)
{
    if (T != NULL)
    {
        post_retrive(T->lchild);
        post_retrive(T->rchild);
        if (T->lchild == NULL && T->rchild == NULL)
            printf("%d %d", T->n, T->dep); // @@ [Missing newline after each output line as required by the problem statement]
    }
}
int main()
{
    int n;
    int data[max];
    btree T = NULL;
    scanf("%d", &n);
    // 组建二叉查找树
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
        T = insert(T, data[i], 1);
    }
    post_retrive(T);
}