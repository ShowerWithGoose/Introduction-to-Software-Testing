#include <stdio.h>
#include <stdlib.h>
typedef struct _term
{
    int a;
    int x;
}terms,*pterm;
terms term1[50];
terms term2[50];
terms term3[50]; // @@ [The array size 50 is too small; multiplying two polynomials with up to 50 terms each can produce up to 2500 terms, leading to buffer overflow.]
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
    scanf("%d%d",&a0,&x0); // @@ [This assumes at least two terms in the first polynomial; fails if the first polynomial has only one term.]
    while(x0<term1[i].x) // @@ [Logic error: assumes input is given in descending order and tries to validate it, but problem does not guarantee multiple terms or this loop condition being safe (term1[i] is uninitialized on first loop entry). Also, the loop condition uses uninitialized term1[i].x.]
    {
        term1[i].a=a0;
        term1[i].x=x0;
        i++;
        scanf("%d%d",&a0,&x0);
    }
    n=i;
    term2[j].a=a0;
    term2[j].x=x0;
    j++;
    while(scanf("%d%d",&a0,&x0)!=EOF) // @@ [Incorrect EOF handling: scanf returns number of successfully read items, not EOF directly. Should check if return value != 2. Also, mixing newline-terminated input with EOF causes issues.]
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
    for(k=h-1;k>=0;k--) // @@ [The cmp function sorts in ascending order by exponent, so printing from h-1 to 0 gives descending order — this part is correct. However, if there are zero-coefficient terms (due to cancellation), they are not removed, violating the requirement to output only non-zero terms.]
    {
        printf("%d %d ",term3[k].a,term3[k].x);
    }
    return 0;
}