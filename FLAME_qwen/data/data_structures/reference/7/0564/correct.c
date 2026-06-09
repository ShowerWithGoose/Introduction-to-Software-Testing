#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct btn
{
    int data;
    int h;
    struct btn *r,*l;
};
void preorder(struct btn *t)
{
    if(t!=NULL)
    {
        if(t->l==NULL&&t->r==NULL) printf("%d %d\n",t->data,t->h);
        preorder(t->l);
        preorder(t->r);
    }
}
int main()
{
    int n,x,i;
    struct btn *t=NULL,*p,*q;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        p=(struct btn*)malloc(sizeof(struct btn));
        p->data=x;
        p->h=1;
        p->l=p->r=NULL;
        if(t==NULL)
        {
            t=p;
            //t->h=1;
        }
        else
        {
            q=t;
            while(1)
            {
                if(x<q->data)
                {
                    if(q->l==NULL)
                    {
                        q->l=p;
                        p->h++;
                        break;
                    }
                    else
                    {
                        q=q->l;
                        p->h++;
                    }
                }
                else
                {
                    if(q->r==NULL)
                    {
                        q->r=p;
                        p->h++;
                        break;
                    }
                    else
                    {
                        q=q->r;
                        p->h++;
                    }
                }
            }
        }
    }
    preorder(t);
    return 0;
}











