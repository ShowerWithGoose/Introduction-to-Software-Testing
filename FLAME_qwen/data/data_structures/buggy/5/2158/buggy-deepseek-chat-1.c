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
    for(k=0;k<=i;k++) // @@ Error: The loop condition should be k < i (or k <= i-1) because i is the index of the last element, not the count. The input loop increments i after reading each term, so after reading the last term and breaking, i is the index of the last term. Thus the number of terms is i+1, and the loop should run from 0 to i inclusive, which is correct. However, the same logic applies to j below, but the issue is that the arrays fir and sec are declared with size 205, and the input may exceed this, but the main error is in the merging logic later.
    {
        for(ii=0;ii<=j;ii++) // @@ Error: Same as above, the loop condition should be ii < j (or ii <= j-1) but actually j is the index of the last element, so the number of terms is j+1, so ii <= j is correct. However, the real problem is that the arrays are too small (205) for large inputs, but the test case may not trigger that. The critical error is in the subsequent merging logic.
        {
            ret1[n].a=fir[k].a*sec[ii].a;
            ret1[n].b=fir[k].b+sec[ii].b;
            n++;
        }
    }
    qsort(ret1,n-1,sizeof(struct mul),cmp); // @@ Error: The second argument to qsort should be the number of elements, which is n, not n-1. This causes the last element to be excluded from sorting, leading to incorrect order.
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
    for(k=0;k<n;k++)
    {
        if(ret1[k].b!=ret1[k+1].b) // @@ Error: When k = n-1, ret1[k+1] accesses out-of-bounds memory (ret1[n]), which is undefined behavior. This can cause incorrect comparison and potential crash.
        {
            oop++;
        }
        else
        {
            op++;
        }
        if((oop==2)||((oop==1)&&(k+1==n))) // @@ Error: The condition (oop==1)&&(k+1==n) is intended to handle the last group, but due to the out-of-bounds access above, the logic is flawed. Additionally, the merging logic is overly complex and incorrect; it does not properly combine terms with the same exponent.
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
    while(ret2[m].a!=0) // @@ Error: This loop assumes that all non-zero coefficients are stored consecutively in ret2, but ret2 may contain zero coefficients from uninitialized or incorrectly merged terms. Also, if the result polynomial has zero coefficients (e.g., all terms cancel), this loop may never terminate or skip valid terms.
    {
        printf("%d %d ",ret2[m].a,ret2[m].b);
        m++;
    }
    return 0;
}