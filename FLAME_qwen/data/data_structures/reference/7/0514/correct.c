#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
int data;
int h;
struct node *lchild;
struct node *rchild;
}BNnode, *BNnodeptr;

BNnode *creatnode()
{
    BNnodeptr p;
    p=(BNnodeptr)malloc(sizeof(BNnode));
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}
BNnodeptr root = NULL;
/*int height (int a)
{
    int k=1;
    BNnodeptr r=root;
    while((r->data!=a)||(r->lchild!=NULL)||(r->rchild!=NULL))
    {
        k++;
        if (a<r->data)
            r = r->lchild;
        if (a>r->data)
            r = r->rchild;
    }
    return k;
}*/
void print(BNnodeptr p)
{
    if((p->lchild==NULL)&&(p->rchild==NULL))
    {
        printf("%d %d\n", p->data, p->h);
    }
    else
    {
        if (p->lchild!=NULL)
            print(p->lchild);
        if (p->rchild!=NULL)
            print(p->rchild);
    }
}
int main()
{
    int a, i, num, flag, h=1;
    BNnodeptr p=NULL;
    BNnodeptr r=NULL, t=NULL;
    scanf("%d", &num);
    for (i=0; i<num; i++)
    {
        scanf("%d", &a);
        if(root==NULL)
        {
            root = creatnode();
            root->data=a;
            root->h = 1;
        }
        else
        {
            r = root;
            while (1)
            {
                if (a >= r->data)
                {
                    if (r->rchild==NULL)
                    {
                        flag=0;
                        h++;
                        break;
                    }
                    else
                        r = r->rchild;
                }
                else if (a < r->data)
                {
                    if (r->lchild==NULL)
                    {
                        flag=1;
                        h++;
                        break;
                    }
                    else
                        r = r->lchild;
                }
                h++;
            }
            p = creatnode();
            p->data = a;
            p->h = h;
            if (flag==0)
                r->rchild = p;
            else
                r->lchild = p;
            h = 1;
        }
    }
    print(root);

    return 0;
}

