#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int datum,flat;
    struct node *lchild,*rchild,*parent;
}Tree,*Btree;
Btree Maketree(Btree root)
{
    int a;
    Btree p,q=root;
    scanf("%d",&a);
    p=(Btree)malloc(sizeof(Tree));
    p->datum=a;
    p->flat=0;
    p->lchild=p->rchild=NULL;
    if(q==NULL)
    {
        p->parent=NULL;
        root=p;
    }
    else
    {
        while(1)
        {
            if(p->datum<q->datum)
            {
                if(q->lchild==NULL)
                    {
                        q->lchild=p;
                        p->parent=q;
                        break;
                    }
                q=q->lchild;
            }
            else
            {
                if(q->rchild==NULL)
                    {
                        q->rchild=p;
                        p->parent=q;
                        break;
                    }
                q=q->rchild;
            }
        }
    }
    return root;
}
int main()
{
    int n,i,depth=1,time=0;
    Btree root=NULL,p;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        root=Maketree(root);
    }
    p=root;
    while(1)
    {
        if(time==n)
            break;
        if(p->flat==0)
        {
            if(p->lchild!=NULL)
                {
                    p->flat=1;
                    p=p->lchild;
                    depth++;
                }
            else if(p->rchild!=NULL)
            {
                p->flat=2;
                p=p->rchild;
                depth++;
            }
            else
                {
                    printf("%d %d\n",p->datum,depth);
                    p=p->parent;
                    depth--;
                    time++;
                }
        }
        else if(p->flat==1)
        {
            if(p->rchild!=NULL)
            {
                p->flat=2;
                p=p->rchild;
                depth++;
            }
            else
            {
                p=p->parent;
                depth--;
                time++;
            }
        }
        else
        {
            p=p->parent;
            depth--;
            time++;
        }
    }
    return 0;
}

