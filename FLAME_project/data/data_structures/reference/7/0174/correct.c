#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    int deep;
    struct tree *lchild;
    struct tree *rchild;
}*root,*p,*q;
//q=(struct monkey *)malloc(sizeof(struct monkey));
void inLookThrough(struct tree *t)
{
    if(t!=NULL)
    {
        inLookThrough(t->lchild);
        if(t->lchild==NULL&&t->rchild==NULL)
        printf("%d %d\n",t->data,t->deep);
        inLookThrough(t->rchild);
    }
}

int main()
{
    int n,i,in,d;
    scanf("%d",&n);
    // ‰»Î
    for(i=0;i<n;i++)
    {
        scanf("%d",&in);
        p=(struct tree *)malloc(sizeof(struct tree));
        p->data=in;
        p->lchild=NULL;
        p->rchild=NULL;
        if(root==NULL)
        {
            root=p;
            root->deep=1;
        }
        else
        {
            for(q=root,d=2;;)
            {
                if(in<q->data)
                {
                    if(q->lchild==NULL)
                    {
                        p->deep=d;
                        q->lchild=p;
                        break;
                    }
                    else
                    {
                        q=q->lchild;
                        d++;
                    }
                }
                else
                {
                    if(q->rchild==NULL)
                    {
                        p->deep=d;
                        q->rchild=p;
                        break;
                    }
                    else
                    {
                        q=q->rchild;
                        d++;
                    }
                }

            }
        }
    }
    //÷––Ú±È¿˙
    q=root;
    inLookThrough(q);
    return 0;
}

