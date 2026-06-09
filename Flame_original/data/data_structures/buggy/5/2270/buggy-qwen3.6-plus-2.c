#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int cmp(const void*p,const void*q);

struct list
{
    int a;
    int n;
};

int main()
{
    struct list a[10000],b[10000],c[10000];
    int op = 0;
    char ca;
    
    do
    {
        scanf("%d%d%c",&a[op].a,&a[op].n,&ca);
        op++;
    }while(ca!='\n');
    int len1 = op;
    op = 0;
    do
    {
        scanf("%d%d%c",&b[op].a,&b[op].n,&ca);
        op++;
    }while(ca!='\n');
    int len2 = op;
    int k = 0;
    
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            c[k].a = a[i].a*b[j].a;
            c[k].n = a[i].n + b[j].n;
            k++;
        }
    }
    
    qsort(c,k,sizeof(struct list),cmp);
    
    for(int i=0;i<k;i++)
    {
        if(c[i].n==c[i+1].n&&c[i].a!=-1) // @@ Out-of-bounds access when i=k-1; also -1 is a valid coefficient and cannot be used as a marker for merged terms.
        {
            c[i+1].a += c[i].a;
            c[i].a = -1; // @@ Incorrect marker: -1 is a valid coefficient. Should use 0 to mark terms that have been merged or are zero.
        }
    }
    for(int i=0;i<k+1;i++) // @@ Loop condition i<k+1 accesses c[k] which is out of bounds and uninitialized. Should be i<k.
    {
        if(c[i].a!=-1) // @@ Should check c[i].a != 0 to correctly filter out zero/merged terms, consistent with the corrected marker.
        {
            printf("%d %d ",c[i].a,c[i].n);
        }
    }
    
     return 0;
}
int cmp(const void*p,const void*q)
{
    struct list *a = (struct list*)p;
    struct list *b = (struct list*)q;
    return b->n - a->n;
}