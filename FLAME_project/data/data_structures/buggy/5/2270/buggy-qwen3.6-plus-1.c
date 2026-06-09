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
        if(c[i].n==c[i+1].n&&c[i].a!=-1) // @@ The condition `c[i].a!=-1` is incorrect logic for merging terms. It prevents merging if the current coefficient happens to be -1, and it doesn't handle the case where the accumulated sum becomes 0 correctly in the subsequent print loop. More importantly, it fails to merge all terms with the same exponent if there are more than 2, or if the first one was already marked. The standard approach is to accumulate into one and mark others as invalid, or use a different structure. However, the specific bug here leading to "0 0" in output is likely due to the next loop printing terms that should have been zeroed out or skipped because the merging logic is flawed.
        {
            c[i+1].a += c[i].a;
            c[i].a = -1;
        }
    }
    for(int i=0;i<k+1;i++) // @@ Loop bound `k+1` accesses `c[k]` which is out of bounds (valid indices are 0 to k-1). This can lead to undefined behavior, potentially printing garbage values like "0 0" if memory at `c[k]` happens to be zero.
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