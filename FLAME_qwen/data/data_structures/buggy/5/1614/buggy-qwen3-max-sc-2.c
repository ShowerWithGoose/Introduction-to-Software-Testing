#include <stdio.h>
#include <stdlib.h>
typedef struct _term
{
    int a;
    int x;
}terms,*pterm;
terms term1[50];
terms term2[50];
terms term3[50]; // @@ [The size of term3 is too small. When multiplying two polynomials with up to 50 terms each, the product can have up to 2500 terms before combining like terms. This causes buffer overflow.]
int cmp(const void* p1,const void*p2)
{
    int ans;
    pterm line1=(pterm)p1;
    pterm line2=(pterm)p2;
    ans=line1->x-line2->x; // @@ [The comparison function returns negative when line1->x < line2->x, which sorts in ascending order. But output requires descending order of exponents. Also, qsort expects negative/zero/positive for less/equal/greater, but this implementation may cause integer overflow if values are large.]
    return ans;
}
int main()
{
    int i=0,j=0;
    int a0,x0;
    int m,n;
    int h=0,k;
    int xsum,asum;
    scanf("%d%d",&a0,&x0); // @@ [Does not check return value of scanf. If input fails (e.g., empty input), behavior is undefined.]
    term1[i].a=a0;
    term1[i].x=x0;
    i++;
    scanf("%d%d",&a0,&x0); // @@ [Assumes at least two terms in first polynomial. Fails if first polynomial has only one term.]
    while(x0<term1[i].x) // @@ [Logic assumes input is given in strictly descending order and tries to read until order breaks. However, problem does not guarantee number of terms, and this loop condition is flawed: term1[i] is uninitialized on first iteration of loop. Also, it doesn't handle end-of-line correctly.]
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
    while(scanf("%d%d",&a0,&x0)!=EOF) // @@ [This loop reads until EOF, but problem states that each polynomial ends with a newline. If second polynomial ends with newline (not EOF), this will block waiting for more input or fail. Also, after reading last term of second polynomial, the next scanf may fail or read garbage.]
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
    for(k=h-1;k>=0;k--) // @@ [Because cmp sorts in ascending order by exponent, printing from h-1 to 0 gives descending order. However, if cmp had been correct for descending, this would be wrong. But due to earlier error in cmp, this accidentally compensates. However, if multiple terms have same exponent and cancel out (sum to zero), they are still printed, violating "only non-zero terms" requirement.]
    {
        printf("%d %d ",term3[k].a,term3[k].x);
    }
    return 0;
}