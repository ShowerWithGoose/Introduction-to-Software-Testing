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
    for(k=0;k<=i;k++)
    {
        for(ii=0;ii<=j;ii++)
        {
            ret1[n].a=fir[k].a*sec[ii].a;
            ret1[n].b=fir[k].b+sec[ii].b;
            n++;
        }
    }
    qsort(ret1,n-1,sizeof(struct mul),cmp); // @@ The number of elements to sort should be n, not n-1. Using n-1 leaves the last element unsorted.
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
    for(k=0;k<n;k++) // @@ Loop condition allows k to reach n-1, causing ret1[k+1] to access out-of-bounds memory in the next line.
    {
        if(ret1[k].b!=ret1[k+1].b) // @@ Out-of-bounds array access when k equals n-1.
        {
            oop++;
        }
        else
        {
            op++;
        }
        if((oop==2)||((oop==1)&&(k+1==n)))
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
              k--; // @@ Modifying the loop variable k inside the for loop disrupts iteration and can cause infinite loops or skipped elements.
              op=1;
              oop=0;
            }
        }
    }
    while(ret2[m].a!=0) // @@ Using coefficient != 0 as termination condition is incorrect because valid terms might have zero coefficients after cancellation, or uninitialized memory might be non-zero. Should track the actual number of terms.
    {
        printf("%d %d ",ret2[m].a,ret2[m].b);
        m++;
    }
    return 0;
}