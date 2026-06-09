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
    
    for(int i=0;i<k;i++) // @@ [Out-of-bounds access: when i == k-1, c[i+1] is beyond allocated array. Should be i<k-1 or handle separately.]
    {
        if(c[i].n==c[i+1].n&&c[i].a!=-1)
        {
            c[i+1].a += c[i].a;
            c[i].a = -1;
        }
    }
    for(int i=0;i<k+1;i++) // @@ [Off-by-one error: loop iterates to k+1, accessing uninitialized element c[k]. Should be i<k.]
    {
        if(c[i].a!=-1)
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