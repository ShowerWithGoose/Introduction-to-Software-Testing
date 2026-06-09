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
    for(i=0;i<num1+1;i++) // @@ The loop condition should be i < num1, not i < num1+1, because num1 is the index of the last element (i after the loop), so the number of elements is num1+1, but the loop starts from 0, so it should go to i <= num1 or i < num1+1, but the original input loop increments i after the last element, so num1 is the last index, meaning there are num1+1 elements. However, the loop uses i < num1+1, which is correct for iterating over all elements (0 to num1 inclusive). The error is that the input loop increments i after the last element, so i ends up as the index of the last element, not the count. Actually, let's re-analyze: In the input loop, i starts at 0, and after reading the first term, i becomes 1, but the break occurs before incrementing i for the last term? No, the code increments i after each term, including the last one, because the break is after the increment. So after the loop, i is the index of the last term plus 1, meaning i equals the number of terms. So num1 = i (number of terms), and the loop should be for(i=0; i < num1; i++), not i < num1+1. This causes an out-of-bounds access.
    {
        for(j=0;j<num2+1;j++) // @@ Similarly, the loop condition should be j < num2, not j < num2+1, for the same reason.
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