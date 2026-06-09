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
    int num1=i;
    int num2=j;
    for(i=0;i<num1+1;i++) // @@ The loop condition should be i<num1, not i<num1+1, because num1 is the index of the last term (starting from 0), so the number of terms is num1+1, but the loop already starts from 0, so it should iterate num1+1 times, which is i<=num1 or i<num1+1. However, the issue is that after the input loop, i is incremented one extra time after the break, so i equals the number of terms. Thus, num1 = i (number of terms), and the loop should be i<num1, not i<num1+1. This causes an out-of-bounds access to t1[num1] which is uninitialized.
    {
        for(j=0;j<num2+1;j++) // @@ Same issue: num2 is the number of terms in t2, so the loop should be j<num2, not j<num2+1.
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
        printf("%d %d ",t[i].d,t[i].m);
    }
    return 0;
}