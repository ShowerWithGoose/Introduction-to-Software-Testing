#include<stdio.h>
#include<stdlib.h>
struct node{int data;
            int height;
            struct node *lchild,*rchild;
            };
typedef struct node BTnode,*BTnodeptr;
BTnodeptr queue[500];
int front=-1;
void preorder(BTnodeptr t)
{
    if(t!=NULL)
    {
        if(t->lchild==NULL&&t->rchild==NULL)
        {
            front++;
            queue[front]=t;
        }
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void deletetree(BTnodeptr t)
{
    if(t!=NULL)
    {
        deletetree(t->lchild);
        deletetree(t->rchild);
        free(t);
        t=NULL;
    }
}
int main()
{
    int n,i,a[500],x;
    BTnodeptr root=NULL,p;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        x=1;
        if(root==NULL)
        {
            root=(BTnodeptr)malloc(sizeof(BTnode));
            root->data=a[i];
            root->height=1;
            root->lchild=root->rchild=NULL;
            continue;
        }
        else
        {
            p=root;
            while(1)
            {
                x++;
                if(a[i]>=(p->data))
                {
                    if(p->rchild!=NULL)
                    {
                        p=p->rchild;
                    }
                    else
                    {
                        p->rchild=(BTnodeptr)malloc(sizeof(BTnode));
                        (p->rchild)->data=a[i];
                        (p->rchild)->height=x;
                        (p->rchild)->lchild=(p->rchild)->lchild=NULL;
                        break;
                    }
                }
                else
                {
                    if(p->lchild!=NULL)
                    {
                        p=p->lchild;
                    }
                    else
                    {
                        p->lchild=(BTnodeptr)malloc(sizeof(BTnode));
                        (p->lchild)->data=a[i];
                        (p->lchild)->height=x;
                        (p->lchild)->lchild=(p->lchild)->lchild=NULL;
                        break;
                    }
                }
            }
        }
    }
    preorder(root);
    for(i=0;i<=front;i++)
    {
        printf("%d %d\n",queue[i]->data,queue[i]->height);
    }
    deletetree(root);
    return 0;
}

