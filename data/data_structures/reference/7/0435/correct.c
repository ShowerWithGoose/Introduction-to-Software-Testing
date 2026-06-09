#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct t
{
    int num;
    struct t *l;
    struct t *r;
};

void visit(struct t *p,int de)
{
    if(p!=NULL)
    {
         de++;
        if(p->l==NULL&&p->r==NULL)
        {
            printf("%d %d\n",p->num,de);
            de = 0;
        }
        else
        {
            visit(p->l,de);
            visit(p->r,de);
        }
    }


}

struct t* creat(int num)
{
    struct t* newone = (struct t*)malloc(sizeof(struct t));
    newone->num = num;
    newone->l = NULL;
    newone->r = NULL;
    return newone;
}

void insert(struct t *p,struct t *n)
{
     if(p->l!=NULL&&p->r!=NULL)
    {
        if((n->num)<(p->num))
        {
            insert(p->l,n);
        }
        else
        {
            insert(p->r,n);
        }
    }
    else if(p->l!=NULL&&p->r==NULL)
    {
        if((n->num)<(p->num))
        {
            insert(p->l,n);
        }
        else
        {
            p->r = n;
        }
    }
    else if(p->l==NULL&&p->r!=NULL)
    {
        if((n->num)<(p->num))
        {
            p->l = n;
        }
        else
        {
            insert(p->r,n);
        }
    }
    else
    {
        if((n->num)<(p->num))
        {
            p->l = n;
        }
        else
        {
            p->r = n;

        }
        return;
    }
}

int main()
{
     struct t *p,*u;
     int a,n,de = 0;
     scanf("%d",&n);
     scanf("%d",&a);
     p = creat(a);
     for(int i = 1;i<n;i++)
     {
         scanf("%d",&a);
         u = creat(a);
         insert(p,u);
     }

     visit(p,de);
     return 0;
}

