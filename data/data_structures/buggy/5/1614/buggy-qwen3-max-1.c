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
    ans=line1->x-line2->x; // @@ [The comparison function returns negative when line1->x < line2->x, which sorts in ascending order. However, the output requires descending order of exponents, so this logic is inverted. Also, qsort expects a return value that is negative, zero, or positive; while this works numerically, it may cause overflow if values are large, though not the main issue here.]
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
    scanf("%d%d",&a0,&x0); // @@ [This assumes there are at least two terms in the first polynomial. If the first polynomial has only one term, this second scanf will read from the second polynomial, causing incorrect parsing.]
    while(x0<term1[i].x) // @@ [This loop condition assumes input terms are given in strictly descending order and tries to validate that. However, the problem does not guarantee input order, and more critically, if the next input belongs to the second polynomial (e.g., after a newline), x0 could be anything, leading to undefined behavior or infinite loop. Also, term1[i].x is uninitialized on first iteration of this loop (i was incremented but term1[i] wasn't set before comparison).]
    {
        term1[i].a=a0;
        term1[i].x=x0;
        i++;
        scanf("%d%d",&a0,&x0);
    }
    n=i;
    term2[j].a=a0;
    term2[j].x=x0; // @@ [This assigns leftover a0,x0 (which may actually be the start of the second polynomial or even invalid) into term2[0], but if the first polynomial had only one term, this is correct; however, due to earlier flawed reading logic, this is unreliable.]
    j++;
    while(scanf("%d%d",&a0,&x0)!=EOF) // @@ [This reads until EOF, but the input specification says the second polynomial ends with a newline, not necessarily EOF. On many systems, interactive input or test cases may not send EOF immediately after the newline, but more critically, if the first polynomial parsing consumed part of the second, this may miss terms or include garbage. Also, if input ends without trailing newline, behavior is undefined. Moreover, scanf returns number of successfully matched items, so checking !=EOF is insufficient; should check ==2.]
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
    for(k=h-1;k>=0;k--) // @@ [This prints in reverse order to compensate for ascending sort, but if the comparison function were fixed to sort descending, this would be unnecessary. However, due to earlier issues in input parsing and term3 size, this may print incorrect or incomplete results.]
    {
        printf("%d %d ",term3[k].a,term3[k].x);
    }
    return 0;
}