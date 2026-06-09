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
        if(getchar()=='\n') // @@ Logical error: `getchar()` may read a space instead of newline if trailing whitespace exists, causing incorrect loop termination or `scanf` failure.
            break;
    }
    int len1=i+1;i=0; // @@ Off-by-one error: `i` already holds the term count, so `len1` should be `i`. Also, declaring variables after statements causes compilation errors in C89.
     for(i=0;;i++)
    {
        scanf("%d%d",&g[i].a,&g[i].b);
        if(getchar()=='\n') // @@ Logical error: same as above, `getchar()` may read whitespace instead of newline.
            break;
    }
    int len2=i+1;i=0; // @@ Off-by-one error: `len2` should be `i`. C89 declaration issue.

    for(i=0;i<len1;i++)
    {
      for(j=0;j<len2;j++)
      {
          k[u].a=(h[i].a)*(g[j].a);
          k[u].b=(h[i].b)+(g[j].b);
          u++;
      }
    }n=0;int temp; // @@ Declaring `int temp` after `n=0;` violates C89 standard, causing a compilation error.
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
            else if(k[n].b==k[j].b) // @@ Logical error: merging coefficients here leaves zeroed terms in the array, disrupting sort order and causing premature output termination.
            {
                k[n].a+=k[j].a;
                k[j].a=0;
                k[j].a=0; // @@ Redundant assignment.
            }
        }

    }
    n=0;

    for(n=0;n<u&&k[n].a!=0;n++) // @@ Logical error: stops printing at the first zero coefficient. If a zero-coefficient term is swapped forward, valid terms are skipped.
        printf("%d %d ",k[n].a,k[n].b);
    return 0;
}