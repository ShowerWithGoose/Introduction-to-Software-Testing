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
    for(i1=0;i1<=i;i1++) // @@ Error: The loop condition should be i1 < i, not i1 <= i, because i is the index of the last term read (with exponent 0), and the loop should include that term. However, the input reading logic breaks when exponent 0 is read, so i points to the term with exponent 0. The loop should go up to i inclusive, but the condition i1 <= i is correct for including the last term. The actual error is that the input reading logic incorrectly breaks after reading exponent 0 without incrementing i, so i is the index of the term with exponent 0, but the loop should process it. This is fine. The real issue is that the input reading does not handle the case where the polynomial has only one term (exponent 0) correctly, but for this test case, the problem is different. The main error is that the input reading for the second polynomial uses the same break condition, but the test case input has two terms with exponent 1000000000, not 0, so the while loop never breaks, causing an infinite loop or reading beyond input. The input format expects terms until a newline, but the code breaks only when exponent is 0, which is incorrect for this test case.
    {
        for(j1=0;j1<=j;j1++) // @@ Error: Same issue as above; the loop condition should be j1 < j, but j is the index of the last term read. However, the input reading for the second polynomial uses while(1) and breaks on exponent 0, but the test case input does not have exponent 0, so the loop never breaks, leading to undefined behavior. The correct approach is to read until newline, not until exponent 0.
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
        while((a[j].ms==a[i].ms)&&j<n-1&&a[i].ms!=-1) // @@ Error: The condition j < n-1 should be j < n to avoid accessing out-of-bounds when j equals n-1. Also, the while loop may skip combining all consecutive equal exponents because it only checks j < n-1, missing the last pair.
        {
            a[i].xs+=a[j].xs;
            a[j].ms=-1;
            j++;
        }
    }
}