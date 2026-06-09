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

void sortTree(int n)
{
    int k;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&k);
        insertBST(k);
    }
}

void insertBST(int item)
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

void bian_li()
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

            if(p->right == NULL) // @@ 叶子节点判断错误：只检查右子树为空，应改为左右子树均为空
            {
                printf("%d %d\n",p->num,height_node(Root,p));
            }

            p=p->right;
        }
        while(!(p==NULL && num==-1));
    }
}

int height_node(NODE *q,NODE *p)
{
    if(q->num == p->num)
    {
        if(q == p)
        {
            return 1;
        }
        else
        {
            return 1 + height_node(q->right,p);
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

void destoryTree(NODE *p)
{
    if(p != NULL)
    {
        destoryTree(p->left);
        destoryTree(p->right);
        free(p);
        p = NULL;
    }
}