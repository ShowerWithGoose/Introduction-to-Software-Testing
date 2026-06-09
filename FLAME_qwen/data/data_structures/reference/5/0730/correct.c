#include <stdio.h>
struct poly
{
    int coe;
    int power;
}
a[1000],b[1000];
struct pol
{
    long long co;
    long long po;
    struct pol *p;
    struct pol *pre;
}
c[1000000],*q,end;
int m,n,i,j,k,l1,l2;
char ch;
int main()
{
    for(n=1,i=0;ch!='\n';i++)
    {
        scanf("%d%d%c",&m,&n,&ch);
        a[i].coe=m,a[i].power=n;
    }
    l1=i;
    ch=1;
    for(n=1,i=0;ch!='\n';i++)
    {
        scanf("%d%d%c",&m,&n,&ch);
        b[i].coe=m,b[i].power=n;
    }
    l2=i;
    k=-1;
    for(i=0;i<l1;i++)
    for(j=0;j<l2;j++)
    {
        m=a[i].coe*b[j].coe,n=a[i].power+b[j].power;
        k++;
        c[k].co=m,c[k].po=n;
        if(k==0)
        {
            end.pre=c;
            c[k].p=&end;
        }
        else
        {
            for(q=c;n<q->po;q=q->p)
            ;
            if(n==q->po)
            q->co=q->co+m;
            else
            {
                q->pre->p=&c[k];
                c[k].p=q;
                c[k].pre=q->pre;
                q->pre=&c[k];
            }
        }
    }
    for(q=c;q!=NULL&&q->co!=0;q=q->p)
    printf("%lld %lld ",q->co,q->po);
    return 0;
}

