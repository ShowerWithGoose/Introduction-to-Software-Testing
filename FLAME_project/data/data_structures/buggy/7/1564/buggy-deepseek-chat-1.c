#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE *Root;
NODE *zhan[20];
int num;

void sortTree(int n);
void insertBST(int item);
void bian_li();
int height_node(NODE *,NODE *);
void destoryTree(NODE *p);

int main()
{
    int n;

    scanf("%d",&n);

    sortTree(n);
    bian_li();

    destoryTree(Root);
    return 0;
}

void sortTree(int n)//借助二叉查找树的插入实现树的建立（调用非递归）
{
    int k;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&k);
        insertBST(k);
    }
}

void insertBST(int item)//非递归进行二叉查找树的插入
{
    NODE *p,*q;
    p=(NODE *)malloc(sizeof(NODE));
    p->num=item;
    p->left=NULL;
    p->right=NULL;
    if(Root==NULL)
        Root=p;
    else
    {
        q=Root;
        while(1)
        {
            /* 比较值的大小 */
            /* 小于向左，大于向右 */
            if(item<q->num)
            {
                if(q->left==NULL)
                {
                    q->left=p;
                    break;
                }
                else
                    q=q->left;
            }
            else if (item>=q->num)
            {
                if(q->right==NULL)
                {
                    q->right=p;
                    break;
                }
                else
                    q=q->right;
            }
        }
    }
}

void bian_li()//遍历二叉树
{
    NODE *p = Root;

    num = -1;
    if(p!=NULL)
    {
        do
        {
            while(p!=NULL)
            {
                zhan[++num]=p;
                p=p->left;
            }
            p=zhan[num--];

            if(p->right == NULL)
            {
                printf("%d %d\n",p->num,height_node(Root,p));
            }

            p=p->right;
        }
        while(!(p==NULL && num==-1));
    }
}

int height_node(NODE *q,NODE *p)//二叉树的高度
{
    if(q->num == p->num)
    {
        if(q == p)
        {
            return 1;
        }
        else
        {
            return 1 + height_node(q->right,p); // @@ [Error: When q->num == p->num but q != p, this assumes the duplicate value is in the right subtree, but the BST definition puts duplicates in the right subtree. However, the height calculation should follow the actual path from root to node. Since duplicates are placed in the right subtree, this is correct for the given BST definition, but the bug is that the condition `q == p` is used to check if the node is found, which may fail if there are duplicate values because the first node with the same value might not be the correct one. The actual error is that the function does not correctly find the height for nodes with duplicate values because it compares by value first, and if values are equal, it assumes the node is in the right subtree, but the pointer comparison `q == p` may never be true if the duplicate is deeper. This leads to incorrect height calculation for nodes with duplicate values, causing the extra output "180 1" in the buggy output.]
        }
    }
    else if(p->num > q->num)
    {
        return 1 + height_node(q->right,p);
    }
    else
    {
        return 1 + height_node(q->left,p);
    }
}

void destoryTree(NODE *p)//二叉树的删除
{
    if(p != NULL)
    {
        destoryTree(p->left);
        destoryTree(p->right);
        free(p);
        p = NULL;
    }
}