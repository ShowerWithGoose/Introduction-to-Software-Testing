#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct Node{
    int data;
    int h;
    struct Node* lchild;
    struct Node* rchild;
}*root;
void preorder(struct Node* p)
{
    if(p!=NULL)
    {
        if(p->rchild==NULL&&p->lchild==NULL)
        {
            printf("%d %d\n",p->data,p->h);
        }
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int main()
{
    int n,a[10000],i=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a[i++]);
    }
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=a[0];
    root->h=1;
    root->lchild=NULL;
    root->rchild=NULL;
    n=i;
    for(i=1;i<n;i++)
    {
        insert(root,a[i]);
    }
    preorder(root);
}
void insert(struct Node *p,int data)
{
    struct Node *r,*q;
    q=(struct Node*)malloc(sizeof(struct Node));
    q->data=data;
    q->lchild=NULL;
    q->rchild=NULL;
    q->h=1;
    r=p;
    while(1)
    {
        if(data<r->data)
        {
            if(r->lchild!=NULL)
            {
                r=r->lchild;
                (q->h)++;
            }
            else
            {
                r->lchild=q;
                (q->h)++;
                break;
            }
        }
        else
        {
            if(r->rchild!=NULL)
            {
                r=r->rchild;
                (q->h)++;
            }
            else
            {
                r->rchild=q;
                (q->h)++;
                break;
            }
        }
    }
}

