#include <stdio.h>
#include <stdlib.h>
typedef struct _term
{
    int a;
    int x;
}terms,*pterm;
terms term1[50];
terms term2[50];
terms term3[50]; // @@ [The size of term3 is too small. Multiplying two polynomials with up to 50 terms each can produce up to 2500 terms before combining like terms, but term3 only has space for 50 terms, leading to buffer overflow.]
int cmp(const void* p1,const void*p2)
{
    int ans;
    pterm line1=(pterm)p1;
    pterm line2=(pterm)p2;
    ans=line1->x-line2->x;
    return ans; // @@ [The comparison function returns negative when line1->x < line2->x, which sorts in ascending order. However, the output requires descending order of exponents, so this logic is inverted. Also, qsort expects a negative, zero, or positive value indicating less than, equal, or greater than; while this works numerically, it may cause integer overflow if exponents are large.]
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
    scanf("%d%d",&a0,&x0); // @@ [This assumes there are at least two terms in the first polynomial. If the first polynomial has only one term, this second scanf will read from the second polynomial, causing incorrect parsing.]
    while(x0<term1[i].x) // @@ [This condition assumes input terms are given in strictly descending order and that the next term has a smaller exponent. However, the problem does not guarantee input order, and this loop condition is flawed: term1[i] was never initialized before comparing with x0. This leads to undefined behavior.]
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
    while(scanf("%d%d",&a0,&x0)!=EOF) // @@ [This loop reads until EOF, but the input specification says each polynomial ends with a newline. If the second polynomial ends with a newline (not EOF), this loop may fail to terminate correctly or consume extra input. Also, on some systems, scanf may not return EOF immediately after newline, leading to infinite loop or incorrect reads.]
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
    for(k=h-1;k>=0;k--) // @@ [Because cmp sorts in ascending order, printing from h-1 down to 0 gives descending exponents, which matches the requirement. However, if cmp were fixed to sort descending, this loop would be wrong. But given current cmp, this is correct. However, if there are zero-coefficient terms (which can result from cancellation), they are not removed, violating the requirement to only output non-zero terms.]
    {
        printf("%d %d ",term3[k].a,term3[k].x);
    }
    return 0;
}