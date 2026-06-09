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
    int len1=i+1;i=0; // @@ [len1 should be i, not i+1, because i was incremented after the last valid input before breaking]
     for(i=0;;i++)
    {
        scanf("%d%d",&g[i].a,&g[i].b);
        if(getchar()=='\n')
            break;
    }
    int len2=i+1;i=0; // @@ [len2 should be i, not i+1, for the same reason as len1]

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
                k[j].a=0;
                k[j].a=0; // @@ [This line is redundant; also, setting k[j].a=0 twice doesn't fix the fact that later terms with same exponent may not be merged correctly due to unsorted order and incomplete combination logic]
            }
        }

    }
    n=0;

    for(n=0;n<u&&k[n].a!=0;n++) // @@ [Loop stops at first zero coefficient, but non-zero terms might appear later due to incomplete merging of like terms; also, output must include all non-zero terms regardless of position]
        printf("%d %d ",k[n].a,k[n].b);
    return 0;
}