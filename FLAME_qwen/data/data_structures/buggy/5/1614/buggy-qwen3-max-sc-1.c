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
    return ans; // @@ [The comparison function returns positive when line1->x > line2->x, which sorts in ascending order. However, the output requires descending order of exponents, so this logic is inverted.]
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
    scanf("%d%d",&a0,&x0); // @@ [This assumes there are at least two terms in the first polynomial. If the first polynomial has only one term, this second scanf will read from the second polynomial or fail, causing incorrect parsing.]
    while(x0<term1[i].x) // @@ [This condition assumes input terms are given in strictly descending order and tries to validate that, but the problem does not guarantee multiple terms or strict ordering during input reading. Also, term1[i].x is uninitialized on first loop iteration (i was incremented after storing first term), leading to undefined behavior.]
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
    while(scanf("%d%d",&a0,&x0)!=EOF) // @@ [This loop reads until EOF, but the problem states that each polynomial ends with a newline. If the second polynomial ends with a newline (not EOF), this may either miss the last term or attempt to read beyond, especially since the previous read already consumed part of the second polynomial. Also, scanf returns number of successfully matched items, not EOF directly; correct check is != 2.]
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
    for(k=h-1;k>=0;k--) // @@ [Because cmp sorts in ascending order, printing from h-1 down to 0 gives descending exponents, which matches the requirement. However, this relies on the flawed cmp and may not work correctly if sorting is unstable or if zero-coefficient terms are present (which should be omitted). Also, if any combined coefficient becomes zero, it should not be printed, but the code prints all terms regardless.]
    {
        printf("%d %d ",term3[k].a,term3[k].x);
    }
    return 0;
}