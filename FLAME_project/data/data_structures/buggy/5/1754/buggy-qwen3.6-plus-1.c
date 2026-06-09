#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct duoxiangshi
{
    int a,b;
};
int cmp(const void *p1,const void *p2)
{
    struct duoxiangshi x,y;
    x=*(struct duoxiangshi *)p1;y=*(struct duoxiangshi *)p2;
    if(x.b>y.b)
        return 1;
    if(x.b<y.b)
        return -1;
    else
        return 0;
}
int main()
{
    int i=0,n,j=0,u=0;
    struct duoxiangshi h[100005],g[100005],k[100005];
    for(i=0;;i++)
    {
        scanf("%d%d",&h[i].a,&h[i].b);
        if(getchar()=='\n')
            break;
    }
    int len1=i+1;i=0;
     for(i=0;;i++)
    {
        scanf("%d%d",&g[i].a,&g[i].b);
        if(getchar()=='\n')
            break;
    }
    int len2=i+1;i=0;

    for(i=0;i<len1;i++)
    {
      for(j=0;j<len2;j++)
      {
          k[u].a=(h[i].a)*(g[j].a);
          k[u].b=(h[i].b)+(g[j].b);
          u++;
      }
    }n=0;int temp;
     for(n=0;n<u;n++)
    {
        for(j=n+1;j<u;j++)
        {
            if(k[n].b<k[j].b)
            {
                temp=k[n].b;
                k[n].b=k[j].b;
          k[j].b=temp;
                temp=k[n].a;
                k[n].a=k[j].a;
                k[j].a=temp;
            }
            else if(k[n].b==k[j].b)
            {
                k[n].a+=k[j].a;
                k[j].a=0; // @@ [The logic for merging terms with the same exponent is flawed. When k[j].a becomes 0, it is not removed from the array or marked as invalid. In the subsequent printing loop, these zero-coefficient terms might be skipped if the condition is k[n].a!=0, but the sorting and merging process leaves "holes" or unprocessed zeros in the middle of the array. More critically, if multiple terms share the same exponent, this pairwise comparison might not aggregate them all correctly into k[n] if they are not adjacent after partial swaps, or it leaves zeroed-out entries that disrupt the contiguous non-zero assumption of the final print loop. However, the primary issue causing Wrong Answer here is likely that the zeroed-out terms remain in the array `k`. The final loop `for(n=0;n<u&&k[n].a!=0;n++)` stops printing as soon as it hits a term with coefficient 0. If a merged term results in a 0 coefficient (e.g., cancellation) or if a zeroed-out duplicate is encountered before valid terms with lower exponents, the output is truncated. Given the expected output has many terms, and the buggy output is truncated, it suggests that a zero coefficient (from the `k[j].a=0` assignment) appears in the sorted order before some valid terms, causing the loop to terminate early.]
                k[j].a=0;
            }
        }

    }
    n=0;

    for(n=0;n<u&&k[n].a!=0;n++)
        printf("%d %d ",k[n].a,k[n].b);
    return 0;
}