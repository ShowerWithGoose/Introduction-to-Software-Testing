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
                k[j].a=0; // @@ [The logic here attempts to merge terms with same exponent by setting the duplicate's coefficient to 0. However, this only works correctly if the array is subsequently sorted or filtered properly. The current sorting/merging logic is flawed because it mixes sorting and merging in a single pass without ensuring that all like terms are adjacent before merging, or it fails to handle the case where merged terms might need further merging if not processed in a stable sorted order. More critically, the subsequent print loop relies on k[n].a != 0, but the sorting logic above is unstable and incorrect for grouping all like terms together before zeroing them out. Specifically, if k[n] merges with k[j], k[j] becomes 0. But if there was another term k[m] with the same exponent later in the unsorted part, it won't be merged with k[n] because the inner loop moves forward. The standard approach is to sort first, then merge adjacent duplicates. Here, the "sort" is happening simultaneously with merging, which is buggy.]
                k[j].a=0;
            }
        }

    }
    n=0;

    for(n=0;n<u&&k[n].a!=0;n++) // @@ [This loop prints terms until it hits a zero coefficient. However, because the previous merging step didn't fully consolidate all like terms (due to the flawed single-pass merge/sort), there may be non-zero terms with lower exponents that appear AFTER zeroed-out terms in the array, or the array isn't fully sorted by exponent in descending order due to the swap logic interacting poorly with the zeroing logic. The primary issue is that the algorithm doesn't correctly sort and merge. A correct approach would be: 1. Generate all product terms. 2. Sort all terms by exponent descending. 3. Iterate through sorted terms, summing coefficients of adjacent terms with same exponent. 4. Print non-zero results. The current code fails to produce the correct output because the merging is incomplete and the final order is not guaranteed to be strictly descending for all terms, especially when zeros are interspersed.]
        printf("%d %d ",k[n].a,k[n].b);
    return 0;
}