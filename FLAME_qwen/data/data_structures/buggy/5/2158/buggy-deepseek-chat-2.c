/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<stdlib.h>
struct mul{
    int a;
    int b;
};
int cmp(const void* p,const void* q)
{
    return ((struct mul*)q)->b-((struct mul*)p)->b;
}
int main()
{
    struct mul fir[205];
    struct mul sec[205];
    struct mul ret1[205];
    struct mul ret2[205];
    int i=0,j=0,k,ii,n=0,op=1,oop=0,m=0;
    char c;
    while(scanf("%d%d%c",&fir[i].a,&fir[i].b,&c))
    {
        if(c=='\n')
        {
            break;
        }
        else
        {
            i++;
        }
    }
    while(scanf("%d%d%c",&sec[j].a,&sec[j].b,&c))
    {
        if(c=='\n')
        {
            break;
        }
        else
        {
            j++;
        }
    }
    for(k=0;k<=i;k++) // @@ Error: Loop condition should be k < i (since i is the last index, not the count). The input loop increments i after reading each term, so i is the index of the last term, and the number of terms is i+1. However, the loop uses k <= i, which includes the last term correctly, but the issue is that the input loop may not increment i for the last term because it breaks before incrementing. Actually, after the break, i is the index of the last term read, so the number of terms is i+1. The loop condition k <= i is correct for iterating over all terms. The real error is that the arrays fir and sec are too small (size 205) for large inputs, but the problem states coefficients and exponents fit in int, not the number of terms. However, the main error is in the merging logic below.
    {
        for(ii=0;ii<=j;ii++) // @@ Error: Same issue as above; ii <= j is correct for the number of terms, but the merging logic is flawed.
        {
            ret1[n].a=fir[k].a*sec[ii].a;
            ret1[n].b=fir[k].b+sec[ii].b;
            n++;
        }
    }
    qsort(ret1,n-1,sizeof(struct mul),cmp); // @@ Error: The third argument to qsort should be n, not n-1. n is the number of elements, so it should be qsort(ret1, n, sizeof(struct mul), cmp);
    /*for(k=0;k<n;k++)
    {
        printf("%d %d ",ret1[k].a,ret1[k].b);
    }*/
    for(k=0;k<n;k++)
    {
        ret2[k].a=0;
    }
    ret2[0].a=ret1[0].a;
    ret2[0].b=ret1[0].b;
    ii=1;
    for(k=0;k<n;k++) // @@ Error: The loop condition k < n is correct, but the logic inside is flawed. It attempts to combine terms with the same exponent but uses incorrect indices and conditions. Specifically, the variable oop is supposed to count occurrences of different exponents, but it is reset incorrectly, and the condition (oop==2) is arbitrary. The merging should simply iterate through sorted ret1 and add coefficients when exponents match.
    {
        if(ret1[k].b!=ret1[k+1].b) // @@ Error: When k = n-1, ret1[k+1] accesses out-of-bounds memory, causing undefined behavior.
        {
            oop++;
        }
        else
        {
            op++;
        }
        if((oop==2)||((oop==1)&&(k+1==n))) // @@ Error: The condition is overly complex and incorrect. It does not correctly handle merging of consecutive terms with the same exponent.
        {
            if(k+1==n)
            {
                ret2[ii].a=ret1[n-1].a;
                ret2[ii].b=ret1[n-1].b;
            }
            else
            {
              for(i=1;i<=op;i++)
              {
                ret2[ii].a=ret2[ii].a+ret1[k-op+i].a;
              }
              ret2[ii].b=ret1[k].b;
              ii++;
              k--;
              op=1;
              oop=0;
            }
        }
    }
    while(ret2[m].a!=0) // @@ Error: This loop assumes that all non-zero coefficients are stored consecutively in ret2, but ret2 may have gaps (zero entries) due to incorrect merging. Also, if the result polynomial has a zero coefficient term, it will stop prematurely.
    {
        printf("%d %d ",ret2[m].a,ret2[m].b);
        m++;
    }
    return 0;
}