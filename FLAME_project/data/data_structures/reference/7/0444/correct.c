#include<stdio.h>
struct node
{
    int a;
    int b;
    struct node *lchild,*rchild;
};
typedef struct node form;
void print(form *root)
{
    if(root!=NULL)
    {
        if(root->lchild==NULL&&root->rchild==NULL)
        {
            printf("%d %d\n",root->a,root->b);
        }
        print(root->lchild);
        print(root->rchild);
    }
}
int main()
{
    int  n;
    int m[200];
    int y=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&m[i]);
    }
    form *p,*q;
    form *root=NULL;
    p=(int *)malloc(sizeof(form));
    root=p;
    p->a=m[y++];
    p->b=1;
    p->lchild=NULL;
    p->rchild=NULL;
    while(y<n)
    {
        q=root;
        p=(int *)malloc(sizeof(form));
        p->a=m[y++];
        p->b=1;
        p->lchild=NULL;
        p->rchild=NULL;
        while(1)
        {
            if(m[y-1]<q->a)
            {
                p->b++;
                if(q->lchild==NULL)
                {
                    q->lchild=p;
                    break;
                }
                else
                    q=q->lchild;
            }
            else if(m[y-1]>=q->a)
            {
                p->b++;
                if(q->rchild==NULL)
                {
                    q->rchild=p;
                    break;
                }
                else
                    q=q->rchild;
            }
        }
    }
    print(root);
    return 0;
}

