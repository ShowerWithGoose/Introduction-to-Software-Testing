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
    }
    while(1)
    {
        scanf("%lld%lld",&dxs2[j].xs,&dxs2[j].ms);
        if((dxs2[j].ms)==0)
        {
            break;
        }
        j++;
    }
    for(i1=0;i1<=i;i1++) // @@ Error: The loop condition should be i1 < i (not <= i) because i is the index of the last term read, and the term with exponent 0 was already read and stored at index i, but the loop should include all terms from 0 to i inclusive. However, the input reading logic breaks when exponent 0 is read, so the term with exponent 0 is stored at index i, and i is not incremented after that. Thus the loop should be i1 <= i to include that term. But the problem is that the input format may have multiple terms with exponent 0? Actually, the input ends with exponent 0, so there is exactly one term with exponent 0. The loop condition i1 <= i is correct to include it. However, the error is that the loop should be i1 <= i, but the original code has i1 <= i, which is correct. Wait, let me re-check: The while loop reads a term, then checks if ms==0, if so breaks without incrementing i. So the term with exponent 0 is stored at index i, and i is not incremented. So the number of terms is i+1. The loop for(i1=0;i1<=i;i1++) correctly iterates over all terms. So this line is actually correct. The error might be elsewhere.
    {
        for(j1=0;j1<=j;j1++) // @@ Error: Same logic as above, j1 <= j is correct because j is the index of the last term (exponent 0) and not incremented after reading it.
        {
            dxs3[k].xs=(dxs1[i1].xs)*(dxs2[j1].xs);
            dxs3[k].ms=(dxs1[i1].ms)+(dxs2[j1].ms);
            k++;
        }
    }
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
        while((a[j].ms==a[i].ms)&&j<n-1&&a[i].ms!=-1) // @@ Error: The condition j < n-1 should be j < n to avoid accessing out-of-bounds when j equals n-1. Also, the while loop may skip over multiple terms with the same exponent, but it only checks the next term; it should continue while j < n and a[j].ms == a[i].ms. Additionally, after merging, the loop should skip the merged terms, but the current logic may miss some.
        {
            a[i].xs+=a[j].xs;
            a[j].ms=-1;
            j++;
        }
    }
}