#include<stdio.h>

struct team
{
    int d;
    int m;
};
int main()
{
    struct team t1[1000];
    struct team t2[1000];
    struct team t[1000];
    int i=0;
    char c;
    while(1)
    {
        scanf("%d",&t1[i].d);
        scanf("%d",&t1[i].m);
        scanf("%c",&c);
        if(c=='\n')
        {
            break;
        }
        i++; // @@ [The increment of i happens after checking for newline, so the last valid index is not counted correctly. This causes num1 = i to be one less than the actual number of terms.]
    }
    int j=0;
    while(1)
    {
        scanf("%d",&t2[j].d);
        scanf("%d",&t2[j].m);
        scanf("%c",&c);
        if(c=='\n')
        {
            break;
        }
        j++; // @@ [Same issue as above: j is incremented only when newline is not encountered, so the final term's index is not included in j.]
    }
    
//    for(;i>=0;i--)
//    {
//        printf("%d %d\n",t1[i].d,t1[i].m);
//    }
//    for(;j>=0;j--)
//    {
//        printf("%d %d\n",t2[j].d,t2[j].m);
//    }
    int k=0;
    int num1=i; // @@ [num1 should be i+1 because the loop breaks without incrementing i for the last term. Same applies to num2.]
    int num2=j; // @@ [num2 should be j+1 for the same reason.]
    for(i=0;i<num1+1;i++) // @@ [This uses num1+1 which may accidentally compensate, but logic is flawed due to incorrect num1/num2. Also, if input has only one term, i starts at 0 and num1 is 0, so this runs once — which is correct — but the root cause remains.]
    {
        for(j=0;j<num2+1;j++) // @@ [Same issue as above.]
        {
            t[k].d=t1[i].d*t2[j].d;
            t[k].m=t1[i].m+t2[j].m;
            k++;
        }
    }
    for(i=0;i<k-1;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(t[i].m==t[j].m)
            {
                t[i].d=t[i].d+t[j].d;
                t[j].d=0; // @@ [Setting coefficient to zero instead of removing the term can lead to printing zero-coefficient terms later if not handled properly. However, the print loop skips zero coefficients, so this may not be a direct error, but it's inefficient and fragile.]
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(t[i].d==0)
        {
            continue;
        }
        printf("%d %d ",t[i].d,t[i].m); // @@ [Output is not sorted in descending order of exponents as required by the problem statement.]
    }
    return 0;
}