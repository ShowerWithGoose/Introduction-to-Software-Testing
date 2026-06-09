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
    for(i=0;i<num1+1;i++) // @@ The loop condition should be i<num1, not i<num1+1, because num1 is the index of the last term (i after the loop), so the number of terms is num1+1, but the loop already starts from 0, so it should go to i<=num1 or i<num1+1, but the issue is that num1 is the last index, so the correct number of iterations is num1+1, which is correct. However, the real error is that the input reading logic does not increment i for the last term because break happens before i++, so i is the index of the last term, meaning there are i+1 terms. So the loop should be i<=num1 or i<num1+1. This is actually correct. The error is elsewhere.
    {
        for(j=0;j<num2+1;j++) // @@ Similarly, this should be j<num2+1, which is correct for j being the last index. But the real error is that the multiplication loop uses i and j from 0 to num1 and num2 inclusive, which is correct. The problem is in the combination of like terms and sorting.
        {
            t[k].d=t1[i].d*t2[j].d;
            t[k].m=t1[i].m+t2[j].m;
            k++;
        }
    }
    for(i=0;i<k-1;i++) // @@ This loop only combines adjacent like terms after sorting, but the code does not sort the terms by exponent before combining. The combination loop assumes that like terms are adjacent, but they are not sorted, so it fails to combine all like terms correctly.
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
        printf("%d %d ",t[i].d,t[i].m); // @@ The output is not sorted in descending order of exponents as required. The code does not sort the terms before output, so the output order is arbitrary.
    }
    return 0;
}