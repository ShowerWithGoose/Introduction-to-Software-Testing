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
        i++; @@ // The increment of i happens after checking for newline, so the last valid term is stored at index i, but i is not incremented after the last term. This causes num1 = i to be one less than the actual number of terms.
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
        j++; @@ // Same issue as above: j is not incremented after reading the last term, so num2 = j undercounts the number of terms by 1.
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
    int num1=i; @@ // Because i was not incremented after the last successful read, num1 is one less than the actual count of terms in t1.
    int num2=j; @@ // Same issue: num2 is one less than the actual count of terms in t2.
    for(i=0;i<num1+1;i++)
    {
        for(j=0;j<num2+1;j++)
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
                t[j].d=0; @@ // Setting coefficient to zero instead of removing the term can lead to printing zero-coefficient terms if not handled carefully later, but more critically, this merging logic is flawed because it doesn't handle cases where multiple terms have the same exponent beyond pairwise merging.
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(t[i].d==0)
        {
            continue;
        }
        printf("%d %d ",t[i].d,t[i].m); @@ // Output order is not guaranteed to be in descending exponent order as required by the problem.
    }
    return 0;
}