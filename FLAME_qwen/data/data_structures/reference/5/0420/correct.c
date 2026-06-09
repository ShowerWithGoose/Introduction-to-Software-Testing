#include<stdio.h>
#include<stdlib.h>
struct node
{
    int xs;
    int zs;
    struct node *link;
};
struct node *a=NULL,*b=NULL;

struct ys
{
    int ch;
    int sh;
}jg[100];

int cmp(const void* a,const void *b)
{
    return (*(struct ys*)a).sh<(*(struct ys*)b).sh?1:-1;
}

int hbtlx(struct ys *w,int e)
{
    int i,j;
    for(i=0;i<e-1;i++)
    {
        if(w[i].sh==w[i+1].sh)
        {
            w[i].ch+=w[i+1].ch;
            if(i==e-2)
            {
                e--;
                i--;
            }
            else
            {
                for(j=i+1;j<e-1;j++)
                {
                    w[j]=w[j+1];
                }
                e--;
                i--;
            }
        }
    }
    return e;
}

int main()
{
    struct node *r,*p,*c=NULL,*q,*k;
    char m;
    int i,j,h;
    do
    {
        r=(struct node*)malloc(sizeof(struct node));
        scanf("%d%d%c",&r->xs,&r->zs,&m);
        if(a==NULL)
        {
            a=p=r;
        }
        else
        {
            p->link=r;
            p=r;
        }
        p->link=NULL;
    }while(m!='\n');
    do
    {
        r=(struct node*)malloc(sizeof(struct node));
        scanf("%d%d%c",&r->xs,&r->zs,&m);
        if(b==NULL)
        {
            b=p=r;
        }
        else
        {
            p->link=r;
            p=r;
        }
        p->link=NULL;
    }while(m!='\n');
    for(p=b;p!=NULL;p=p->link)
    {
        for(r=a;r!=NULL;r=r->link)
        {
            q=(struct node*)malloc(sizeof(struct node));
            q->xs=r->xs*p->xs;
            q->zs=r->zs+p->zs;
            if(c==NULL)
            {
                c=k=q;
            }
            else
            {
                k->link=q;
                k=q;
            }
        }
    }
    k->link=NULL;
    for(i=0,p=c;p!=NULL;i++,p=p->link)
    {
        jg[i].ch=p->xs;
        jg[i].sh=p->zs;
    }
    qsort(jg,i,sizeof(jg[0]),cmp);
    h=hbtlx(jg,i);
    for(j=0;j<h;j++)
    {
        printf("%d %d ",jg[j].ch,jg[j].sh);
    }
    return 0;
}

