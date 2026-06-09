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
    for(k=0;k<=i;k++) @@ // Error: loop should run from 0 to i (inclusive), but i is the index of last valid element; however, due to input logic, i is not incremented after last term, so this actually includes one extra invalid term.
    {
        for(ii=0;ii<=j;ii++) @@ // Same error as above: j is not incremented after last term, so <=j accesses an uninitialized element.
        {
            ret1[n].a=fir[k].a*sec[ii].a;
            ret1[n].b=fir[k].b+sec[ii].b;
            n++;
        }
    }
    qsort(ret1,n-1,sizeof(struct mul),cmp); @@ // Error: should sort 'n' elements, not 'n-1'. This skips the last term in sorting.
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
        if(ret1[k].b!=ret1[k+1].b) @@ // Error: when k == n-1, ret1[k+1] is out-of-bounds access.
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
              k--;
              op=1;
              oop=0;
            }
        }
    }
    while(ret2[m].a!=0) @@ // Error: assumes ret2 is null-terminated with a zero coefficient, but ret2 may contain non-zero coefficients followed by uninitialized or zero values arbitrarily; also, if all terms cancel out, nothing is printed, but loop condition fails immediately.
    {
        printf("%d %d ",ret2[m].a,ret2[m].b);
        m++;
    }
    return 0;
}