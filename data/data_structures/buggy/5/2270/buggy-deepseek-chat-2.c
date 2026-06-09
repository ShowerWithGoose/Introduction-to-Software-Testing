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
        if(c[i].n==c[i+1].n&&c[i].a!=-1) // @@ [Error: When i reaches k-1, c[i+1] accesses out-of-bounds memory, causing undefined behavior. Also, the condition c[i].a!=-1 is incorrect; it should check if the term has not been merged, but using -1 as a sentinel may fail if coefficients can be -1. The reference program uses p[i].data=0 to mark merged terms.]
        {
            c[i+1].a += c[i].a;
            c[i].a = -1;
        }
    }
    for(int i=0;i<k+1;i++) // @@ [Error: The loop runs to k+1, which is one iteration too many, accessing c[k] which is out-of-bounds. The correct bound should be i<k.]
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