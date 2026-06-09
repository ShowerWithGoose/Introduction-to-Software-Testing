#include <stdio.h>
#include <stdlib.h>
typedef struct _term
{
    int a;
    int x;
}terms,*pterm;
terms term1[50];
terms term2[50];
terms term3[50]; // @@ [The array size 50 is too small. Multiplying two polynomials with up to 50 terms each can produce up to 2500 terms before combining like terms, leading to buffer overflow.]
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
    scanf("%d%d",&a0,&x0); // @@ [This assumes at least two terms in the first polynomial. If the first polynomial has only one term, this reads into the second polynomial's input, causing misinterpretation.]
    while(x0<term1[i].x) // @@ [This loop condition assumes input terms are given in strictly descending order and that there are more terms. It fails if the next term belongs to the second polynomial or if input ends early.]
    {
        term1[i].a=a0;
        term1[i].x=x0;
        i++;
        scanf("%d%d",&a0,&x0);
    }
    n=i;
    term2[j].a=a0;
    term2[j].x=x0; // @@ [This uses the last read pair (a0,x0) which may be the first term of the second polynomial, but if the first polynomial had only one term, this incorrectly consumes the first term of the second polynomial without checking for newline/EOF separation.]
    j++;
    while(scanf("%d%d",&a0,&x0)!=EOF) // @@ [This loop does not stop at newline; it continues until EOF, which means it will consume all remaining input including potential extra data, but more critically, it doesn't handle the case where input ends with newline correctly on all systems. Also, if the first polynomial parsing consumed part of the second, this logic breaks.]
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
    for(k=h-1;k>=0;k--) // @@ [The comparison function `cmp` returns (x1 - x2), which sorts in ascending order. Printing from h-1 down to 0 gives descending order, which is correct. However, if multiple terms have the same exponent and cancel out (sum to zero), they are still printed, violating the requirement to only output non-zero terms.]
    {
        printf("%d %d ",term3[k].a,term3[k].x);
    }
    return 0;
}