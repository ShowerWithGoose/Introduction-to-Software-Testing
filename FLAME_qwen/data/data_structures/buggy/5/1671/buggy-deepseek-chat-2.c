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
    for(i1=0;i1<=i;i1++) // @@ Error: Loop condition should be i1 < i, not i1 <= i, because i is the index of the last term read (exponent 0), and the loop should process all terms including the one with exponent 0. However, the input reading logic breaks when exponent is 0, so the term with exponent 0 is stored at index i, and the loop should include it. But the condition i1 <= i causes an off-by-one error if the polynomial has only the constant term (exponent 0), as i would be 0 and the loop runs once correctly. The real issue is that the input reading logic incorrectly breaks on exponent 0, which may cause the last term (constant) to be processed but then the loop increments i after break, leading to i being the index of the constant term. The loop condition i1 <= i is actually correct to include that term. However, the problem is that the input format does not guarantee that the last term has exponent 0; it could be any term. The reference program reads all terms until newline, not stopping at exponent 0. This code incorrectly assumes the last term has exponent 0 and breaks, which may miss subsequent terms. This is a logical error in input reading.
    {
        for(j1=0;j1<=j;j1++) // @@ Error: Same issue as above; loop condition should be j1 < j, but due to input reading logic, j is the index of the constant term. However, the input reading is flawed as it breaks on exponent 0, which may not be the last term.
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
        while((a[j].ms==a[i].ms)&&j<n-1&&a[i].ms!=-1) // @@ Error: The condition j < n-1 should be j < n to avoid accessing out-of-bounds when j equals n-1. Also, the while loop may skip the last element if it has the same exponent as the previous one.
        {
            a[i].xs+=a[j].xs;
            a[j].ms=-1;
            j++;
        }
    }
}