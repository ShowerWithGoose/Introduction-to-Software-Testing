#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//二叉树
struct TreeNode
{
    int data;
    struct TreeNode *Lchild, *Rchild;
};
typedef struct TreeNode BTNode, *BTNodeptr;
//销毁
void destroyBT(BTNodeptr newNode)
{
    if (newNode != NULL)
    {
        destroyBT(newNode->Lchild);
        destroyBT(newNode->Rchild);
        free(newNode);
        newNode = NULL;
    }
}
//遍历
void preorder(BTNodeptr t, int height)
{

    if (t != NULL)
    {
        if (t->Lchild == NULL && t->Rchild == NULL)
            printf("%d %d\n", t->data, height);
        preorder(t->Lchild, height + 1);
        preorder(t->Rchild, height + 1);
    }
}
//插入
BTNodeptr head = NULL; // 根
void insertBST(int item)
{
    BTNodeptr newNode, temp;
    newNode = (BTNodeptr)malloc(sizeof(BTNode));
    newNode->data = item;
    newNode->Lchild = NULL;
    newNode->Rchild = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        temp=head;
        while(1)
        {
            if(item<temp->data)
            {
                if(temp->Lchild==NULL) {temp->Lchild=newNode;break;}
                else temp=temp->Lchild;
            }
            else 
            {
                if(temp->Rchild==NULL) {temp->Rchild=newNode;break;}
                else temp=temp->Rchild;
            }
            
        }
    }
}
int main()
{
    int n, data;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d",&data);
     insertBST(data);
    }
    preorder(head,1);
    destroyBT(head);
    return 0;
}


