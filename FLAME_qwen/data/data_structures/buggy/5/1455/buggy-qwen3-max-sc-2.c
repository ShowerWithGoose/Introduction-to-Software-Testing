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
        i++; // @@ [The increment happens after checking for newline, so the last valid term is stored at index i, but i is not incremented after the last term. This causes num1 = i to be one less than the actual number of terms.]
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
        j++; // @@ [Same issue as above: j is not incremented after reading the last term, leading to incorrect count of terms in second polynomial.]
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
    int num1=i; // @@ [Because i was not incremented after the last successful read, num1 is one less than the actual number of terms. Should be num1 = i + 1.]
    int num2=j; // @@ [Same issue: num2 should be j + 1 to include the last term read before the newline.]
    for(i=0;i<num1+1;i++) // @@ [This loop runs from 0 to num1 (inclusive), which is correct only if num1 was set properly. But since num1 = i (which missed the last increment), this may skip the last term or cause out-of-bound access if arrays were filled completely.]
    {
        for(j=0;j<num2+1;j++) // @@ [Same issue as above with num2.]
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
                t[j].d=0; // @@ [Setting coefficient to zero marks it for skipping later, but this approach doesn't merge all like terms correctly if more than two terms share the same exponent. Also, it leaves zeros in the array which are skipped later, but ordering is not handled.]
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(t[i].d==0)
        {
            continue;
        }
        printf("%d %d ",t[i].d,t[i].m); // @@ [Terms are not printed in descending order of exponents as required. The problem requires output in descending exponent order, but the current code outputs in the order of generation and merging, which is arbitrary.]
    }
    return 0;
}