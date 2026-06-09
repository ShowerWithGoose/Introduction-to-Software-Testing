#include <stdio.h>
#include <stdlib.h>
typedef struct _term
{
    int a;
    int x;
}terms,*pterm;
terms term1[50];
terms term2[50];
terms term3[50];
int cmp(const void* p1,const void*p2)
{
    int ans;
    pterm line1=(pterm)p1;
    pterm line2=(pterm)p2;
    ans=line1->x-line2->x;
    return ans;
}
int main()
{
    int i=0,j=0;
    int a0,x0;
    int m,n;
    int h=0,k;
    int xsum,asum;
    scanf("%d%d",&a0,&x0);
    term1[i].a=a0;
    term1[i].x=x0;
    i++;
    scanf("%d%d",&a0,&x0);
    while(x0<term1[i].x)  // @@ [Incorrect condition: term1[i].x is uninitialized/zero, and the loop should read all terms until newline, not compare exponents.]
    {
        term1[i].a=a0;
        term1[i].x=x0;
        i++;
        scanf("%d%d",&a0,&x0);
    }
    n=i;
    term2[j].a=a0;  // @@ [Uses leftover a0 from the first polynomial (the constant term) instead of starting to read the second polynomial properly.]
    term2[j].x=x0;  // @@ [Same as above: x0 is the exponent of the first polynomial's constant term, not the first term of the second polynomial.]
    j++;
    while(scanf("%d%d",&a0,&x0)!=EOF)  // @@ [Does not stop on newline; relies on EOF. Should read until newline similar to the first polynomial.]
    {
        term2[j].a=a0;
        term2[j].x=x0;
        j++;
    }
    m=j;
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            asum=term2[j].a*term1[i].a;
            xsum=term2[j].x+term1[i].x;
            for(k=0;k<h;k++)
            {
                if(term3[k].x==xsum)
                {
                    term3[k].a=term3[k].a+asum;
                    break;
                }
            }
            if(k==h)
            {
                term3[h].x=xsum;
                term3[h].a=asum;
                h++;
            }
        }
    }
    qsort(term3,h,sizeof(term3[0]),cmp);
    for(k=h-1;k>=0;k--)
    {
        printf("%d %d ",term3[k].a,term3[k].x);
    }
    return 0;
}