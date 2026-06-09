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
        if((dxs1[i].ms)==0) // @@ The loop breaks when exponent is 0, meaning the term with exponent 0 is read but not processed in the multiplication loop correctly if it's the last term, or rather, the logic assumes 0 exponent terminates input which is incorrect per problem description (input ends with newline, not necessarily exponent 0). More critically, for the test case "8 1000000000", the exponent is not 0, so it continues. But wait, the test case input is just one term per polynomial? No, "8 1000000000" is one term. The next scanf will wait. The problem says input ends with newline. This logic `if((dxs1[i].ms)==0) break;` is fundamentally flawed because it assumes the last term always has exponent 0, which is not true. It should check for newline or EOF.
        {
            break;
        }
        i++;
    }
    while(1)
    {
        scanf("%lld%lld",&dxs2[j].xs,&dxs2[j].ms);
        if((dxs2[j].ms)==0) // @@ Same error as above: assumes termination on exponent 0.
        {
            break;
        }
        j++;
    }
    for(i1=0;i1<=i;i1++)
    {
        for(j1=0;j1<=j;j1++)
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
        while((a[j].ms==a[i].ms)&&j<n-1&&a[i].ms!=-1) // @@ The condition `j<n-1` prevents checking the last element `a[n-1]` for merging with `a[i]`. It should be `j<n`. Also, accessing `a[j]` when `j` can equal `n` (if corrected to `j<n`) needs care, but here `j` starts at `i+1`. If `i` is `n-2`, `j` is `n-1`. `j<n-1` fails. So the last element is never merged into the previous one if they match.
        {
            a[i].xs+=a[j].xs;
            a[j].ms=-1;
            j++;
        }
    }
}