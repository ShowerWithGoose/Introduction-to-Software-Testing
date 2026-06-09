#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define eps 1e-9
struct duo
{
    long long xs;
    long long ms;
};
void sort(struct duo a[],int n);
void hb(struct duo a[],int n);
struct duo dxs1[1024];
struct duo dxs2[1024];
struct duo dxs3[1024];
int main()
{
    int i=0;
    int j=0,k=0;
    int i1=0,j1=0;
    while(1)
    {
        scanf("%lld%lld",&dxs1[i].xs,&dxs1[i].ms);
        if((dxs1[i].ms)==0)
        {
            break;
        }
        i++;
    } @@ [The loop breaks when exponent is 0, but the problem allows constant term (exponent 0) as valid input. This causes premature termination and misses the last term if it's a constant term.]
    while(1)
    {
        scanf("%lld%lld",&dxs2[j].xs,&dxs2[j].ms);
        if((dxs2[j].ms)==0)
        {
            break;
        }
        j++;
    } @@ [Same issue: breaks on exponent 0, missing the constant term of the second polynomial.]
    for(i1=0;i1<=i;i1++)
    {
        for(j1=0;j1<=j;j1++)
        {
            dxs3[k].xs=(dxs1[i1].xs)*(dxs2[j1].xs);
            dxs3[k].ms=(dxs1[i1].ms)+(dxs2[j1].ms);
            k++;
        }
    } @@ [Loop bounds are off-by-one: should be i1 < i and j1 < j because i and j point to the first unused index after reading, not inclusive. Also, since the previous loops may have skipped the exponent-0 term, the data itself is incomplete.]
    //for(i=0;i<k;i++)
    //{
    //    if(dxs3[i].ms!=-1)
    //    {
    //        printf("%d %d",dxs3[i].xs,dxs3[i].ms);
    //    }
    //}
    sort(dxs3,k);
    hb(dxs3,k);
    for(i=0;i<k;i++)
    {
        if((dxs3[i].ms)!=-1&&(dxs3[i].xs)!=0)
        {
            printf("%lld %lld ",dxs3[i].xs,dxs3[i].ms);
        }
    }
    return 0;
}
void sort(struct duo a[],int n)
{
    struct duo temp;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i].ms<a[j].ms)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void hb(struct duo a[],int n)
{
    int i;
    int j;
    for(i=0;i<n;i++)
    {
        j=i+1;
        while((a[j].ms==a[i].ms)&&j<n-1&&a[i].ms!=-1)
        {
            a[i].xs+=a[j].xs;
            a[j].ms=-1;
            j++;
        }
    } @@ [The merging logic is flawed: it only merges consecutive duplicates and stops at j < n-1, so the last element is never merged even if it has the same exponent as a[i]. Also, it doesn't handle non-consecutive duplicates because the array may not be fully sorted before merging (but sort() is called before hb(), so that part is okay). However, the condition j < n-1 prevents checking the last element.]
}