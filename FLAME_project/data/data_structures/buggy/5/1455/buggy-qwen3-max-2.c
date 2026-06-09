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
        i++;
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
        j++;
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
    int num1=i; // @@ [After the first loop, 'i' is the index of the last valid term, but the loop breaks after incrementing 'i' only when newline is not encountered. However, when newline is encountered, 'i' is not incremented, so num1 = i is correct for count = i+1. But later loops use num1+1 which overcounts by 1.]
    int num2=j; // @@ [Same issue as above: num2 = j, then using num2+1 leads to accessing t2[j] which was never filled (since j stops at last valid index). This causes reading uninitialized data.]
    for(i=0;i<num1+1;i++) // @@ [Loop runs from 0 to num1 inclusive, but t1 has valid indices 0..num1 (total num1+1 terms), which is correct ONLY if num1 is the last index. However, due to input logic, if there's only one term, i remains 0 and num1=0, so this is okay. BUT the real bug is in combination with the next issue.]
    {
        for(j=0;j<num2+1;j++) // @@ [Same as above: accesses t2[num2], which may be uninitialized if the second polynomial input parsing left j as the last valid index (so t2[j] is valid), but if input ends immediately, j=0 and t2[0] is valid. So this might not be the core issue. The main problem is elsewhere.]
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
                t[j].d=0;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(t[i].d==0)
        {
            continue;
        }
        printf("%d %d ",t[i].d,t[i].m); // @@ [The output order is not sorted in descending exponent order. The problem requires terms to be printed in descending order of exponents, but this code outputs in the order of generation (which is based on input order of terms), leading to wrong sequence as seen in test case.]
    }
    return 0;
}